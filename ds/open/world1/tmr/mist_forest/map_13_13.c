// File: /d/mist_forest/map_13_13.c
// Updated by tmr (Thu May 16 20:07:53 2002)

inherit ROOM;

void create()
{
	  set("short", "�g���˪L-�p�|");
	  set("long", @LONG

LONG
	  );
	  set("map_long", 1);
	  set("exits", ([ /* 2 element(s) */
	"southeast" : __DIR__"map_14_14",
	"north" : __DIR__"map_12_13",
]));
	  set("outdoors", "forest");

	setup();
	  replace_program(ROOM);
}
