// File: /d/mist_forest/map_15_15.c
// Updated by tmr (Thu May 16 20:07:59 2002)

inherit ROOM;

void create()
{
	  set("short", "�g���˪L-�p�|");
	  set("long", @LONG

LONG
	  );
	  set("map_long", 1);
	  set("exits", ([ /* 3 element(s) */
	"northeast" : __DIR__"map_14_16",
	"southwest" : __DIR__"map_16_14",
	"northwest" : __DIR__"map_14_14",
]));
	  set("outdoors", "forest");

	setup();
	  replace_program(ROOM);
}
