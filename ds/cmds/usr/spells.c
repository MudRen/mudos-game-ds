// skills.c

#include <ansi2.h>

inherit F_CLEAN_UP;

object ob;
int sort_skill(string sk1,string sk2)
{
           return ob->query_spell(sk2,2)-ob->query_spell(sk1,2);
}

int main(object me, string arg)
{
        mapping skl, lrn, map;
        string *sname, *mapped,result;
          int i;

        seteuid(getuid());

        if(!arg)
                ob = me;
        else{
                ob = present(arg, environment(me));
//        if ( ob->query("SPSKILLS",1)  ) return ob->skills();           
                if (!ob) ob = find_player(arg);
                if (!ob) ob = find_living(arg);
                if (!ob) return notify_fail("你要察看誰的法術﹖\n");
        }

        if( ob!=me && !wizardp(me) && !ob->is_apprentice_of(me)
        && !me->is_apprentice_of(ob) )
                return notify_fail("只有巫師或有師徒關係的人能察看他人的法術。\n");

        skl = ob->query_spells();
        if(!sizeof(skl)) {
                write( (ob==me ? "你" : ob->name()) + "目前並沒有學會任何法術。\n");
                return 1;
        }
        result = 
        "┌─────────────────────────────────┐\n" +
        "│"+BBLU HIM+"  法 術 名 稱                        階段  施法經驗 / 升級經驗值  "+NOR"│\n" +
        "�澺������������������������������������������������������������������螏n";
         sname  = sort_array( keys(skl), (: sort_skill :) );
        
        map = ob->query_spell_map();
        if( mapp(map) ) mapped = values(map);
        if( !mapped ) mapped = ({});

        lrn = ob->query_learned_spell();
        if( !mapp(lrn) ) lrn = ([]);
        for(i=0; i<sizeof(skl); i++)
        {
                result += sprintf("│%s%s%-34s" NOR " %3d(%3d)  %4d / %-5d       │\n",
                        (lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIM : "",
                        (member_array(sname[i], mapped)==-1? "  ": "★"),
                        to_chinese(sname[i]) + " (" + sname[i] + ")",
                        ob->query_spell(sname[i],2), ob->query_spell(sname[i],1),
                        (int)lrn[sname[i]],
                        (skl[sname[i]]+ 1) * (skl[sname[i]] + 1) * 3 / 2,
                        );

        }
        result += "└─────────────────────────────────┘\n";
        me->start_more(result);
        return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : skills [<某人>]

這個指令可以讓你(妳)查詢所學過的法術。

你也可以指定一個和你有師徒關係的對象﹐用 spells 可以查知對方的法術狀況。

巫師可以查詢任何人或 NPC 的法術狀況。

HELP
    );
    return 1;
}


