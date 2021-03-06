// 奧凡迪斯

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"學術走道"NOR);
	set("long", @LONG
你站在一條有學術氣息的走道上。北方是小神殿，往南找找可找到法
師工會，往西直走可以到達美達崙學院。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"room051",
	    "west" : __DIR__"room053",
	    "south": __DIR__"room082",
	    "north": __DIR__"room083",
            ]));

	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/guard" : 2,
	]));

	set("no_clean_up", 0);

	set("light", 1);

	setup();
	replace_program(ROOM);
}