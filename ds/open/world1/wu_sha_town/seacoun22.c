#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","市集");
set("long",@LONG
這裡就是無砂鎮民買賣民生用品的地方了, 你發現四處都
是叫賣聲, 好不熱鬧 ! 
LONG
    );
set("exits",([ "north":__DIR__"seacoun21",
             "west":__DIR__"seacoun25",
		"east":__DIR__"seacoun23",
]));
 set("objects", ([__DIR__"../npc/salesman" : 2,
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);
}            
