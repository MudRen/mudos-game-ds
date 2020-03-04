#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"小路"NOR);
set("long",@LONG
這是一條從天池通到十萬大山和東北澤林等東北地區的
小路, 說重要性其實有不會有多重要, 但平常時後來來往往
的人潮也不少就是了.
LONG
    );
 set("exits",([ "southwest":"/open/world1/acme/area/pool.c",
		"north":__DIR__"road2",
]));
 set("objects", ([__DIR__"npc/road_vendor" : 1,
    ]));

 set("no_clean_up",0);
 set("light",1);
 setup();
 replace_program(ROOM);
}             
