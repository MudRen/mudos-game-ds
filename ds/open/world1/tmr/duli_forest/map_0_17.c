// File: /d/duli_forest/map_0_17.c
// Updated by tmr (Sun Mar  7 09:30:08 2004)

inherit ROOM;

void create()
{
	  set("short", "�L���p��");
	  set("long", @LONG

LONG
	  );
	  set("outdoors", "land");
	  set("map_long", 1);
	  set("exits", ([ /* 2 element(s) */
	"south" : __DIR__"map_1_17",
	"north" : "/d/dead_forest/map_39_0",
]));

	setup();
	  replace_program(ROOM);
}
