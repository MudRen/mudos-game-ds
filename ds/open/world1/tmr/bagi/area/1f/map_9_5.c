// Room: /open/world1/tmr/bagi/area/1f/map_9_5.c

inherit ROOM;

void create()
{
	set("short", "�H��}�@�h");
	set("long", @LONG

LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "northeast" : __DIR__"map_8_6",
  "southeast" : __DIR__"map_10_6",
  "northwest" : __DIR__"map_8_4",
]));
	set("map_long", 1);
	set("current_light", 1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
