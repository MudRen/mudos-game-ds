// Room: /open/world1/tmr/bagi/area/1f/map_6_4.c

inherit ROOM;

void create()
{
	set("short", "�H��}�@�h");
	set("long", @LONG

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"map_5_5",
  "southwest" : __DIR__"map_7_3",
]));
        set("objects",([
                __DIR__"npc/trainee":2,
        ]));
	set("map_long", 1);
	set("current_light", 1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
