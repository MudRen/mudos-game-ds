// File: /d/down_cave/down_maze6.c
// Updated by tmr (Mon Aug 18 02:30:10 2003)

inherit ROOM;

void create()
{
	  set("short", "空洞穴");
	  set("long", @LONG
你正在一個空空如也的洞穴中，四周黑漆漆的，看的不是很清楚。
LONG
	  );
	  set("exits", ([ /* 4 element(s) */
	"south" : __DIR__"down_maze3",
	"east" : __DIR__"down_maze7",
	"west" : __DIR__"down_maze3",
	"north" : __DIR__"down_maze3",
]));

	setup();
	  replace_program(ROOM);
}
