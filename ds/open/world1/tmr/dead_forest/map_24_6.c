// File: /d/dead_forest/map_24_6.c
// Updated by tmr (Fri Dec 26 20:34:44 2003)

inherit ROOM;

void create()
{
	  set("short", "�p�|");
	  set("long", @LONG

LONG
	  );
	  set("map_long", 1);
	  set("exits", ([ /* sizeof() == 2 */
	"north" : __DIR__"map_23_6",
	"southwest" : __DIR__"map_25_5",
]));

	setup();
	  replace_program(ROOM);
}
