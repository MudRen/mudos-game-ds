// 奧凡迪斯

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"牧師工會"NOR);
	set("long", @LONG
這裡有很多的牧師常常在這集會。有很多的魔法藥水和魔杖在旁邊的
桌上和牆邊，的光線照亮了整個房間，讓人有種倍感溫馨的感覺。
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
            "east" : __DIR__"room101",
	    "west" : __DIR__"room090",
            ]));

	set("no_clean_up", 0);

	set("light", 1);

	setup();
	replace_program(ROOM);
}