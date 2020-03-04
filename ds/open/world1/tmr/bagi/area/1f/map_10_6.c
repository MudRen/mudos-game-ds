// Room: /open/world1/tmr/bagi/area/1f/map_10_6.c

inherit ROOM;

void create()
{
	set("short", "�H��}�@�h");
	set("long", @LONG

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"map_11_7",
  "northwest" : __DIR__"map_9_5",
]));
        set("objects",([
                __DIR__"npc/trainee":1,
                  __DIR__"npc/jie2":1,
        ]));
	set("map_long", 1);
	set("current_light", 1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
