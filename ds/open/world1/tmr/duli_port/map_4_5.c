// File: /d/duli_port/map_4_5.c
// Updated by tmr (Thu Feb 28 01:45:18 2002)

inherit ROOM;

void create()
{
	  set("short", "������-�_��D");
	  set("long", @LONG

LONG
	  );
	  set("map_long", 1);
	  set("exits", ([ /* 2 element(s) */
	"north" : __DIR__"map_3_5",
	"south" : __DIR__"map_5_5",
]));
	  set("outdoors", "land");

	setup();
	  replace_program(ROOM);
}
