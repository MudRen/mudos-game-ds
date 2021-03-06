// 奧凡迪斯
// LV 1~50
#include <room.h>  //要加門要這一行
#include <ansi.h>
inherit ROOM;
inherit DOOR;

void create()
{
	set("short", HIC"迪斯大道"NOR);
	set("long", @LONG
你在奧凡迪斯的迪斯大道上，這條大道是位於城裡的東半邊，往東直
走就是東城門了，在南邊有一間珠寶店。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"room013",
	    "west" : __DIR__"room011",
	    "south": __DIR__"room078",
	    "north": __DIR__"room087",
            ]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);
 	create_door("north","鐵門","south",DOOR_LOCKED,"ironkey");
	setup();
}
