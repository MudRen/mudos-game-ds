// File: /d/mist_forest/map_11_5.c
// Updated by tmr (Thu May 16 20:15:01 2002)

inherit ROOM;

void create()
{
	  set("short", "�g��");
	  set("long", @LONG

LONG
	  );
	  set("map_long", 1);
	  set("exits", ([ /* 2 element(s) */
	"south" : __DIR__"map_12_5",
	"north" : __DIR__"map_0_9",
]));
	  set("outdoors", "forest");

	setup();
	  replace_program(ROOM);
}
