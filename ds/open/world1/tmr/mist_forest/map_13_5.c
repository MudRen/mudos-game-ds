// File: /d/mist_forest/map_13_5.c
// Updated by tmr (Thu May 16 20:10:39 2002)

inherit ROOM;

void create()
{
	  set("short", "�g���˪L-�p�|");
	  set("long", @LONG

LONG
	  );
	  set("map_long", 1);
	  set("exits", ([ /* 2 element(s) */
	"north" : __DIR__"map_12_5",
	"southwest" : __DIR__"map_14_4",
]));
	  set("outdoors", "forest");

	setup();
	  replace_program(ROOM);
}
