// File: /d/dead_forest/map_3_38.c
// Updated by tmr (Fri Dec 26 20:33:17 2003)

inherit ROOM;

void create()
{
	  set("short", "�p�|");
	  set("long", @LONG

LONG
	  );
	  set("map_long", 1);
	  set("exits", ([ /* sizeof() == 3 */
	"northeast" : __DIR__"map_2_39",
	"west" : __DIR__"map_3_37",
	"south" : __DIR__"map_4_38",
]));

	setup();
	  replace_program(ROOM);
}
