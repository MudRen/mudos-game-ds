// File: /d/duli_port/map_14_15.c
// Updated by tmr (Thu Feb 28 01:48:36 2002)

inherit ROOM;

void create()
{
	  set("short", "������-�n��j�D");
	  set("long", @LONG

LONG
	  );
	  set("map_long", 1);
	  set("exits", ([ /* 3 element(s) */
	"east" : __DIR__"map_14_16",
	"north" : __DIR__"map_13_15",
	"south" : __DIR__"map_15_15",
]));
	  set("outdoors", "land");

	setup();
	  replace_program(ROOM);
}
