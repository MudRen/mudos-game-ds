// File: /d/duli_port/map_6_1.c
// Updated by tmr (Wed Feb 27 21:03:18 2002)

inherit ROOM;

void create()
{
	  set("short", "������-��D");
	  set("long", @LONG

LONG
	  );
	  set("map_long", 1);
	  set("exits", ([ /* 2 element(s) */
	"east" : __DIR__"map_6_2",
	"west" : __DIR__"duli_port",
]));
        set("objects",([
                __DIR__"npc/du-gui":1,
        ]));
	  set("outdoors", "land");

	setup();
	  replace_program(ROOM);
}
