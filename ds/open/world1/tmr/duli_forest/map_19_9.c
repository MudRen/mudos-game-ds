// File: /d/duli_forest/map_19_9.c
// Updated by tmr (Sat Mar  9 22:11:39 2002)

inherit ROOM;

void create()
{
	  set("short", "�p��");
	  set("long", @LONG

LONG
	  );
	  set("outdoors", "land");
	  set("map_long", 1);
	  set("exits", ([ /* 2 element(s) */
	"south" : "/d/duli_port/map_0_5",
	"north" : __DIR__"map_18_9",
]));

	setup();
	  replace_program(ROOM);
}
