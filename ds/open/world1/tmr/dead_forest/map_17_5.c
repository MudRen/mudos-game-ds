// File: /d/dead_forest/map_17_5.c
// Updated by tmr (Fri Dec 26 20:35:31 2003)

inherit ROOM;

void create()
{
	  set("short", "�p�|");
	  set("long", @LONG

LONG
	  );
	  set("map_long", 1);
	  set("exits", ([ /* sizeof() == 2 */
	"southeast" : __DIR__"map_18_6",
	"west" : __DIR__"map_17_4",
]));

	setup();
	  replace_program(ROOM);
}
