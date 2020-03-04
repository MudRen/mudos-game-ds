
inherit ROOM;

void create()
{
	set("short", "巫毒教廚房");
	set("long", @LONG
一陣濃濃的香味快速的向你撲鼻而來，這裡是巫毒教的廚房，有很多
的廚具及美味可口的食物就在你眼前。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
            "south" : __DIR__"room13",
	    "north" : __DIR__"room15",
            ]));

	set("no_clean_up", 0);

	set("light", "1");

	setup();
	replace_program(ROOM);
}
