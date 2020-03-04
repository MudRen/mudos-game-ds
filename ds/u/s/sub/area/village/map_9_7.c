// Room: /u/s/sub/area/village/map_9_7.c

inherit ROOM;

void create()
{
	set("short", "�H�۸�");
	set("long", @LONG

LONG
	);
	set("map_long", 1);
	set("world", "undefine");
	set("no_clean_up", 0);
	set("outdoors", "land");
	set("current_light", 2);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"map_8_7",
  "south" : __DIR__"vi08",
]));

	setup();
	replace_program(ROOM);
}
