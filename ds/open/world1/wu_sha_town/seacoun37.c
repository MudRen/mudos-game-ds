#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","港道");
set("long",@LONG
這裡通到林繁榮到任後才大作整修的無砂主港口, 由於林
繁榮到任後大刀闊斧的改建, 如今無砂已是北至遼霖城, 西到
步靈城之間最大的港口了!
LONG
    );
 set("exits",([ "west":__DIR__"seacoun30",
	        "north":__DIR__"seacoun38",
	        "east":__DIR__"seacoun39",
]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);
}            