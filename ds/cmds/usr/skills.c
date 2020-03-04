// skills.c
// ���X��/¾�~/�M�~ �ޯ� -tmr 2007/11/18

#include <ansi2.h>

inherit F_CLEAN_UP;
int sort_skill(string sk1,string sk2);

 object ob;
int main(object me, string arg)
{
       mapping skl, lrn, map;
       string *sname, *mapped;
       string basic, pro, know; // ��/¾�~/�M�~
                string r;
       int i;

        seteuid(getuid());

        if(!arg)
                ob = me;
        else{
                ob = present(arg, environment(me));
                if (!ob) ob = find_player(arg);
                if (!ob) ob = find_living(arg);
                if (!ob) return notify_fail("�A�n��ݽ֪��ޯ�S\n");
        }

        if( ob!=me      && !wizardp(me)         && !ob->is_apprentice_of(me)
        && !me->is_apprentice_of(ob) )
                return notify_fail("�u���Ův�Φ��v�{���Y���H���ݥL�H���ޯ�C\n");

        skl = ob->query_skills();
        if(!sizeof(skl)) {
                write( (ob==me ? "�A" : ob->name()) + "�ثe�èS���Ƿ|����ޯ�C\n");
                return 1;
        }

                pro     = "�x"+BBLU HIW "  ¾ �~ �� ��                              ����    ���m�� / �ɯŻݭn    "+NOR"�x\n"NOR;
                basic   = "�x"+BBLU HIW "  �� �� �� ��                              ����    ���m�� / �ɯŻݭn    "+NOR"�x\n"NOR;
                know    = "�x"+BBLU HIW "  �M �~ �� ��                              ����    ���m�� / �ɯŻݭn    "+NOR"�x\n"NOR;
        
                pro +=   "����������������������������������������������������������������������������\n";
                basic += "����������������������������������������������������������������������������\n";
                know +=  "����������������������������������������������������������������������������\n";
        
            sname = sort_array( keys(skl),(: sort_skill:));
        map = ob->query_skill_map();
        if( mapp(map) )
                        mapped = values(map);
        if( !mapped )
                        mapped = ({});

        lrn = ob->query_learned();
        if( !mapp(lrn) ) 
                        lrn = ([]);

        for(i=0; i<sizeof(skl); i++)
        {
                        r =  sprintf("�x%s%s%-44s  " NOR "  %3d(%3d)   %5d / %-6d      �x\n",
                        (lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1)*2 ) ? HIM : "",
                        (member_array(sname[i], mapped)==-1? NOR"  ": HIY"��"),
                        to_chinese(sname[i]) + " (" + sname[i] + ")"NOR,
                        ob->query_skill(sname[i],2), ob->query_skill(sname[i],1),
                        (int)lrn[sname[i]],
                        (skl[sname[i]]+ 1) * (skl[sname[i]]+ 1) * 2,
                        );

                                if( ("/daemon/skill/" + sname[i]+".c")->type() == "knowledge")  {
                         know +=r;
                                } else if( ("/daemon/skill/" + sname[i]+".c")->type() == "basic")  {
                         basic +=r;
                                } else {
                         pro +=r;
                }
        }
        pro = "�z�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�{\n"
                + pro
                + "����������������������������������������������������������������������������\n"
                + basic
                + "����������������������������������������������������������������������������\n"
                + know
                + "�|�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�}\n";

        write(pro);
        return 1;
}

int help(object me)
{
        write(@HELP
���O�榡 : skills [<�Y�H>]

�o�ӫ��O�i�H���A(�p)�d�ߩҾǹL���ޯ�C
�A�]�i�H���w�@�өM�A���v�{���Y����H�M�� skills �i�H�d����誺�ޯબ�p�C

�Ův�i�H�d�ߥ���H�� NPC ���ޯબ�p�C

HELP
    );
    return 1;
}

int sort_skill(string sk1,string sk2)
{
        return ob->query_skill(sk2,2)-ob->query_skill(sk1,2);
}


