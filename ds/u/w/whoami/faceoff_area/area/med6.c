#include <ansi.h>
#include <room.h>
inherit ROOM;
inherit DOOR;
void create()
{
 set("short","小徑");

 set("long",@LONG
這是一條通往溫室及蓮池的小路, 往東走就是溫室, 而往西
走則會通往蓮池.
LONG
    );
 set("exits",([ "east":__DIR__"med7",
		"west":__DIR__"med5",
    ]));
create_door("east","竹門","west",DOOR_CLOSED);
 set("no_clean_up",0);
 set("outdoors","land");
 setup();
}
