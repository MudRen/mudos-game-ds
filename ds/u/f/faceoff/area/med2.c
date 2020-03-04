#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIC"蓮池"NOR);

 set("long",@LONG
這裡已經是天梟的藥園了, 園中總共分為四個不同的部份, 
分別栽培不同的植物, 你放眼望去, 藥園有如一個小小的花園
, 煞是美觀 ! 
LONG
    );
 set("exits",([ "north":__DIR__"med3",
		"west":__DIR__"med1",
		"east":__DIR__"med5",
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);                      
}