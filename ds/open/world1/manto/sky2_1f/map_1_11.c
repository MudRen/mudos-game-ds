// Room: /open/world1/manto/sky2_1f/map_1_11.c

inherit ROOM;

void create()
{
	set("short", "�Z����");
	set("long", @LONG

LONG
	);
	set("light", 1);
	set("current_light", 1);
	set("map_long", 1);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"map_3_11",
]));
        set("objects",([
    __DIR__"obj/weapon_box" :1,
]));

	setup();
        set("stroom", 1);
}
