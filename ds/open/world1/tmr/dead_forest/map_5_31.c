// File: /d/dead_forest/map_5_31.c
// Updated by tmr (Fri Dec 26 20:34:07 2003)

inherit ROOM;

void create()
{
	  set("short", "�p�|");
	  set("long", @LONG

LONG
	  );
	  set("map_long", 1);
	  set("exits", ([ /* sizeof() == 2 */
	"northeast" : __DIR__"map_4_32",
	"west" : __DIR__"map_5_30",
]));

	setup();
	  replace_program(ROOM);
}
