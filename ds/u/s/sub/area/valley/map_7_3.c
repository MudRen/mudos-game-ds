// Room: /u/s/sub/area/valley/map_7_3.c

inherit ROOM;

void create()
{
	set("short", "�������s���J�f");
	set("long", @LONG

LONG
	);
	set("outdoors", "land");
	set("world", "undefine");
	set("no_clean_up", 0);
	set("map_long", 1);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"map_6_3",
]));
	set("current_light", 1);

	setup();
	replace_program(ROOM);
}
