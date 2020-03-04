// File: /d/duli_forest/map_12_9.c
// Updated by tmr (Mon Mar 11 02:37:24 2002)

inherit ROOM;

void create()
{
	  set("short", "小路");
	  set("long", @LONG
在四周黃沙漫漫的沙原上，有幾處特別高的小山丘，隨著風起而崩解。
LONG
	  );
	  set("outdoors", "land");
	  set("map_long", 1);
	  set("objects", ([ /* 2 element(s) */
	__DIR__"npc/song-zhong" : 1,
	__DIR__"npc/bandit" : 4,
]));
	  set("exits", ([ /* 4 element(s) */
	"east" : __DIR__"map_12_10",
	"south" : __DIR__"map_13_9",
	"west" : __DIR__"map_12_8",
	"north" : __DIR__"map_11_9",
]));

	setup();
	  replace_program(ROOM);
}
