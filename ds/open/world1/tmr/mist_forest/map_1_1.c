// File: /d/mist_forest/map_1_1.c
// Updated by tmr (Sat May 18 12:19:20 2002)

inherit ROOM;

void create()
{
	  set("short", "�g��");
	  set("long", @LONG

LONG
	  );
	  set("exits", ([ /* 2 element(s) */
	"south" : __DIR__"map_2_1",
	"north" : __DIR__"big_tree",
]));
	  set("map_long", 1);
	  set("outdoors", "forest");

	setup();
	  replace_program(ROOM);
}
