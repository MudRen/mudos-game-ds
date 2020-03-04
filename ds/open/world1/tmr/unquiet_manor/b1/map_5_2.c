// Room: /open/world1/tmr/unquiet_manor/b1/map_5_2.c

inherit ROOM;

void create()
{
	set("short", "�X�J�f");
	set("long", @LONG

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"map_6_2",
  "up" : "/open/world1/tmr/unquiet_manor/map_6_4",
]));
	set("outdoors", "land");
	set("no_clean_up", 0);
	set("current_light", 1);
	set("map_long", 1);

	setup();
	replace_program(ROOM);
}
