// 奧凡迪斯

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"神秘的大門"NOR);
	set("long", @LONG
一切只有「神秘」可以說明，也許你需要更多的線索。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
	    "south": __DIR__"room045",
            ]));

	set("no_clean_up", 0);

	set("light", 1);

	setup();
	replace_program(ROOM);
}