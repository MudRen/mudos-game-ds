// Room: /u/s/suez/tsing-yu/map_7_2.c

inherit ROOM;

void create()
{
	set("short", "�J��");
	set("long", @LONG

LONG
	);
	set("no_clean_up", 0);
	set("world", "undefine");
	set("map_long", 1);
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"map_8_1",
  "east" : __DIR__"map_7_3",
]));

	setup();
	replace_program(ROOM);
}
