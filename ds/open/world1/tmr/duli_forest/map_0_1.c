// File: /d/duli_forest/map_0_1.c
// Updated by tmr (Thu Jun 27 17:21:47 2002)

inherit ROOM;

void create()
{
	  set("short", "�L���p��");
	  set("long", @LONG

LONG
	  );
	  set("exits", ([ /* 2 element(s) */
	"south" : __DIR__"map_1_1",
	"north" : "/d/duli_field_w/map_40_40",
]));
	  set("outdoors", "land");
        set("objects",([
        __DIR__"npc/statue":1,
        ]));
	  set("map_long", 1);

	setup();
	  replace_program(ROOM);
}
