// File: /d/duli_port/map_15_5.c
// Updated by tmr (Thu Feb 28 01:47:22 2002)

inherit ROOM;

void create()
{
	  set("short", "������-�n��D");
	  set("long", @LONG

LONG
	  );
	  set("map_long", 1);
	  set("exits", ([ /* 3 element(s) */
	"east" : __DIR__"map_15_6",
	"north" : __DIR__"map_14_5",
	"south" : __DIR__"map_16_5",
]));
	  set("outdoors", "land");
        set("objects",([
                __DIR__"npc/police":1,
        ]));

	setup();
	  replace_program(ROOM);
}
