// File: /d/mist_forest/map_2_16.c
// Updated by tmr (Thu May 16 20:02:35 2002)

inherit ROOM;

void create()
{
	  set("short", "�g���˪L-�p�|");
	  set("long", @LONG

LONG
	  );
	  set("map_long", 1);
	  set("exits", ([ /* 2 element(s) */
	"southwest" : __DIR__"map_3_15",
	"east" : __DIR__"map_2_17",
]));
	  set("outdoors", "forest");

	setup();
	  replace_program(ROOM);
}
