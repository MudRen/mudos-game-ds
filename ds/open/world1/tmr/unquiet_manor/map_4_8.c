// Room: /open/world1/tmr/unquiet_manor/map_4_8.c

inherit ROOM;

void create()
{
	set("short", "�L�礧�X-�J�f");
	set("long", @LONG

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"map_5_8",
  "down" : __DIR__"grave5",
]));
	set("outdoors", "land");
	set("no_clean_up", 0);
	set("current_light", 2);
	set("map_long", 1);

	setup();
	replace_program(ROOM);
}
