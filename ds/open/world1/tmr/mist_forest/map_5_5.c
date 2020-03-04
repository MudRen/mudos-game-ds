// File: /d/mist_forest/map_5_5.c
// Updated by tmr (Thu May 16 20:01:24 2002)

inherit ROOM;

void create()
{
	  set("short", "�g���˪L-�p�|");
	  set("long", @LONG

LONG
	  );
	  set("map_long", 1);
	  set("exits", ([ /* 4 element(s) */
	"southeast" : __DIR__"map_6_6",
	"northeast" : __DIR__"map_4_6",
	"southwest" : __DIR__"map_6_4",
	"northwest" : __DIR__"map_4_4",
]));
        set("objects",([
                __DIR__"npc/evil-monster":3,
        ]));

	  set("outdoors", "forest");

	setup();
	  replace_program(ROOM);
}
