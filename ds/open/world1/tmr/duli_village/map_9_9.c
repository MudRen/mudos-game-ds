// File: /d/duli_village/map_9_9.c
// Updated by tmr (Sun May  5 15:10:51 2002)

inherit ROOM;

void create()
{
	  set("short", "���]");
	  set("long", @LONG

LONG
	  );
	  set("exits", ([ /* 1 element(s) */
	"south" : __DIR__"map_10_9",
]));
	  set("outdoors", "forest");
	  set("map_long", 1);

        set("objects",([
                __DIR__"npc/bu-qing-shan":1,
        ]));

	setup();
	  replace_program(ROOM);
}
