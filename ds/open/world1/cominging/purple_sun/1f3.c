// �����s�Ĥ@�h
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�����s");
        set("long", @LONG
���ۨ��ۡA�s���W��M�X�{�F�ʭZ�����j��A�_�Ǫ��O����]�S��
�󰪤j����F�A���ӥi�H�쨺�h���������A�~�򩹫e�����O�s���A�T��
�~�M�A���n�����ˤl�C
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"1f4.c",
  "northwest" : __DIR__"1f2.c",
]));
        set("item_desc", ([
  "�j��" : "�o�O�@�ʭZ�����j��A�ä����ܰ��j�A�W�����Ǫ��m���a��C\n",
]));
        set("world", "past");
        set("no_clean_up", 0);
        set("outdoors","forest");
        setup();
}

void init()
{
        add_action("do_climb","climb");
}

int do_climb(string arg)
{
        object me = this_player();
        if( arg != "�j��" && arg != "tree" ) return 0;
        if( me->can_move(__DIR__"tree.c") )
        {
                message_vision(WHT"$N�p���l�l�����W��D�D�D\n"NOR,me);
                me->move(__DIR__"tree.c");
		tell_room( environment(me) , me->name()+"�q��U���F�W�ӡA��A�����@�ΡC\n", ({ me }));
                me->start_busy(1);
                return 1;
        }
        else return notify_fail("�A�n���S��k�W�h��W�I\n");
}
