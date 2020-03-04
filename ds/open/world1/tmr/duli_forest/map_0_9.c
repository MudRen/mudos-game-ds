// File: /d/duli_forest/map_0_9.c
// Updated by tmr (Thu May 16 23:07:43 2002)

inherit ROOM;

void create()
{
	  set("short", "�L���p��");
	  set("long", @LONG

LONG
	  );
	  set("objects", ([ /* 2 element(s) */
	__DIR__"npc/police" : 4,
	__DIR__"npc/police_captain" : 1,
]));
	  set("map_long", 1);
	  set("exits", ([ /* 2 element(s) */
	"south" : __DIR__"map_1_9",
	"north" : "/d/mist_forest/map_19_9",
]));
	  set("outdoors", "land");

	setup();
	  replace_program(ROOM);
}
