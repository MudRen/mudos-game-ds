// Room: /open/world1/manto/sky2_2f/map_3_4.c

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
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"map_3_6",
]));

	setup();
        set("stroom", 1);
}
