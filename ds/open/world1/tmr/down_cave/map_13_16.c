// File: /d/down_cave/map_13_16.c
// Updated by tmr (Mon Aug 18 02:34:05 2003)

inherit ROOM;

void create()
{
	  set("short", "�w�����`��");
	  set("long", @LONG

LONG
	  );
	  set("exits", ([ /* 1 element(s) */
	"west" : __DIR__"map_13_15",
]));
	  set("map_long", 1);
        set("objects",([
                __DIR__"npc/song-tian-wang" : 1,
        ]) );

	setup();
	  replace_program(ROOM);
}
