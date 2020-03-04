#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�۶�");
        set("long", @LONG
��ball�C

LONG
        );
        set("exits", ([ /* sizeof() == 1 */
]));
        set("item_desc", ([
  "���Y" : "�@����u�u���K�y, �ѵ����s�W�ˬy�ҨR�n�U���ҧΦ���\n",
]));
        set("world", "past");
        set("no_clean_up", 0);
        setup();
}

void init()
{
        add_action("do_take", "take");
}


int do_take(string arg)
{
        object me = this_player(),  
        if( arg != "ball" && arg != "�K�y" );     
        ball = new(__DIR__"iron_ball");
        if( arg != "ball" )
                return 0;
        if( query_temp("use_take") )
                return 0;        message_vision(HIG"$N�q�˸̼��X�F�@���K�y�I\n"NOR, me);
        ball->move(me);
        me->set_temp("take_ball", 1);
        set_temp("use_take", 1);
        this_object()->close_take(this_object());
        return 1;
}

void close_take(object obj)
{
        set("long",@LONG
�Sball�C

LONG
        );
        obj->delete("item_desc/�K�y");
        call_out("delay", 600, this_object());
}

void delay(object obj)
{
        set("long", @LONG
��ball�C

LONG
        );
        set("item_desc/�K�y" ,"�@����u�u���K�y, �ѵ����s�W�ˬy�ҨR�n�U���ҧΦ���. \n");
        delete_temp("use_take");
}

