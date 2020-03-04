#include <ansi.h>

inherit F_CLEAN_UP;


string table = 
        "��������������������������������������������������������\n"
        "��          �x��  �Ţx�԰����N�x �n  �� �x �g  ��  �� ��\n"
        "��������������������������������������������������������\n"
        "�� �H������ �x%6d�x%8d�x%8d�x%12d��\n"
        "��������������������������������������������������������\n"
        "�� �O�q(STR)�x%6d�x%8d�x%8d�x%12d��\n"
        "��������������������������������������������������������\n"
        "�� ���(CON)�x%6d�x%8d�x%8d�x%12d��\n"
        "��������������������������������������������������������\n"
        "�� ���z(INT)�x%6d�x%8d�x%8d�x%12d��\n"
        "��������������������������������������������������������\n"
        "�� �ӱ�(DEX)�x%6d�x%8d�x%8d�x%12d��\n"
        "��������������������������������������������������������\n"
        "�� �i���I�� �x      �x"HIY"%8d"NOR"�x"HIY"%8d"NOR"�x"HIY"%12d"NOR"��\n"
        "��������������������������������������������������������\n\n";

int main(object me, string arg)
{
    object ob;
    mapping my;
    string str="";
    seteuid(getuid(me));

    if(!arg)
        ob = me;
    else if (wizardp(me)) {
        ob = present(arg, environment(me));
        if (!ob) ob = find_player(arg);
        if (!ob) ob = find_living(arg);
        if (!ob) return notify_fail("�A�n��ݽ֪����Ū��A�S\n");
    } else
        return notify_fail("�u���Ův���ݧO�H�����Ū��A�C\n");

    my = ob->query_entire_dbase();

    if( (int)my["level"] > 50 ) {
        str+=sprintf(table, 
                     my["level"]+1,
                     GUILDMASTER->advance_level_art_cost(my["level"]),
                     GUILDMASTER->advance_level_popu_cost(my["level"]),
                     GUILDMASTER->exp_count(my["level"],my["level"],14),
                     my["str"]+1, 
                     GUILDMASTER->advance_attr_art_cost(my["level"], my["str"]),
                     GUILDMASTER->advance_attr_popu_cost(my["level"], my["str"]),
                         GUILDMASTER->exp_count(my["level"],my["str"],7),
                     my["con"]+1,
                     GUILDMASTER->advance_attr_art_cost(my["level"], my["con"]),
                     GUILDMASTER->advance_attr_popu_cost(my["level"], my["con"]),
                         GUILDMASTER->exp_count(my["level"],my["con"],7),
                     my["int"]+1, 
                     GUILDMASTER->advance_attr_art_cost(my["level"], my["int"]),
                     GUILDMASTER->advance_attr_popu_cost(my["level"], my["int"]),
                         GUILDMASTER->exp_count(my["level"],my["int"],7),
                     my["dex"]+1, 
                     GUILDMASTER->advance_attr_art_cost(my["level"], my["dex"]),
                     GUILDMASTER->advance_attr_popu_cost(my["level"], my["dex"]),
                         GUILDMASTER->exp_count(my["level"],my["dex"],7),
                                        my["war_art"],
                                        my["popularity"], 
                                        my["exp"],
                       );

    } else if( (int)my["level"] >= 25 ) {
        str+=sprintf(table, 
                     my["level"]+1,
                     0, ((int)my["level"]-20)*((int)my["level"]-20),
                     GUILDMASTER->exp_count(my["level"],my["level"],14),
                     my["str"]+1, 
                     0, 3,
                     GUILDMASTER->exp_count(my["level"],my["str"],7),
                     my["con"]+1,
                     0, 3,
                         GUILDMASTER->exp_count(my["level"],my["con"],7),
                     my["int"]+1, 
                     0, 3,
                         GUILDMASTER->exp_count(my["level"],my["int"],7),
                     my["dex"]+1, 
                     0, 3,
                         GUILDMASTER->exp_count(my["level"],my["dex"],7),
                                        my["war_art"] ,
                                        my["popularity"], 
                                        my["exp"],
                    );
    }
        else {
                str+=sprintf(table, 
                             my["level"]+1,
                             0,
                                                0,
                             GUILDMASTER->exp_count(my["level"],my["level"],14),
                             my["str"]+1, 
                             0,
                                 0,
                                 GUILDMASTER->exp_count(my["level"],my["str"],7),
                             my["con"]+1,
                             0,
                                 0,
                                 GUILDMASTER->exp_count(my["level"],my["con"],7),
                             my["int"]+1, 
                             0,
                                 0,
                                 GUILDMASTER->exp_count(my["level"],my["int"],7),
                             my["dex"]+1, 
                             0,
                                 0,
                                 GUILDMASTER->exp_count(my["level"],my["dex"],7),
                                                my["war_art"] ,
                                                my["popularity"], 
                                                my["exp"],
                            );
    }
        write(str);
    return 1;
}

int help(object me)
{
    write(@HELP
���O�榡 : level
           level <��H�W��> (�Ův�M��)

        �o�ӫ��O�i�H��ܧA(�p)�Ϋ��w��H(�t�Ǫ�)�ɯũһݭn���g���I�ơC

HELP
         );
    return 1;
}


