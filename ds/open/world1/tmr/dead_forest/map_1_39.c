// File: /d/dead_forest/map_1_39.c
// Updated by tmr (Sat Jun 19 19:42:02 2004)

inherit ROOM;

void create()
{
	  set("short", "�p�|");
	  set("long", @LONG

LONG
	  );
	  set("map_long", 1);
	  set("exits", ([ /* 2 element(s) */
        "northeast" : "/d/crush_bone/map_23_4",
	"south" : __DIR__"map_2_39",
]));
	  set("objects", ([ /* 1 element(s) */
	__DIR__"npc/obj/placard.c" : 1,
]));

	setup();
	  replace_program(ROOM);
}
