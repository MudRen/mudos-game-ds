// 奧凡迪斯

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"旅館二樓"NOR);
	set("long", @LONG
陽光從窗戶透射進來，照亮了整個房間。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
	    "south": __DIR__"room104",
            ]));

	set("no_clean_up", 0);

	set("light", 1);

	setup();
	replace_program(ROOM);
}

