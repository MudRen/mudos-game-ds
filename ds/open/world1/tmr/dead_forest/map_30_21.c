// File: /d/dead_forest/map_30_21.c
// Updated by tmr (Fri Dec 26 20:36:15 2003)

inherit ROOM;

void create()
{
	  set("short", "�p�|");
	  set("long", @LONG

LONG
	  );
	  set("map_long", 1);
	  set("exits", ([ /* sizeof() == 2 */
	"north" : __DIR__"map_29_21",
	"southwest" : __DIR__"map_31_20",
]));

	setup();
	  replace_program(ROOM);
}
