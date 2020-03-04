// Room: /u/s/suez/tsing-yu/map_11_10.c

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
	set("exits", ([ /* sizeof() == 5 */
  "north" : __DIR__"map_10_10",
  "east" : __DIR__"map_11_11",
  "northwest" : __DIR__"map_10_9",
  "west" : __DIR__"map_11_9",
  "south" : __DIR__"map_12_10",
]));

	setup();
	replace_program(ROOM);
}
