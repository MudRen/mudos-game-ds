// 奧凡迪斯

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"旅館二樓"NOR);
	set("long", @LONG
高級的房間就是這裡了，你看到這裡的裝潢及氣氛就覺得疲勞度減輕
了一半。
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
	    "north": __DIR__"room105",
            "down" : __DIR__"room079",
            ]));

	set("no_clean_up", 0);

	set("light", 1);

	setup();
	replace_program(ROOM);
}

