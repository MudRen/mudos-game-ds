// File: /d/mist_forest/map_7_7.c
// Updated by tmr (Thu May 16 20:01:41 2002)

inherit ROOM;

void create()
{
	  set("short", "�g���˪L-�p�|");
	  set("long", @LONG

LONG
	  );
	  set("map_long", 1);
	  set("exits", ([ /* 2 element(s) */
	"east" : __DIR__"map_7_8",
	"northwest" : __DIR__"map_6_6",
]));
	  set("outdoors", "forest");

	setup();
	  replace_program(ROOM);
}
