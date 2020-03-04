// 紫陽山第一層
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "紫陽山");
        set("long", @LONG
你步行一步步的走上了山，走在山路上，四周的景物沒有什麼改變
，令人覺得無聊，你的身旁一邊是山壁，一邊是森林，要是一不小心跌
了下去，可就救不了了！
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
//        if( !objectp(b_stone) ) CHANNEL_D->do_channel(this_object(), "sys", "ERROR: 找不到 stone .");
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

    message_vision("只見$N提氣往山下跳了下去... \n", me);
    me->move(__DIR__"psin_forest1.c");
    me->receive_damage("hp",30, me);
    me->receive_damage("ap",30, me);
    me->start_busy(3);
    message_vision("只見$N山上跳下來，途中慘嚎不絕... \n", me);
    return 1;
}

*/
