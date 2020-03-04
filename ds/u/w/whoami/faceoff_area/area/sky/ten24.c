#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",CYN"龍井棧道"NOR);
 set("long",@LONG
古代的重要棧道 -- 龍井棧道就是指這裡了, 在古時, 
這是唯一一條通往泰源天國的道路, 這一路上, 龍井棧道橫
跨龍脊峰, 東北澤林, 橫天橋......等等天險, 這條道路實
在是古代工程的最佳典範.
LONG
    );
 set("exits",([  "northwest":__DIR__"ten25",
                 "south":__DIR__"ten23",
    ]));
 set("objects", ([__DIR__"npc/sky_guard" : 2,
    ]));
set("no_clean_up",0);
set("outdoors","land");
 setup();
}

int valid_leave(object me, string dir)
{
        if( dir== "northwest" && !userp(me) )
                return notify_fail("那裡只有玩家才能進去。\n");
        return ::valid_leave(me, dir);
}

