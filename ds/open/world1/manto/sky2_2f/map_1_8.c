// Room: /open/world1/manto/sky2_2f/map_1_8.c

inherit ROOM;

void create()
{
	set("short", "��D��");
	set("long", @LONG

LONG
	);
	set("light", 1);
	set("current_light", 1);
	set("map_long", 1);
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"map_1_10",
  "west" : __DIR__"map_1_6",
  "south" : __DIR__"map_3_8",
]));
        set("objects",([
    __DIR__"obj/heaven_box" :1,
]));

	setup();
        set("stroom", 1);
}
