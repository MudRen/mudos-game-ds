// File: /d/mist_forest/map_11_17.c
// Updated by tmr (Thu May 16 20:12:38 2002)

inherit ROOM;

void create()
{
	  set("short", "�g��");
	  set("long", @LONG

LONG
	  );
	  set("map_long", 1);
	  set("exits", ([ /* 2 element(s) */
	"south" : __DIR__"map_12_17",
	"north" : __DIR__"map_1_1",
]));
	  set("outdoors", "forest");
        set("objects",([
                __DIR__"npc/evil-monster":1,
        ]));

	setup();
	  replace_program(ROOM);
}
