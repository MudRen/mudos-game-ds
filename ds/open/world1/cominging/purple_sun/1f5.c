// �����s�Ĥ@�h
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�����s");
        set("long", @LONG
�A�B��@�B�B�����W�F�s�A���b�s���W�A�|�P�������S���������
�A�O�Hı�o�L��A�A�����Ǥ@��O�s���A�@��O�˪L�A�n�O�@���p�߶^
�F�U�h�A�i�N�Ϥ��F�F�I
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "northeast" : __DIR__"1f4.c",
  "down" : __DIR__"psin7.c",
]));
        set("world", "past");
        set("no_clean_up", 0);
        set("outdoors","forest");
        setup();
}

int valid_leave(object me, string dir)
{
        if(!userp(me) && !me->is_ghost() ) return 0;
        return ::valid_leave(me, dir);
}

void fall_stone()
{
//        object b_stone = new(__DIR__"npc/obj/b_stone.c");
//        if( !objectp(b_stone) ) CHANNEL_D->do_channel(this_object(), "sys", "ERROR: �䤣�� stone .");
//        b_stone->move(this_object());
        return;
}


/*
void clean_stone()
{
        object b_stone = present("stack-road", this_object());
        destruct(b_stone);
}

void init()
{
        add_action("do_jump", "jump");
}

int do_jump(string arg)
{
    object me = this_player();

    if( arg != "down" ) return 0;
    if( !objectp(present("stack-road", this_object())) )
        return 0;

    message_vision("�u��$N���𩹤s�U���F�U�h... \n", me);
    me->move(__DIR__"psin_forest1.c");
    me->receive_damage("hp",30, me);
    me->receive_damage("ap",30, me);
    me->start_busy(3);
    message_vision("�u��$N�s�W���U�ӡA�~���G�z����... \n", me);
    return 1;
}

*/
