// Room: /open/world1/manto/sky2_2f/map_3_10.c

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
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"map_3_12",
  "west" : __DIR__"map_3_8",
]));

	setup();
        set("stroom", 1);
}
