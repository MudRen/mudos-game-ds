// File: /d/duli_forest/map_17_17.c
// Updated by tmr (Mon Mar 11 02:37:08 2002)

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
	  set("exits", ([ /* 2 element(s) */
	"west" : __DIR__"map_17_16",
	"north" : __DIR__"map_16_17",
]));

	setup();
	  replace_program(ROOM);
}
