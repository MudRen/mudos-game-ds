// File: /d/dead_forest/map_18_6.c
// Updated by tmr (Fri Dec 26 20:35:39 2003)

inherit ROOM;

void create()
{
	  set("short", "�p�|");
	  set("long", @LONG

LONG
	  );
	  set("map_long", 1);
	  set("exits", ([ /* sizeof() == 2 */
	"northwest" : __DIR__"map_17_5",
	"east" : __DIR__"map_18_7",
]));

	setup();
	  replace_program(ROOM);
}
