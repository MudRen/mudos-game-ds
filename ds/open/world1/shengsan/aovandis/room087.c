// 奧凡迪斯

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"盜賊工會"NOR);
	set("long", @LONG
你走到了一間狹小的房間，這裡的裝飾琳瑯滿目，好像都不是這個地
區的東西。
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
            "east" : __DIR__"room100",
	    "south": __DIR__"room012",
            ]));

	set("no_clean_up", 0);

	set("light", 1);

	setup();
	replace_program(ROOM);
}