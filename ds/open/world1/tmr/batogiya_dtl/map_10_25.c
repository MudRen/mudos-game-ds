// File: /d/batogiya_dtl/map_10_25.c
// Updated by tmr (Tue Jul 13 01:40:07 2004)

inherit ROOM;

void create()
{
	  set("short", "���������s��");
	  set("long", @LONG

LONG
	  );
	  set("map_long", 1);
	  set("objects", ([ /* 2 element(s) */
	"/obj/statue.c" : 1,
	"/obj/pot.c" : 1,
]));
	  set("exits", ([ /* 4 element(s) */
	"east" : __DIR__"map_10_26",
	"west" : __DIR__"map_10_24",
	"north" : __DIR__"map_9_25",
	"south" : __DIR__"map_11_25",
]));
	  set("no_fight", 1);

	setup();
	  replace_program(ROOM);
}
