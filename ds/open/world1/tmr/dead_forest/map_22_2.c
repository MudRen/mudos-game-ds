// File: /d/dead_forest/map_22_2.c
// Updated by tmr (Fri Dec 26 20:35:13 2003)

inherit ROOM;

void create()
{
	  set("short", "�p�|");
	  set("long", @LONG

LONG
	  );
	  set("map_long", 1);
	  set("exits", ([ /* sizeof() == 3 */
	"southeast" : __DIR__"map_23_3",
	"north" : __DIR__"map_21_2",
	"west" : __DIR__"map_22_1",
]));

	setup();
	  replace_program(ROOM);
}
