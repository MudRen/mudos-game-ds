#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","市集");
set("long",@LONG
這裡是市集的東邊, 主要是在販賣一些海鮮, 這裡不只受到
當地居民的青睞, 連外國人也相當喜歡來這裡買海鮮祭祭五臟
廟呢! 
LONG
    );
 set("exits",([ "west":__DIR__"seacoun22",
		"south":__DIR__"seacoun24",
]));
 set("objects", ([__DIR__"../npc/fisher" : 1,
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);
}            