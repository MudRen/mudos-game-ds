// File: /d/duli_port/map_5_9.c
// Updated by tmr (Wed Feb 27 21:18:49 2002)

inherit ROOM;

void create()
{
	  set("short", "������-��D");
	  set("long", @LONG

LONG
	  );
	  set("map_long", 1);
	  set("exits", ([ /* 2 element(s) */
	"north" : __DIR__"duli_shop.c",
	"south" : __DIR__"map_6_9",
]));
	  set("outdoors", "land");

	setup();
	  replace_program(ROOM);
}
