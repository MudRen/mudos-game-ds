// File: /d/dead_forest/map_4_9.c
// Updated by tmr (Wed May 26 23:31:56 2004)

inherit ROOM;

void create()
{
	  set("short", "�j��");
	  set("long", @LONG

LONG
	  );
	  set("map_long", 1);
	  set("exits", ([ /* 3 element(s) */
	"south" : __DIR__"map_5_9",
	"enter" : __DIR__"temple2",
	"east" : __DIR__"map_4_10",
]));

	setup();
	  replace_program(ROOM);
}
