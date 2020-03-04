// Room: /open/world1/tmr/bagi/area/2f/map_9_5.c

inherit ROOM;

void create()
{
	set("short", "�H��}�G�h");
	set("long", @LONG

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"map_9_6",
  "northwest" : __DIR__"map_8_4",
]));
	set("map_long", 1);
	set("current_light", 1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
