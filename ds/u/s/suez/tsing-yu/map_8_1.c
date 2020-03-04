// Room: /u/s/suez/tsing-yu/map_8_1.c

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
  "northwest" : __DIR__"map_7_0",
  "northeast" : __DIR__"map_7_2",
]));

	setup();
	replace_program(ROOM);
}
