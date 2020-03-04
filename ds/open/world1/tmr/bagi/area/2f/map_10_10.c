// Room: /open/world1/tmr/bagi/area/2f/map_10_10.c

inherit ROOM;

void create()
{
	set("short", "�H��}�G�h");
	set("long", @LONG

LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"map_11_10",
  "east" : __DIR__"map_10_11",
  "northwest" : __DIR__"map_9_9",
]));
	set("map_long", 1);
	set("current_light", 1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
