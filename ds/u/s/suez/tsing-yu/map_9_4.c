// Room: /u/s/suez/tsing-yu/map_9_4.c

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
  "west" : __DIR__"map_9_3",
  "northeast" : __DIR__"map_8_5",
  "south" : __DIR__"map_10_4",
]));

	setup();
	replace_program(ROOM);
}
