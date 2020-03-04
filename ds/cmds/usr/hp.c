// hp cmds

#include <ansi2.h>
 
inherit F_CLEAN_UP;
inherit SSERVER; 

string status_color(int current, int max);
string bg_color(int current, int max);
 
int main(object me, string arg)
{
        object ob,victim;
        mapping my;
        int max_tp,i;
        string str="";
        seteuid(getuid(me));
 
        if(!arg) ob = me;
        else
        {
                ob = present(arg, environment(me));
                if (!ob) ob = find_player(arg);
                if (!ob) ob = find_living(arg);
                if (!ob) return notify_fail("�A�n��ݽ֪����A�S\n");
                if(ob->query("creater")!=me && !wizardp(me) ) return notify_fail("�u���Ův���ݧO�H�����A�C\n");
        }
        my = ob->query_entire_dbase();
        
        if(ob->is_fighting() && victim=offensive_target(ob) )
        {
                i=50;
                str+=sprintf("\n    ");
                if(!victim) victim=offensive_target(ob);
                if(victim)
                {
                        str+=sprintf(bg_color(victim->query("hp"), victim->query("max_hp")));
                        while(i--)
                        {
                                if(i>=(50-50*victim->query("hp")/victim->query("max_hp"))) str+="_";
                                else str+=NOR"_";
                        }
                        str+=sprintf(NOR+HIW"    %s\n"NOR,victim->name());
                }
                i=50;
                str+=sprintf("\n    "NOR);
                str+=sprintf(bg_color(my["hp"], my["max_hp"]));
                while(i--)
                {
                        if(i>=(50-50*my["hp"]/my["max_hp"])) str+="_";
                        else str+=NOR"_";
                }
                str+=sprintf(NOR+HIY"    %s",my["name"]);
                str+=sprintf("\n\n"NOR);
        }
        max_tp=my["level"]*3+5;
        if(my["talk_point"] > max_tp) my["talk_point"]=max_tp;
        else if(my["talk_point"] < 0 ) my["talk_point"]=0;

        str+=sprintf(
                "\n  �� %s\n"
                " ����������������������������������������������������������������������\n"
                " ��\t�ͩR�I�ơR %s%5d"NOR" / %-5d\t�k�]��v�R "HIY"%-10d"NOR"        ��\n"
                " ��\t�]�k�I�ơR %s%5d"NOR" / %-5d\t�g �� �ȡR "HIW"%-10d"NOR"        ��\n"
                " ��\t���l�I�ơR %s%5d"NOR" / %-5d\t�n    ��R "HIW"%-10d"NOR"        ��\n"
                " ��\t�͸��I�ơR %s%5d"NOR" / %-5d\t�԰����N�R "HIW"%-10d"NOR"        ��\n"
                " ����������������������������������������������������������������������\n",
                ob->short(1),
                status_color(my["hp"], my["max_hp"]),my["hp"],my["max_hp"],
                my["wimpy"],
                status_color(my["mp"], my["max_mp"]),my["mp"],my["max_mp"],
                my["exp"],
                status_color(my["ap"], my["max_ap"]),my["ap"],my["max_ap"],
                my["popularity"],
                status_color(my["talk_point"], max_tp),my["talk_point"],max_tp,
                my["war_art"],
        );
        write(str);
        return 1;
}
                                                  
string bg_color(int current, int max)
{
        int percent;
 
        if( max>0 ) percent = current * 100 / max;
        else percent = 100;
        if( percent >= 60 ) return HBGRN"";
        if( percent >= 30 ) return HBYEL"";
        return HBRED"";
}
                                                  
string status_color(int current, int max)
{
        int percent;
 
        if( max>0 ) percent = current * 100 / max;
        else percent = 100;
        if( percent > 100 ) return HIC;
        if( percent >= 90 ) return HIG;
        if( percent >= 60 ) return HIY;
        if( percent >= 30 ) return YEL;
        if( percent >= 10 ) return HIR;
        return RED;
}
int help(object me)
{
        write(@HELP
���O�榡 : hp
           hp <��H�W��>                   (�Ův�M��)
 
�o�ӫ��O�i�H��ܧA(�p)�Ϋ��w��H(�t�Ǫ�)����, ��, ���ƭȡC

see also : score
HELP
    );
    return 1;
}

