// 奧凡迪斯

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"餐\廳內包廂"NOR);
	set("long", @LONG
這個餐廳規模相當的大，餐廳內的客人絡繹不絕。浪漫的氣氛充斥其
中，好讓人醉心。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
	    "north": __DIR__"room107",
            ]));

	set("no_clean_up", 0);

	set("light", 1);

	setup();
	replace_program(ROOM);
}

