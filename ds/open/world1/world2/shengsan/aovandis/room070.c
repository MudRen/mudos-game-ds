// 奧凡迪斯

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"第二商街"NOR);
	set("long", @LONG
這裡是奧凡迪斯的第二商街，這裡是全城中最熱鬧的地方之一，在這
逛逛你一定會有很多收穫的。往東是麵包店。
LONG
	);

	set("exits", ([ /* sizeof() == 3 */
            "east" : __DIR__"room081",
	    "west" : __DIR__"room072",
	    "north": __DIR__"room069",
            ]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}