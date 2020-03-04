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
                if (!ob) return notify_fail("�A�n��ݽ֪��k�N�S\n");
        }

        if( ob!=me && !wizardp(me) && !ob->is_apprentice_of(me)
        && !me->is_apprentice_of(ob) )
                return notify_fail("�u���Ův�Φ��v�{���Y���H���ݥL�H���k�N�C\n");

        skl = ob->query_spells();
        if(!sizeof(skl)) {
                write( (ob==me ? "�A" : ob->name()) + "�ثe�èS���Ƿ|����k�N�C\n");
                return 1;
        }
        result = 
        "�z�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�{\n" +
        "�x"+BBLU HIM+"  �k �N �W ��                        ���q  �I�k�g�� / �ɯŸg���  "+NOR"�x\n" +
        "����������������������������������������������������������������������\n";
         sname  = sort_array( keys(skl), (: sort_skill :) );
        
        map = ob->query_spell_map();
        if( mapp(map) ) mapped = values(map);
        if( !mapped ) mapped = ({});

        lrn = ob->query_learned_spell();
        if( !mapp(lrn) ) lrn = ([]);
        for(i=0; i<sizeof(skl); i++)
        {
                result += sprintf("�x%s%s%-34s" NOR " %3d(%3d)  %4d / %-5d       �x\n",
                        (lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIM : "",
                        (member_array(sname[i], mapped)==-1? "  ": "��"),
                        to_chinese(sname[i]) + " (" + sname[i] + ")",
                        ob->query_spell(sname[i],2), ob->query_spell(sname[i],1),
                        (int)lrn[sname[i]],
                        (skl[sname[i]]+ 1) * (skl[sname[i]] + 1) * 3 / 2,
                        );

        }
        result += "�|�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�}\n";
        me->start_more(result);
        return 1;
}

int help(object me)
{
        write(@HELP
���O�榡 : skills [<�Y�H>]

�o�ӫ��O�i�H���A(�p)�d�ߩҾǹL���k�N�C

�A�]�i�H���w�@�өM�A���v�{���Y����H�M�� spells �i�H�d����誺�k�N���p�C

�Ův�i�H�d�ߥ���H�� NPC ���k�N���p�C

HELP
    );
    return 1;
}


