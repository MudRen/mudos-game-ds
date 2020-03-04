#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","小徑");

 set("long",@LONG
這是一條小小的小徑, 往北走會回到天梟藥園的入口, 而往
東走就會到黑暗的晦林了.
LONG
    );
 set("exits",([ "north":__DIR__"med1",
		"east":__DIR__"med21",
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);                      
}