// File: /d/duli_port/map_0_15.c
// Updated by tmr (Thu Feb 28 01:48:15 2002)

inherit ROOM;

void create()
{
	  set("short", "������-�_��j�D");
	  set("long", @LONG

LONG
	  );
	  set("map_long", 1);
	  set("exits", ([ /* 1 element(s) */
	"south" : __DIR__"map_1_15",
]));
	  set("outdoors", "land");
        set("objects", ([
        ]));

        set("no_clear",1);
	setup();
	  replace_program(ROOM);
}
