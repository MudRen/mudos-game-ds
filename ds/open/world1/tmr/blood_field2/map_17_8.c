// Room: /open/world1/tmr/blood_field2/map_17_8.c

inherit ROOM;

void create()
{
	set("short", "��a");
	set("long", @LONG

LONG
	);
	set("map_long", 1);
	set("current_light", 1);
	set("outdoors", "forest");
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"map_18_8",
  "east" : __DIR__"map_17_9",
  "north" : __DIR__"map_16_8",
  "west" : __DIR__"map_17_7",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
