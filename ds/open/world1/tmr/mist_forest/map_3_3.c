// File: /d/mist_forest/map_3_3.c
// Updated by tmr (Thu May 16 20:01:09 2002)

inherit ROOM;

void create()
{
	  set("short", "�g���˪L-�p�|");
	  set("long", @LONG

LONG
	  );
	  set("map_long", 1);
	  set("exits", ([ /* 2 element(s) */
	"southeast" : __DIR__"map_4_4",
	"northwest" : __DIR__"map_2_2",
]));
	  set("outdoors", "forest");

	setup();
	  replace_program(ROOM);
}
