// File: /d/mist_forest/map_19_9.c
// Updated by tmr (Thu May 16 22:09:11 2002)

inherit ROOM;

void create()
{
	  set("short", "�g���˪L-�p�|");
	  set("long", @LONG

LONG
	  );
	  set("map_long", 1);
	  set("exits", ([ /* 2 element(s) */
	"south" : "/d/duli_forest/map_0_9",
	"north" : __DIR__"map_18_9",
]));
	  set("outdoors", "forest");

	setup();
	  replace_program(ROOM);
}
