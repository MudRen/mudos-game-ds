// File: /d/duli_forest/map_17_9.c
// Updated by tmr (Sat Mar  9 22:12:24 2002)

inherit ROOM;

void create()
{
	  set("short", "�Q�r���f");
	  set("long", @LONG

LONG
	  );
	  set("outdoors", "land");
	  set("map_long", 1);
	  set("exits", ([ /* 4 element(s) */
	"east" : __DIR__"map_17_10",
	"south" : __DIR__"map_18_9",
	"west" : __DIR__"map_17_8",
	"north" : __DIR__"map_16_9",
]));

	setup();
	  replace_program(ROOM);
}
