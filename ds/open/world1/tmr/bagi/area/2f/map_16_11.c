// Room: /open/world1/tmr/bagi/area/2f/map_16_11.c

inherit ROOM;

void create()
{
	set("short", "�H��}�G�h");
	set("long", @LONG

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"map_17_10",
  "northeast" : __DIR__"map_15_12",
]));
	set("map_long", 1);
	set("current_light", 1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
