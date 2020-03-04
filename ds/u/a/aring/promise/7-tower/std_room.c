#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", RED"�C����"NOR);
        set("long", @LONG
���b��e��A��ݨ��𳺵M�@�L��ҡA�����ѪŶ��h�A�L��
�O�b�V�ѩ������žԡC�b�ǲ@�L�ͪ��Ať���b�����B���H�����D�A
����̦�ۤ@�ǧ��]���ǡAť���U�U�k�O���j�A���e�����C
LONG);
        set("exits", ([ /* sizeof() == 3 */ 
   "back" : "/open/world1/tmr/area/hotel",
    ]));
        
        set("no_fight",1);
        set("no_cast",1);
        set("no_exert", 1);
        set("no_steal", 1);
        set("world", "past");
        set("no_clean_up", 0);
        set("light",1);
        setup();
}

void init()
{
        add_action("do_enter","enter");
        
}

int do_enter(string arg)

{
        object me = this_player();
        string gender;
        gender=me->query("gender");

        if( arg != "�C����" )
                return 0;
        if ( gender=="�k��" ) gender="�֫L";
        if ( gender=="�k��" ) gender="�L�k";
        if ( me->query("age") > 50 ) gender="�e��";
        if ( me->query("level") < 40 )  return notify_fail(HIW"�𤺶ǥX�@�n�j�q�GHIB" +gender+ "HIW�A�٥����Z�A�^�h�׽m�X�~�b�����a�C\n"NOR);
message("world:world1:vision",
NOR+GRN"\t�ǻ����i�̡y"HIW+me->query("name")+NOR+GRN"�z�T�M�i�J�C����A����}�l�C���𥲵M���_�@�}��{�I�I\n\n"NOR,users());
        me->move(__DIR__"1f_1");
        me->start_busy(1);
        
        return 1;
}

