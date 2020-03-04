#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","修船廠");
set("long",@LONG
正所謂有收穫必有付出, 當一艘船出洋歸來時, 船體受到的
傷害可是相當大的, 所以才會有修船廠的出現, 無砂修船廠的規
模雖然不大, 但效率還算不錯!
LONG
    );
 set("exits",([ "north":__DIR__"seacoun30",
		"south":__DIR__"seacoun34",
		"east":__DIR__"seacoun36",
]));
 set("objects", ([__DIR__"../npc/worker2" : 1,
		  __DIR__"../npc/worker3" : 2,
    ]));
 set("no_clean_up",0);
 set("light",1);
 setup();
 replace_program(ROOM);
}            