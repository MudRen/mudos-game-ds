// Room: /u/s/suez/tsing-yu/map_4_9.c

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
	set("exits", ([ /* sizeof() == 3 */
  "southwest" : __DIR__"map_5_8",
  "east" : __DIR__"map_4_10",
]));

	setup();
	replace_program(ROOM);
}
