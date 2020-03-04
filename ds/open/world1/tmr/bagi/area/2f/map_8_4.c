// Room: /open/world1/tmr/bagi/area/2f/map_8_4.c

inherit ROOM;

void create()
{
	set("short", "�H��}�G�h");
	set("long", @LONG

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"map_9_5",
  "southwest" : __DIR__"map_9_3",
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
