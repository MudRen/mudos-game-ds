// File: /d/mist_forest/map_4_12.c
// Updated by tmr (Thu May 16 20:05:19 2002)

inherit ROOM;

void create()
{
	  set("short", "�g���˪L-�p�|");
	  set("long", @LONG

LONG
	  );
	  set("map_long", 1);
	  set("exits", ([ /* 2 element(s) */
	"southeast" : __DIR__"map_5_13",
	"northwest" : __DIR__"map_3_11",
]));
	  set("outdoors", "forest");

	setup();
	  replace_program(ROOM);
}
