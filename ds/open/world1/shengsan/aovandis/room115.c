// 奧凡迪斯

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"植物園"NOR);
	set("long", @LONG
各式各樣的植物全在你的眼底下了，你看到有許多可愛的小生物在其
中玩耍鬥樂。亮麗的陽光照射在油亮的綠色植物上，好不美麗啊。
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
	    "north": __DIR__"room113",
	    "west" : __DIR__"room114",
            ]));

	set("no_clean_up", 0);

	set("light", 1);

	setup();
	replace_program(ROOM);
}

