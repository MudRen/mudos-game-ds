// Room: /u/s/sub/area/valley/map_1_3.c

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
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"map_1_4",
  "west" : __DIR__"map_1_2",
  "south" : __DIR__"map_2_3",
]));
	set("current_light", 1);

	setup();
	replace_program(ROOM);
}
