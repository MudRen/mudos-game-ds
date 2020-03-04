#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","道路");
set("long",@LONG
這裡是通往無砂舊市區的道路, 由於無砂鎮的三年前的
轉型, 舊市區早已不敷使用, 因此北至大岬灣之間皆拓墾為
新市區, 而往南就是無砂的舊市區了.
LONG
    );
 set("exits",([ "north":__DIR__"seacoun4",
		"south":__DIR__"seacoun21",
]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);
}            