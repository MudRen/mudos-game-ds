// 奧凡迪斯

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"巫師工會內室"NOR);
	set("long", @LONG
這裡是高級巫師練習技能的房間，有位巫師導師在這教導學生可怕的
巫師技能。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
	    "south": __DIR__"room085",
            ]));

	set("no_clean_up", 0);

	set("light", 1);

	setup();
	replace_program(ROOM);
}

