// File: /d/duli_port/map_6_10.c
// Updated by tmr (Thu Feb 28 01:49:36 2002)

inherit ROOM;

void create()
{
	  set("short", "������-�s���_�j��");
	  set("long", @LONG

LONG
	  );
	  set("map_long", 1);
	  set("exits", ([ /* 3 element(s) */
	"east" : __DIR__"map_6_11",
	"west" : __DIR__"map_6_9",
	"south" : __DIR__"map_7_10",
]));
	  set("outdoors", "land");
        set("objects",([
                __DIR__"npc/li-qian-jun" : 1,
        ]) );

	setup();
	  replace_program(ROOM);
}
