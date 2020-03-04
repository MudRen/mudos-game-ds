#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","無砂鎮");
set("long",@LONG
這裡是無砂鎮的舊市街, 你看到你的東方店面掛著老記當
鋪的招牌, 而西方的店面則是賣漁網的, 往北則會到海政司, 
老記當鋪是在無砂鎮開墾以來第一家當鋪, 也算很老囉....
LONG
    );
 set("exits",([ "north":__DIR__"seacoun7",
		"south":__DIR__"seacoun5",
		"west":__DIR__"seacoun18",
		"east":__DIR__"seacoun19",
]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();
}

int valid_leave(object me, string dir)
{
       if( dir=="south" && !userp(me) )
                return notify_fail("那裡只有玩家才能進去。\n");
        return ::valid_leave(me, dir);
}