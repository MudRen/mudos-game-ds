// Room: /open/world1/tmr/bagi/area/3f/map_4_15.c

inherit ROOM;

void create()
{
	set("short", "�H��}�T�h");
	set("long", @LONG

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"map_5_15",
  "northeast" : __DIR__"map_3_16",
]));
	set("map_long", 1);
	set("current_light", 1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
