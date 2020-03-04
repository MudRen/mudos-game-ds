// Room: /open/world1/tmr/unquiet_manor/map_6_4.c

inherit ROOM;

void create()
{
	set("short", "�ﰩ���X-�J�f");
	set("long", @LONG

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"map_7_4",
  "down" : __DIR__"grave3",
]));
	set("outdoors", "land");
	set("no_clean_up", 0);
	set("current_light", 2);
	set("map_long", 1);

	setup();
	replace_program(ROOM);
}
