// File: /d/dead_forest/map_23_3.c
// Updated by tmr (Fri Dec 26 20:35:07 2003)

inherit ROOM;

void create()
{
	  set("short", "�p�|");
	  set("long", @LONG

LONG
	  );
	  set("map_long", 1);
	  set("exits", ([ /* sizeof() == 2 */
	"south" : __DIR__"map_24_3",
	"northwest" : __DIR__"map_22_2",
]));

	setup();
	  replace_program(ROOM);
}
