// 奧凡迪斯

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"牧師工會內室"NOR);
	set("long", @LONG
這裡是高級牧師練習技能的房間，有位牧師導師在這教導學生牧師技
能。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
	    "west" : __DIR__"room095",
            ]));

	set("no_clean_up", 0);

	set("light", 1);

	setup();
	replace_program(ROOM);
}

