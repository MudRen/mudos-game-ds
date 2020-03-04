// Room: /u/s/sub/area/village/map_7_8.c

inherit ROOM;

void create()
{
	set("short", "��a");
	set("long", @LONG

LONG
	);
	set("outdoors", "land");
	set("world", "undefine");
	set("no_clean_up", 0);
	set("map_long", 1);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"map_6_8",
  "west" : __DIR__"map_7_7",
]));
	set("current_light", 1);

	setup();
	replace_program(ROOM);
}
