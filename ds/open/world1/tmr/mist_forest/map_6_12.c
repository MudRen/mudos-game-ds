// File: /d/mist_forest/map_6_12.c
// Updated by tmr (Thu May 16 20:03:02 2002)

inherit ROOM;

void create()
{
	  set("short", "�g���˪L-�p�|");
	  set("long", @LONG

LONG
	  );
	  set("map_long", 1);
	  set("exits", ([ /* 2 element(s) */
	"northeast" : __DIR__"map_5_13",
	"southwest" : __DIR__"map_7_11",
]));
	  set("outdoors", "forest");

	setup();
	  replace_program(ROOM);
}
