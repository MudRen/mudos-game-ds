// 奧凡迪斯

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"小神殿"NOR);
	set("long", @LONG
你發現一座小神殿在這裡，但是卻找不出任何可以進去的方法，也許
這裡是神尊進出世界的出入口吧。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
	    "south": __DIR__"room083",
            ]));

	set("no_clean_up", 0);

	set("light", 1);

	setup();
	replace_program(ROOM);
}

