// File: /d/mist_forest/map_16_9.c
// Updated by tmr (Thu May 16 21:26:44 2002)

inherit ROOM;

void create()
{
	  set("short", "�g���˪L-�p�|");
	  set("long", @LONG

LONG
	  );
	  set("map_long", 1);
	  set("exits", ([ /* 5 element(s) */
	"south" : __DIR__"map_17_9",
	"northeast" : __DIR__"map_15_10",
	"east" : __DIR__"map_16_10",
	"west" : __DIR__"map_16_8",
	"northwest" : __DIR__"map_15_8",
]));
	  set("outdoors", "forest");

	setup();
	  replace_program(ROOM);
}
