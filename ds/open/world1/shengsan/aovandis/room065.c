// 奧凡迪斯

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"空房間"NOR);
	set("long", @LONG
奇怪，這裡會有空屋？
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
	    "west" : __DIR__"room063",
	    "south": __DIR__"room066",
            ]));

	set("no_clean_up", 0);

	set("light", 1);

	setup();
	replace_program(ROOM);
}