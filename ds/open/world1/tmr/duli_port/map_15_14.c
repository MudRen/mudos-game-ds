// File: /d/duli_port/map_15_14.c
// Updated by tmr (Thu Feb 28 01:49:12 2002)

inherit ROOM;

void create()
{
	  set("short", "������-�s���n�j��");
	  set("long", @LONG

LONG
	  );
	  set("map_long", 1);
	  set("exits", ([ /* 2 element(s) */
	"east" : __DIR__"map_15_15",
	"west" : __DIR__"map_15_13",
]));
	  set("outdoors", "land");

	setup();
	  replace_program(ROOM);
}
