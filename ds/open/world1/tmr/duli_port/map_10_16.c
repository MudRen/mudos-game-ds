// File: /d/duli_port/map_10_16.c
// Updated by tmr (Thu Feb 28 08:39:37 2002)

inherit ROOM;

void create()
{
	  set("short", "�Ȧ���f");
	  set("long", @LONG

LONG
	  );
	  set("exits", ([ /* 2 element(s) */
	"east" : __DIR__"duli_bank",
	"west" : __DIR__"map_10_15",
]));
	  set("outdoors", "land");
	  set("map_long", 1);

	setup();
	  replace_program(ROOM);
}
