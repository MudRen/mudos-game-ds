// File: /d/duli_port/map_19_15.c
// Updated by tmr (Thu Feb 28 01:48:43 2002)

inherit ROOM;

void create()
{
	  set("short", "������-�n��j�D");
	  set("long", @LONG

LONG
	  );
	  set("map_long", 1);
	  set("exits", ([ /* 1 element(s) */
	"north" : __DIR__"map_18_15",
]));
	  set("outdoors", "land");
        set("objects",([
                __DIR__"npc/police":1,
        ]));

	setup();
	  replace_program(ROOM);
}
