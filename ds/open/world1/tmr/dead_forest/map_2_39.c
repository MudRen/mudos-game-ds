// File: /d/dead_forest/map_2_39.c
// Updated by tmr (Fri Dec 26 20:33:07 2003)

inherit ROOM;

void create()
{
	  set("short", "�p�|");
	  set("long", @LONG

LONG
	  );
	  set("map_long", 1);
	  set("exits", ([ /* sizeof() == 2 */
	"north" : __DIR__"map_1_39",
	"southwest" : __DIR__"map_3_38",
]));

	setup();
	  replace_program(ROOM);
}
