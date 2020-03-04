// Room: /open/world1/manto/sky2_1f/map_7_13.c

inherit ROOM;

void create()
{
	set("short", "�Ѧa�|�j��");
	set("long", @LONG

LONG
	);
	set("current_light", 3);
	set("stroom", 1);
	set("light", 1);
	set("map_long", 1);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"map_7_11",
  "south" : "/open/world1/acme/area/pool.c",
]));
	set("no_clean_up", 1);

	setup();
	replace_program(ROOM);
}
