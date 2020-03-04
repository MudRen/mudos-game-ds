// Room: /u/s/suez/tsing-yu/map_7_0.c

inherit ROOM;

void create()
{
	set("short", "��D");
	set("long", @LONG

LONG
	);
	set("no_clean_up", 0);
	set("world", "undefine");
	set("map_long", 1);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"map_6_0",
  "southeast" : __DIR__"map_8_1",
]));

	setup();
	replace_program(ROOM);
}
