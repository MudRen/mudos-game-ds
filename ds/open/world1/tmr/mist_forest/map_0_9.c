// File: /d/mist_forest/map_0_9.c
// Updated by tmr (Thu May 16 23:59:47 2002)

inherit ROOM;

void create()
{
	  set("short", "�g��");
	  set("long", @LONG

LONG
	  );
	  set("map_long", 1);
	  set("exits", ([ /* 2 element(s) */
	"south" : __DIR__"map_1_9",
	"north" : __DIR__"map_11_1",
]));
	  set("outdoors", "forest");

	setup();
	  replace_program(ROOM);
}
