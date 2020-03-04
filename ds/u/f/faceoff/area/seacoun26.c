#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","市集");
set("long",@LONG
你一跨過市集大門, 立刻被四周的人潮嚇了一跳, 原來這裡
所交易的是民生物品, 因此有許多的無砂鎮民在這挑購日常用品
, 也難怪會如此熱鬧了.
LONG
    );
 set("exits",([ "north":__DIR__"seacoun25",
		"east":__DIR__"seacoun27",
]));
 set("objects", ([__DIR__"npc/salesman" : 2,
		  __DIR__"npc/woman" : 2,
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);
}            