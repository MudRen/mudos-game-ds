// File: /d/duli_port/map_18_15.c
// Updated by tmr (Thu Feb 28 01:48:40 2002)

inherit ROOM;

void create()
{
	  set("short", "������-�n��j�D");
	  set("long", @LONG

LONG
	  );
	  set("map_long", 1);
	  set("exits", ([ /* 3 element(s) */
	"east" : __DIR__"map_18_16",
	"north" : __DIR__"map_17_15",
	"south" : __DIR__"map_19_15",
]));
	  set("outdoors", "land");

	setup();
	  replace_program(ROOM);
}
