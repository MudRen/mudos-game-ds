// Room: /u/s/sub/area/valley/map_3_2.c

inherit ROOM;

void create()
{
	set("short", "�˪L");
	set("long", @LONG

LONG
	);
	set("outdoors", "land");
	set("world", "undefine");
	set("no_clean_up", 0);
	set("map_long", 1);
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"map_3_3",
  "north" : __DIR__"map_2_2",
  "west" : __DIR__"map_3_1",
  "south" : __DIR__"map_4_2",
]));
	set("current_light", 1);

	setup();
	replace_program(ROOM);
}
