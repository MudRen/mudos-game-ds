// File: /d/duli_port/map_16_15.c
// Updated by tmr (Thu Feb 28 01:48:38 2002)

inherit ROOM;

void create()
{
	  set("short", "������-�n��j�D");
	  set("long", @LONG

LONG
	  );
	  set("map_long", 1);
	  set("exits", ([ /* 2 element(s) */
	"north" : __DIR__"map_15_15",
	"south" : __DIR__"map_17_15",
]));
	  set("outdoors", "land");

	setup();
	  replace_program(ROOM);
}
