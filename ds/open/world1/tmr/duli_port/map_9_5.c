// File: /d/duli_port/map_9_5.c
// Updated by tmr (Thu Feb 28 01:47:17 2002)

inherit ROOM;

void create()
{
	  set("short", "������-�n��D");
	  set("long", @LONG

LONG
	  );
	  set("map_long", 1);
	  set("exits", ([ /* 2 element(s) */
	"north" : __DIR__"map_8_5",
	"south" : __DIR__"map_10_5",
]));
	  set("outdoors", "land");

	setup();
	  replace_program(ROOM);
}
