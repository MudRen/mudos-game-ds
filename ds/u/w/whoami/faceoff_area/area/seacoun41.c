#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","南無砂港");
set("long",@LONG
這裡是南邊的無砂港, 你可以看就有許多商人正往東邊移
動, 看來東邊就是南無砂港的泊口.
LONG
    );
 set("exits",([ "north":__DIR__"seacoun39",
	       "east":__DIR__"seacoun42",
]));
  set("no_clean_up",0);
 set("outdoors","land");
 setup();
}            





