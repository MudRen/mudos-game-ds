// 奧凡迪斯

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"學術走道"NOR);
	set("long", @LONG
你站在一條有學術氣息的走道上。往上走你可以到達美達崙學院的入
口。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
            "east" : __DIR__"room053",
            ]));

	set("no_clean_up", 0);

	set("light", 1);

	setup();
	replace_program(ROOM);
}