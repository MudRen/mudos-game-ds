#include <ansi.h>
inherit NPC;
inherit BANKMAN;
inherit SSERVER;
void create()
{
        set_name("���d��",({ "purple thousand red","red"}));
        set("long", "�@�Ө�����R�A�����]���k�ʡA�o�O���������ƫ��D�A\n�]�P�ɬO�o���������D�H�C\n\n"
     "�s�ڽХ�[deposit]\n���ڽХ�[withdraw]\n�d�ݾl�B�Х�[balance]\n\n"
        );
        set("level",1);
        set("nickname",HIM"�m�������n"HIC"�ѪF"NOR);
        set("title",HIC"�������ƫ��D"NOR);
        set("gender", "�k��");
        set("race", "�H��");
        set("no_kill",1);
        set("age", 40);
 setup();
}
void init()
{
 add_action("do_deposit","deposit");
 add_action("do_withdraw","withdraw");
}


