// File: /d/duli_port/map_6_5.c
// Updated by tmr (Thu Feb 28 01:50:12 2002)

inherit ROOM;

void create()
{
	  set("short", "������-�Q�r���f");
	  set("long", @LONG

LONG
	  );
	  set("map_long", 1);
	  set("objects", ([ /* 1 element(s) */
	__DIR__"npc/wang-hu" : 1,
]));
	  set("exits", ([ /* 4 element(s) */
	"east" : __DIR__"map_6_6",
	"north" : __DIR__"map_5_5",
	"west" : __DIR__"map_6_4",
	"south" : __DIR__"map_7_5",
]));
	  set("outdoors", "land");

	setup();
	  replace_program(ROOM);
}
