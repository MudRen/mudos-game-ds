// Room: /future/area/stihy.c

inherit ROOM;

void create()
{
	set("short", "���K�[�u�t");
	set("long", @LONG

LONG
	);
	set("world", "future");
	set("exits", ([ /* sizeof() == 1 */
	  "north" : __DIR__"digging_road2",
	]));
	set("no_clean_up", 0);
	set("light",1);

	setup();
	replace_program(ROOM);
}
