// 奧凡迪斯
// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"迪斯大道"NOR);
	set("long", @LONG
你在奧凡迪斯的迪斯大道上，這條大道是位於城裡的東半邊，往東直
走就是東城門了。然而，你看到南方好熱鬧阿，好像是商店街吧。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"room012",
	    "west" : __DIR__"room010",
	    "south": __DIR__"room067",
	    "north": __DIR__"room091",
            ]));

	set("light", 1);

	setup();
	replace_program(ROOM);
}