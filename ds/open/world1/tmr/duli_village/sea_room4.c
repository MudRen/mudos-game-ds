// File: /d/duli_village/sea_room4.c
// Updated by tmr (Wed May  8 22:44:07 2002)

inherit ROOM;

void create()
{
	  set("short", "大海洋底下");
	  set("long", @LONG
你正潛游在一片水藍藍的海洋底下，你身處在這個寂靜的世界上，慢
慢地已經分不清東南西北了，微微波動的海流正輕拂過你的身軀。
LONG
	  );
	  set("exits", ([ /* 3 element(s) */
	"down" : __DIR__"sea_room5",
	"west" : __DIR__"sea_room6",
	"up" : __DIR__"map_6_2",
]));

	setup();
	  replace_program(ROOM);
}
