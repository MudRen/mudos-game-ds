// File: /d/mist_forest/map_3_7.c
// Updated by tmr (Thu May 16 19:58:37 2002)

inherit ROOM;

void create()
{
	  set("short", "�g���˪L-�p�|");
	  set("long", @LONG

LONG
	  );
	  set("map_long", 1);
	  set("exits", ([ /* 2 element(s) */
	"southwest" : __DIR__"map_4_6",
	"east" : __DIR__"map_3_8",
]));
	  set("outdoors", "forest");

	setup();
	  replace_program(ROOM);
}
