// Room: /open/world1/tmr/bagi/area/2f/map_16_9.c

inherit ROOM;

void create()
{
	set("short", "�H��}�G�h");
	set("long", @LONG

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"map_17_10",
  "northwest" : __DIR__"map_15_8",
]));
	set("map_long", 1);
	set("current_light", 1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
