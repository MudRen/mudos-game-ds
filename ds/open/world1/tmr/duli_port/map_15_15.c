// File: /d/duli_port/map_15_15.c
// Updated by tmr (Thu Feb 28 01:48:37 2002)

inherit ROOM;

void create()
{
	  set("short", "������-�n��j�D");
	  set("long", @LONG

LONG
	  );
	  set("map_long", 1);
	  set("exits", ([ /* 3 element(s) */
	"north" : __DIR__"map_14_15",
	"west" : __DIR__"map_15_14",
	"south" : __DIR__"map_16_15",
]));
        set("objects",([
                  __DIR__"npc/forget-master":1,        
        ]));
	  set("outdoors", "land");

	setup();
	  replace_program(ROOM);
}
