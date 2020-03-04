// File: /d/duli_port/map_19_5.c
// Updated by tmr (Fri May  3 19:23:07 2002)

inherit ROOM;

void create()
{
	  set("short", "������-�n��D");
	  set("long", @LONG

LONG
	  );
	  set("exits", ([ /* 2 element(s) */
	"north" : __DIR__"map_18_5",
	"south" : "/d/duli_village/map_0_5",
]));
	  set("objects", ([ /* 2 element(s) */
	__DIR__"npc/police" : 1,
	__DIR__"npc/passerby" : 1,
]));
	  set("outdoors", "land");
	  set("map_long", 1);

	setup();
	  replace_program(ROOM);
}
