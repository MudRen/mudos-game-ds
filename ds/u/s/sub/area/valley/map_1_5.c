// Room: /u/s/sub/area/valley/map_1_5.c

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG

LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/beast_grasshopper_3" : 2,
]));
	set("outdoors", "land");
	set("world", "undefine");
	set("no_clean_up", 0);
	set("map_long", 1);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"map_2_5",
  "west" : __DIR__"map_1_4",
]));
	set("current_light", 2);

	setup();
	replace_program(ROOM);
}
