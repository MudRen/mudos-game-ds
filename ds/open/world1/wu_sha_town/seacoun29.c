#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","道路");
set("long",@LONG
這裡往東就是無砂的港口區了, 無砂港算是一個相當完善
的港口, 一片交易繁榮的景像使你感到無砂鎮的活力!
LONG
    );
 set("exits",([ "east":__DIR__"seacoun30",
		"west":__DIR__"seacoun4",
]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);
}            