// Room: /u/s/suez/tsing-yu/map_10_9.c

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
	set("exits", ([ /* sizeof() == 6 */
  "north" : __DIR__"map_9_9",
  "northwest" : __DIR__"map_9_8",
  "southeast" : __DIR__"map_11_10",
  "south" : __DIR__"map_11_9",
]));

	setup();
	replace_program(ROOM);
}
