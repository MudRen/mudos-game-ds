// File: /d/mist_forest/map_15_10.c
// Updated by tmr (Thu May 16 20:08:51 2002)

inherit ROOM;

void create()
{
	  set("short", "�g���˪L-�p�|");
	  set("long", @LONG

LONG
	  );
	  set("map_long", 1);
	  set("exits", ([ /* 3 element(s) */
	"south" : __DIR__"map_16_10",
	"northeast" : __DIR__"map_14_11",
	"southwest" : __DIR__"map_16_9",
]));
	  set("outdoors", "forest");

	setup();
	  replace_program(ROOM);
}
