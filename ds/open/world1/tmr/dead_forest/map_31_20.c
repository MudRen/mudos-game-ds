// File: /d/dead_forest/map_31_20.c
// Updated by tmr (Fri Dec 26 20:36:27 2003)

inherit ROOM;

void create()
{
	  set("short", "�p�|");
	  set("long", @LONG

LONG
	  );
	  set("map_long", 1);
	  set("exits", ([ /* sizeof() == 2 */
	"northeast" : __DIR__"map_30_21",
	"south" : __DIR__"map_32_20",
]));

	setup();
	  replace_program(ROOM);
}
