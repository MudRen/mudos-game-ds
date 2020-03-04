// Room: /open/world1/manto/sky2_1f/map_3_3.c

inherit ROOM;

void create()
{
	set("short", "�m�߫�");
	set("long", @LONG

LONG
	);
	set("light", 1);
	set("current_light", 1);
	set("map_long", 1);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"map_5_3",
]));
        set("objects",([
    __DIR__"npc/goldman5" :10,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
