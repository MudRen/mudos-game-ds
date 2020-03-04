// Room: /open/world1/tmr/bagi/area/3f/map_10_18.c

inherit ROOM;

void create()
{
	set("short", "�H��}�T�h");
	set("long", @LONG

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"map_9_18",
  "southeast" : __DIR__"map_11_19",
]));
	set("map_long", 1);
	set("current_light", 1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
