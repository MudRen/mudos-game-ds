// File: /d/mist_forest/map_14_7.c
// Updated by tmr (Thu May 16 20:09:19 2002)

inherit ROOM;

void create()
{
	  set("short", "�g���˪L-�p�|");
	  set("long", @LONG

LONG
	  );
	  set("map_long", 1);
	  set("exits", ([ /* 2 element(s) */
	"southeast" : __DIR__"map_15_8",
	"north" : __DIR__"map_13_7",
]));
	  set("outdoors", "forest");
        set("objects",([
                __DIR__"npc/evil-monster":1,
        ]));

	setup();
	  replace_program(ROOM);
}
