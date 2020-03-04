// File: /d/mist_forest/map_16_14.c
// Updated by tmr (Thu May 16 21:24:15 2002)

inherit ROOM;

void create()
{
	  set("short", "�g���˪L-�p�|");
	  set("long", @LONG

LONG
	  );
	  set("map_long", 1);
	  set("objects", ([ /* 1 element(s) */
	__DIR__"npc/evil-monster" : 1,
]));
	  set("exits", ([ /* 3 element(s) */
	"northeast" : __DIR__"map_15_15",
	"west" : __DIR__"map_16_13",
]));
	  set("outdoors", "forest");

	setup();
	  replace_program(ROOM);
}
