// File: /d/mist_forest/map_4_4.c
// Updated by tmr (Thu May 16 20:01:15 2002)

inherit ROOM;

void create()
{
	  set("short", "�g���˪L-�p�|");
	  set("long", @LONG

LONG
	  );
	  set("map_long", 1);
	  set("exits", ([ /* 2 element(s) */
	"southeast" : __DIR__"map_5_5",
	"northwest" : __DIR__"map_3_3",
]));
	  set("outdoors", "forest");

	setup();
	  replace_program(ROOM);
}
