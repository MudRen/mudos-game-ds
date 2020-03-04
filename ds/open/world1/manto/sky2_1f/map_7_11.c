// Room: /open/world1/manto/sky2_1f/map_7_11.c

inherit ROOM;

void create()
{
	set("short", "�Ѧa�|�j�U");
	set("long", @LONG

LONG
	);
	set("current_light", 2);
	set("light", 1);
	set("map_long", 1);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"map_7_13",
  "west" : __DIR__"map_7_9",
]));
        set("objects",([
    __DIR__"obj/tree" :1,
]));

	setup();
        set("stroom", 1);
	replace_program(ROOM);
}
