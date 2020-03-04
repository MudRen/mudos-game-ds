// Room: /open/world1/tmr/bagi/area/3f/map_4_5.c

inherit ROOM;

void create()
{
	set("short", "�H��}�T�h");
	set("long", @LONG

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"map_5_5",
  "northwest" : __DIR__"map_3_4",
]));
	set("map_long", 1);
	set("no_clean_up", 0);
	set("current_light", 2);

	setup();
	replace_program(ROOM);
}
