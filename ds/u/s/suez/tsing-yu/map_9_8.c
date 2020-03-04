// Room: /u/s/suez/tsing-yu/map_9_8.c

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
  "northwest" : __DIR__"map_8_7",
  "southeast" : __DIR__"map_10_9",
  "west" : __DIR__"map_9_7",
  "south" : __DIR__"map_10_8",
]));

	setup();
	replace_program(ROOM);
}
