// Room: /open/world1/tmr/bagi/area/1f/map_10_8.c

inherit ROOM;

void create()
{
	set("short", "�H��}�@�h");
	set("long", @LONG

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"map_11_7",
  "northeast" : __DIR__"map_9_9",
]));
	set("map_long", 1);
	set("current_light", 1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
