// File: /d/mist_forest/map_4_6.c
// Updated by tmr (Thu May 16 19:59:05 2002)

inherit ROOM;

void create()
{
	  set("short", "�g���˪L-�p�|");
	  set("long", @LONG

LONG
	  );
	  set("map_long", 1);
	  set("exits", ([ /* 2 element(s) */
	"northeast" : __DIR__"map_3_7",
	"southwest" : __DIR__"map_5_5",
]));
	  set("outdoors", "forest");

	setup();
	  replace_program(ROOM);
}
