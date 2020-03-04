// File: /d/down_cave/down_maze2.c
// Updated by tmr (Mon Aug 18 02:28:39 2003)

inherit ROOM;

void create()
{
	  set("short", "空洞穴");
	  set("long", @LONG
你正在一個空空如也的洞穴中，四周黑漆漆的，看的不是很清楚。
LONG
	  );
	  set("exits", ([ /* 3 element(s) */
	"east" : __DIR__"down_maze5",
	"west" : __DIR__"down_maze1.c",
	"north" : __DIR__"down_maze4",
]));

	setup();
	  replace_program(ROOM);
}
