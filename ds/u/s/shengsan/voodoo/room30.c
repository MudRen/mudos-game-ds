
inherit ROOM;

void create()
{
	set("short", "後花園");
	set("long", @LONG
這裡是巫毒教的後院的花園，你看到有許多花草樹木栽種在這裡，蝴
蝶、蜜蜂飛舞在其中，仔細一看，你才發現這些花草都是你平常沒見過的
，難道這些植物都有毒嗎？
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
            "east" : __DIR__"room31",
	    "west" : __DIR__"room21",
	    "north": __DIR__"room32",
            ]));

	set("objects", ([ /* sizeof() == 2 */
            __DIR__"mob/student" : 3,
	    __DIR__"mob/believer": 2,
            ]));

	set("no_clean_up", 0);

	set("light", "1");

	setup();
	replace_program(ROOM);
}
