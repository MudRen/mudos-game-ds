// File: /d/mist_forest/map_1_17.c
// Updated by tmr (Thu May 16 23:58:13 2002)

inherit ROOM;

void create()
{
	  set("short", "�g��");
	  set("long", @LONG

LONG
	  );
	  set("map_long", 1);
	  set("exits", ([ /* 2 element(s) */
	"south" : __DIR__"map_2_17",
	"north" : __DIR__"map_8_17",
]));
	  set("outdoors", "forest");

	setup();
	  replace_program(ROOM);
}
