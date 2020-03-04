// 奧凡迪斯

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"走道"NOR);
	set("long", @LONG
你站在一條乾淨的走道上。
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
            "east" : __DIR__"room050",
	    "west" : __DIR__"room048",
            ]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}