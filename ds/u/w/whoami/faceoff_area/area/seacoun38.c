#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","小巷子");
set("long",@LONG
這是一條在村長家旁邊的小巷子, 雖然並不大, 但卻可以看
到一些市井無賴在其中打混. 算是這個港都中較不為人知的一面
吧?
LONG
    );
 set("exits",([ "south":__DIR__"seacoun37",
]));
 set("objects", ([__DIR__"npc/thief" : 1,
	           __DIR__"npc/vagabond" : 1,
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();
}            