// File: /d/duli_village/map_6_11.c
// Updated by tmr (Fri May  3 19:36:51 2002)

inherit ROOM;

void create()
{
	  set("short", "�۫�");
	  set("long", @LONG

LONG
	  );
	  set("exits", ([ /* 1 element(s) */
	"west" : __DIR__"map_6_10",
]));
	  set("outdoors", "forest");
	  set("map_long", 1);
        set("objects",([
                __DIR__"npc/jiang-yu-huo":1,
        ]));

	setup();
	  replace_program(ROOM);
}
