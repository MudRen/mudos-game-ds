// File: /d/duli_forest/map_17_4.c
// Updated by tmr (Mon Mar 11 02:35:22 2002)

inherit ROOM;

void create()
{
	  set("short", "小路");
	  set("long", @LONG
一片黃沙飛揚，路過的旅客眼睛都被風沙遮蓋住，難以睜開。
LONG
	  );
	  set("outdoors", "land");
	  set("map_long", 1);
	  set("exits", ([ /* 3 element(s) */
	"east" : __DIR__"map_17_5",
	"west" : __DIR__"map_17_3",
	"north" : __DIR__"map_16_4",
]));

	setup();
	  replace_program(ROOM);
}
