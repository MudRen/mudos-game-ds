// File: /d/dead_forest/map_4_32.c
// Updated by tmr (Fri Dec 26 20:33:58 2003)

inherit ROOM;

void create()
{
	  set("short", "�p�|");
	  set("long", @LONG

LONG
	  );
	  set("map_long", 1);
	  set("exits", ([ /* sizeof() == 2 */
	"southwest" : __DIR__"map_5_31",
	"east" : __DIR__"map_4_33",
]));

	setup();
	  replace_program(ROOM);
}
