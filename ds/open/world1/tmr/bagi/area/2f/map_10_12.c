// Room: /open/world1/tmr/bagi/area/2f/map_10_12.c

inherit ROOM;

void create()
{
	set("short", "�H��}�G�h");
	set("long", @LONG

LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "southeast" : __DIR__"map_11_13",
  "northeast" : __DIR__"map_9_13",
  "west" : __DIR__"map_10_11",
]));
        set("objects",([
                __DIR__"npc/jin":1,
        ]));

	set("map_long", 1);
	set("current_light", 1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
