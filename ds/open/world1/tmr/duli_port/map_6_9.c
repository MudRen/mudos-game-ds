// File: /d/duli_port/map_6_9.c
// Updated by tmr (Thu Feb 28 01:49:36 2002)

inherit ROOM;

void create()
{
	  set("short", "������-�s���_�j��");
	  set("long", @LONG

LONG
	  );
	  set("map_long", 1);
	  set("exits", ([ /* 3 element(s) */
	"east" : __DIR__"map_6_10",
	"north" : __DIR__"map_5_9",
	"west" : __DIR__"map_6_8",
]));
	  set("outdoors", "land");

	setup();
	  replace_program(ROOM);
}
