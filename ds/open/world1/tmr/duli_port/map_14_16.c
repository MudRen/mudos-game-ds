// File: /d/duli_port/map_14_16.c
// Updated by tmr (Thu Feb 28 08:05:28 2002)

inherit ROOM;

void create()
{
	  set("short", "�����ȩ����f");
	  set("long", @LONG

LONG
	  );
	  set("exits", ([ /* 2 element(s) */
	"east" : __DIR__"duli_hotel",
	"west" : __DIR__"map_14_15",
]));
	  set("map_long", 1);
	  set("outdoors", "land");

	setup();
	  replace_program(ROOM);
}
