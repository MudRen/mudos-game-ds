// File: /d/mist_forest/map_5_13.c
// Updated by tmr (Thu May 16 20:04:56 2002)

inherit ROOM;

void create()
{
	  set("short", "�g���˪L-�p�|");
	  set("long", @LONG

LONG
	  );
	  set("map_long", 1);
	  set("exits", ([ /* 4 element(s) */
	"southeast" : __DIR__"map_6_14",
	"northeast" : __DIR__"map_4_14",
	"southwest" : __DIR__"map_6_12",
	"northwest" : __DIR__"map_4_12",
]));
	  set("outdoors", "forest");
        set("objects",([
                __DIR__"npc/evil-monster":3,
        ]));


	setup();
	  replace_program(ROOM);
}
