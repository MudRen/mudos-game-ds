#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","無砂鎮");
set("long",@LONG
這裡往北走會通往海政司, 所謂海政司其實也就是海關, 
不過這裡的海政司是在一年前才成立的, 之前是由林繁榮招募
義民來管理無砂鎮的一切交易.
LONG
    );
 set("exits",([ "north":__DIR__"seacoun6",
		"south":__DIR__"seacoun4",
]));
 set("objects", ([__DIR__"npc/seaguard" : 2,
		  __DIR__"npc/thief" : 1,
    ]));

 set("no_clean_up",0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);
}             
