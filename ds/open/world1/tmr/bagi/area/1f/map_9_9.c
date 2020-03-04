// Room: /open/world1/tmr/bagi/area/1f/map_9_9.c

inherit ROOM;

void create()
{
	set("short", "�H��}�@�h");
	set("long", @LONG

LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "southwest" : __DIR__"map_10_8",
  "northeast" : __DIR__"map_8_10",
  "northwest" : __DIR__"map_8_8",
]));
	set("map_long", 1);
	set("current_light", 1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
