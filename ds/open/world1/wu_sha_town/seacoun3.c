#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","青石道");
set("long",@LONG
這裡仍然是一條青石道, 從這裡往東不遠處就可以到無砂
鎮了.
LONG
    );
 set("exits",([ "west":__DIR__"seacoun2",
		"east":__DIR__"seacoun4",
]));
 set("objects", ([__DIR__"../npc/salesman" : 2,
    ]));

 set("no_clean_up",0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);
}             
