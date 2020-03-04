// Room: /open/world1/tmr/bagi/area/2f/map_9_9.c

inherit ROOM;

void create()
{
	set("short", "�H��}�G�h");
	set("long", @LONG

LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"map_8_9",
  "southeast" : __DIR__"map_10_10",
  "west" : __DIR__"map_9_8",
]));
	set("map_long", 1);
	set("current_light", 1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
