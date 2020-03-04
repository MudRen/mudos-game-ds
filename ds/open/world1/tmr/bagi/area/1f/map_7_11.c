// Room: /open/world1/tmr/bagi/area/1f/map_7_11.c

inherit ROOM;

void create()
{
	set("short", "�H��}�@�h");
	set("long", @LONG

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"map_8_10",
  "northwest" : __DIR__"map_6_10",
]));
        set("objects",([
                __DIR__"npc/trainee":1,
        ]));
	set("map_long", 1);
	set("current_light", 1);
	set("no_clean_up", 0);

	setup();
}
