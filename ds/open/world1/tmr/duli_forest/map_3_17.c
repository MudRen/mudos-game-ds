// File: /d/duli_forest/map_3_17.c
// Updated by tmr (Mon Mar 11 08:26:20 2002)

inherit ROOM;

void create()
{
	  set("short", "�L���p��");
	  set("long", @LONG

LONG
	  );
	  set("map_long", 1);
	  set("exits", ([ /* 2 element(s) */
	"south" : __DIR__"map_4_17",
	"north" : __DIR__"map_2_17",
]));
	  set("outdoors", "land");

	setup();
	  replace_program(ROOM);
}
