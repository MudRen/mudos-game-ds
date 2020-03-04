// Room: /open/world1/tmr/bagi/area/2f/map_14_3.c

inherit ROOM;

void create()
{
	set("short", "�H��}�G�h");
	set("long", @LONG

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"map_14_4",
  "northwest" : __DIR__"map_13_2",
]));
	set("map_long", 1);
	set("current_light", 1);
	set("no_clean_up", 0);
        set("objects",([
                __DIR__"npc/corpse":4,
        ]));


	setup();
	replace_program(ROOM);
}
