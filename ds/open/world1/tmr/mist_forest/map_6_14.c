// File: /d/mist_forest/map_6_14.c
// Updated by tmr (Thu May 16 20:04:47 2002)

inherit ROOM;

void create()
{
	  set("short", "�g���˪L-�p�|");
	  set("long", @LONG

LONG
	  );
	  set("map_long", 1);
	  set("exits", ([ /* 2 element(s) */
	"southeast" : __DIR__"map_7_15",
	"northwest" : __DIR__"map_5_13",
]));
	  set("outdoors", "forest");

	setup();
	  replace_program(ROOM);
}
