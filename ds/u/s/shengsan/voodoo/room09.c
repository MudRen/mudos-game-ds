inherit ROOM;

void create()
{
	set("short", "青石階");
	set("long", @LONG
你正站在由青石所砌合而成的石階之上,有一座宏偉的牌仿就在你的
前方，你可以清楚地看到『巫毒教』三個大字橫批在其上，能有如此的門
面，不知裡頭是有何等的高人在主持教務。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
            "up"   : __DIR__"room10",
	    "down" : __DIR__"room08",
            ]));

	set("no_clean_up", 0);
	set("outdoors",1);

	setup();
	replace_program(ROOM);
}
