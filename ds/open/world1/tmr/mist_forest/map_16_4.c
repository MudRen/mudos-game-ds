// File: /d/mist_forest/map_16_4.c
// Updated by tmr (Thu May 16 21:22:35 2002)

inherit ROOM;

void create()
{
	  set("short", "�g���˪L-�p�|");
	  set("long", @LONG

LONG
	  );
	  set("map_long", 1);
	  set("exits", ([ /* 2 element(s) */
	"east" : __DIR__"map_16_5",
	"northwest" : __DIR__"map_15_3",
]));
	  set("outdoors", "forest");
        set("objects",([
                __DIR__"npc/evil-monster":1,
        ]));

	setup();
	  replace_program(ROOM);
}
