// File: /d/mist_forest/map_3_15.c
// Updated by tmr (Thu May 16 20:02:42 2002)

inherit ROOM;

void create()
{
	  set("short", "�g���˪L-�p�|");
	  set("long", @LONG

LONG
	  );
	  set("map_long", 1);
	  set("exits", ([ /* 2 element(s) */
	"northeast" : __DIR__"map_2_16",
	"southwest" : __DIR__"map_4_14",
]));
	  set("outdoors", "forest");

	setup();
	  replace_program(ROOM);
}
