// File: /d/duli_port/map_0_5.c
// Updated by tmr (Sat Mar  9 22:12:01 2002)

inherit ROOM;

void create()
{
	  set("short", "������-�_��D");
	  set("long", @LONG

LONG
	  );
	  set("outdoors", "land");
	  set("map_long", 1);
	  set("exits", ([ /* 2 element(s) */
	"south" : __DIR__"map_1_5",
	"north" : "/d/duli_forest/map_19_9",
]));
        set("objects",([
                __DIR__"npc/tu-san-niu":1,
        ]) );

	setup();
	  replace_program(ROOM);
}
