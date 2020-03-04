// File: /d/mist_forest/map_14_11.c
// Updated by tmr (Thu May 16 20:08:33 2002)

inherit ROOM;

void create()
{
	  set("short", "�g���˪L-�p�|");
	  set("long", @LONG

LONG
	  );
	  set("map_long", 1);
	  set("exits", ([ /* 2 element(s) */
	"north" : __DIR__"map_13_11",
	"southwest" : __DIR__"map_15_10",
]));
	  set("outdoors", "forest");
        set("objects",([
                __DIR__"npc/evil-monster":1,
        ]));

	setup();
	  replace_program(ROOM);
}
