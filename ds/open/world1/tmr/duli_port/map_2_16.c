// File: /d/duli_port/map_2_16.c
// Updated by tmr (Thu Feb 28 08:40:01 2002)

inherit ROOM;

void create()
{
	  set("short", "�Z�������f");
	  set("long", @LONG

LONG
	  );
	  set("exits", ([ /* 2 element(s) */
	"east" : __DIR__"duli_smith",
	"west" : __DIR__"map_2_15",
]));
	  set("outdoors", "land");
	  set("map_long", 1);

	setup();
	  replace_program(ROOM);
}
