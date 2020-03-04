// Room: /u/s/suez/tsing-yu/map_5_8.c

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
  "southwest" : __DIR__"map_6_7",
  "northeast" : __DIR__"map_4_9",
]));

	setup();
	replace_program(ROOM);
}
