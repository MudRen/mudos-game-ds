// Room: /open/world1/tmr/bagi/area/2f/map_12_1.c

inherit ROOM;

void create()
{
	set("short", "�H��}�G�h");
	set("long", @LONG

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"map_11_1",
  "southeast" : __DIR__"map_13_2",
]));
	set("map_long", 1);
	set("current_light", 1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
