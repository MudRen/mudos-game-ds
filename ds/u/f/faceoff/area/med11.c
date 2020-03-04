#include <ansi.h>
#include <room.h>
inherit ROOM;
inherit DOOR;
void create()
{
 set("short","小徑");

 set("long",@LONG
這是一條小小的路, 連接著溫室和南方的針林, 針林中大部
份都是種植嗜寒植物, 和北方的溫室大是不同, 你可以在那採到
你所要的藥材.
LONG
    );
 set("exits",([ "west":__DIR__"med10",
		"south":__DIR__"med12",
    ]));
create_door("west","竹門","east",DOOR_CLOSED);
 set("no_clean_up",0);
 set("outdoors","land");
 setup();
}
