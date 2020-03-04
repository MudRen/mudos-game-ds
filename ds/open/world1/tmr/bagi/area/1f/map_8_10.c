// Room: /open/world1/tmr/bagi/area/1f/map_8_10.c

inherit ROOM;

void create()
{
	set("short", "�H��}�@�h");
	set("long", @LONG

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"map_9_9",
  "northeast" : __DIR__"map_7_11",
]));
	set("map_long", 1);
	set("current_light", 1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
