// Room: /u/s/suez/tsing-yu/map_5_4.c

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
  "north" : __DIR__"map_4_4",
  "southeast" : __DIR__"map_6_5",
  "west" : __DIR__"map_5_3",
]));

	setup();
	replace_program(ROOM);
}
