// Room: /u/s/sub/area/valley/map_6_5.c

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
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"map_5_5",
  "west" : __DIR__"map_6_4",
]));
	set("current_light", 1);

	setup();
	replace_program(ROOM);
}
