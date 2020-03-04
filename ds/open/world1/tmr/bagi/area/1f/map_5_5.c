// Room: /open/world1/tmr/bagi/area/1f/map_5_5.c

inherit ROOM;

void create()
{
	set("short", "�H��}�@�h");
	set("long", @LONG

LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "southeast" : __DIR__"map_6_6",
  "northeast" : __DIR__"map_4_6",
  "southwest" : __DIR__"map_6_4",
]));
	set("map_long", 1);
	set("current_light", 1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
