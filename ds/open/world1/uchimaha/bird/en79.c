#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
set("short","�ۥ� ");
set("long", @LONG
�A�Ө�F�a�U�ۥ�, �o�̫D�`����, �]�����@�ӥ��j
�����l���b�o�X���������V, �b�o�̦��@�ӿW�u�ѤH���b
���s�@��C, �L��A����Ӧ��G�ܰ���, �b�o�̤]���@��
�۹�, �i�O�n����A��ݨ쪺���Ӥ@��....

LONG
        );
        set("objects",([__DIR__"npc/ooldman" : 1,
               ]));
        set("item_desc",([
        "�۹�":"�@�ӯQ���ܶª��۹��A�۹����Y�n���i�H��ʪ��ˤl(roll)�C\n",
         ]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
}
void init()
{
        add_action("do_roll","roll");
}

int do_roll(string arg)
{
        object me;
        me=this_player();
        if (arg != "�۹����Y") return 0;
        else {
               message_vision("�u��$N��۹����Y�@��A�X�{�F�@�ӳq���W�誺��l�C\n\n",me);
               set("exits",([
               "up" : __DIR__"en78",
               ]) );
           return 1;
        }
}          


