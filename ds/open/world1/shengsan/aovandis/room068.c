// 奧凡迪斯

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"第二商街"NOR);
	set("long", @LONG
這裡是奧凡迪斯的第二商街，這裡是全城中最熱鬧的地方之一，在這
逛逛你一定會有很多收穫的。往東是旅社，往西是酒店。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"room079",
	    "west" : __DIR__"room120",
	    "south": __DIR__"room069",
	    "north": __DIR__"room067",
            ]));

	set("no_clean_up", 0);

	set("light", 1);

	setup();
	replace_program(ROOM);
}