// File: /d/barbarian_island/map_15_13.c
// Updated by tmr (Wed May  8 22:49:42 2002)

inherit ROOM;

void create()
{
	  set("short", "��q�W���p��");
	  set("long", @LONG

LONG
	  );
	  set("map_long", 1);
	  set("outdoors", "forest");
	  set("exits", ([ /* 3 element(s) */
	"down" : "/d/duli_village/sea_room9",
	"west" : __DIR__"map_15_12",
	"north" : __DIR__"map_14_13",
]));

	setup();
	  replace_program(ROOM);
}
