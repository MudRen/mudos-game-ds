#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","海政司大門");
 set("long",@LONG
這裡是海政司的大門了, 青銅的門體加上兩旁的白石獅, 
果然有一股不凡的威嚴, 不過聽說近來海政司惹了很多怨言, 
詳細的情形就不得而知了.
LONG
    );
 set("exits",([ "enter":__DIR__"seacoun8",
		"south":__DIR__"seacoun6",
]));
 set("objects", ([__DIR__"npc/seaguard" : 2,
    ]));

 set("no_clean_up",0);
 set("outdoors","land");
 setup();
}

int valid_leave(object me, string dir)
{
	if( dir== "enter" && !userp(me) )
                return notify_fail("那裡只有玩家才能進去。\n");
        return ::valid_leave(me, dir);
}