// File: /d/dead_forest/map_39_0.c
// Updated by tmr (Sun Mar  7 09:30:05 2004)

inherit ROOM;

void create()
{
	  set("short", "�p�|");
	  set("long", @LONG

LONG
	  );
	  set("map_long", 1);
	  set("exits", ([ /* 2 element(s) */
	"south" : "/d/duli_forest/map_0_17",
	"north" : __DIR__"map_38_0",
]));

	setup();
	  replace_program(ROOM);
}
