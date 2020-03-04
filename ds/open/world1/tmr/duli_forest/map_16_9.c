// File: /d/duli_forest/map_16_9.c
// Updated by tmr (Mon Mar 11 02:34:58 2002)

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
	  set("objects", ([ /* 1 element(s) */
	__DIR__"npc/zi-tong" : 1,
]));
	  set("exits", ([ /* 2 element(s) */
	"south" : __DIR__"map_17_9",
	"north" : __DIR__"map_15_9",
]));

	setup();
	  replace_program(ROOM);
}
