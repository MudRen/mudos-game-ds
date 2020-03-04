// Room: /u/s/sub/area/valley/map_5_4.c

inherit ROOM;

void create()
{
	set("short", "�˪L");
	set("long", @LONG

LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/beast_turtledove_7.c" : 1,
]));
	set("outdoors", "forest");
	set("world", "undefine");
	set("no_clean_up", 0);
	set("map_long", 1);
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"map_5_5",
  "north" : __DIR__"map_4_4",
  "west" : __DIR__"map_5_3",
  "south" : __DIR__"map_6_4",
]));
	set("current_light", 4);

	setup();
	replace_program(ROOM);
}
