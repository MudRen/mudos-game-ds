// File: /d/duli_port/map_3_5.c
// Updated by tmr (Thu Feb 28 01:45:19 2002)

inherit ROOM;

void create()
{
	  set("short", "������-�_��D");
	  set("long", @LONG

LONG
	  );
	  set("map_long", 1);
	  set("exits", ([ /* 2 element(s) */
	"north" : __DIR__"map_2_5",
	"south" : __DIR__"map_4_5",
]));
        set("objects",([
                __DIR__"npc/passerby":1,        //���H
        ]));
	  set("outdoors", "land");

	setup();
	  replace_program(ROOM);
}
