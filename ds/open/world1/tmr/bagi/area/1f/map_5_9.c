// Room: /open/world1/tmr/bagi/area/1f/map_5_9.c

inherit ROOM;

void create()
{
	set("short", "�H��}�@�h");
	set("long", @LONG

LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "southeast" : __DIR__"map_6_10",
  "southwest" : __DIR__"map_6_8",
  "northwest" : __DIR__"map_4_8",
]));
	set("map_long", 1);
	set("current_light", 1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
