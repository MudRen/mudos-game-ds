// File: /d/mist_forest/map_15_3.c
// Updated by tmr (Thu May 30 19:23:09 2002)

inherit ROOM;

void create()
{
	  set("short", "�g���˪L-�p�|");
	  set("long", @LONG

LONG
	  );
	  set("outdoors", "forest");
	  set("map_long", 1);
	  set("exits", ([ /* 3 element(s) */
	"northwest" : __DIR__"map_14_2",
	"southeast" : __DIR__"map_16_4",
	"northeast" : __DIR__"map_14_4",
]));

	setup();
	  replace_program(ROOM);
}
