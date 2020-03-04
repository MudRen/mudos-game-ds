// Room: /u/s/sub/area/valley/map_4_1.c

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG

LONG
	);
	set("outdoors", "land");
	set("world", "undefine");
	set("no_clean_up", 0);
	set("map_long", 1);
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"map_4_2",
  "north" : __DIR__"map_3_1",
  "south" : __DIR__"map_5_1",
]));
	set("current_light", 1);

	setup();
	replace_program(ROOM);
}
