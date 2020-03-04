#include <ansi.h>
#include <room.h>
inherit ROOM;
inherit DOOR;
void create()
{
 set("short",HIR"溫室"NOR);

 set("long",@LONG
這裡是天梟冶藥派培植嗜熱植物的溫室, 你發現裡面的氣
溫大約比外面高上二, 三度, 並不會說非常的炎熱, 你可以在
這找到你要的藥材.
LONG
    );
 set("exits",([ "north":__DIR__"med8",
		"west":__DIR__"med6",
		"east":__DIR__"med10",
    ]));
create_door("west","竹門","east",DOOR_CLOSED);
 set("no_clean_up",0);
 set("outdoors","land");
 setup();
}
