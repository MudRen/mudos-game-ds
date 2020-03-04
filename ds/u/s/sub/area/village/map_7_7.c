// Room: /u/s/sub/area/village/map_7_7.c

inherit ROOM;

void create()
{
	set("short", "�H�۸�");
	set("long", @LONG

LONG
	);
	set("outdoors", "land");
	set("world", "undefine");
	set("no_clean_up", 0);
	set("map_long", 1);
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"map_7_8",
  "north" : __DIR__"map_6_7",
  "south" : __DIR__"map_8_7",
  "west" : __DIR__"map_7_6",
]));
	set("current_light", 1);

	setup();
	replace_program(ROOM);
}
