// File: /d/duli_village/map_0_5.c
// Updated by tmr (Fri May  3 19:22:54 2002)

inherit ROOM;

void create()
{
	  set("short", "�����۸�");
	  set("long", @LONG

LONG
	  );
	  set("exits", ([ /* 2 element(s) */
	"north" : "/d/duli_port/map_19_5",
	"south" : __DIR__"map_1_5",
]));
	  set("outdoors", "forest");
	  set("map_long", 1);

	setup();
	  replace_program(ROOM);
}
