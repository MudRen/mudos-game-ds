// File: /d/mist_forest/map_15_8.c
// Updated by tmr (Thu May 16 20:09:24 2002)

inherit ROOM;

void create()
{
	  set("short", "�g���˪L-�p�|");
	  set("long", @LONG

LONG
	  );
	  set("map_long", 1);
	  set("exits", ([ /* 3 element(s) */
	"southeast" : __DIR__"map_16_9",
	"south" : __DIR__"map_16_8",
	"northwest" : __DIR__"map_14_7",
]));
	  set("outdoors", "forest");

	setup();
	  replace_program(ROOM);
}
