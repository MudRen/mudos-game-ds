// File: /d/duli_forest/map_17_14.c
// Updated by tmr (Mon Mar 11 02:37:01 2002)

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
	  set("exits", ([ /* 3 element(s) */
	"east" : __DIR__"map_17_15",
	"west" : __DIR__"map_17_13",
	"north" : __DIR__"map_16_14",
]));

	setup();
	  replace_program(ROOM);
}
