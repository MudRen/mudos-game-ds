// Room: /open/world1/manto/sky2_1f/map_7_3.c

inherit ROOM;

void create()
{
	set("short", "�m�߫�");
	set("long", @LONG

LONG
	);
	set("light", 1);
	set("ourdoors", "land");
	set("current_light", 1);
	set("map_long", 1);
	set("outdoors", "land");
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"map_5_3",
  "east" : __DIR__"map_7_5",
  "west" : __DIR__"map_7_1",
]));
        set("objects",([
    __DIR__"npc/goldman5" :10,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
