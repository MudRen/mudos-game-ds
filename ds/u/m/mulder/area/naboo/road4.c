// Room: /u/s/sonicct/area/road4.c

inherit ROOM;

void create()
{
	set("short", "Naboo城街道");
	set("long", @LONG
這裡的市民正在忙碌地工作，而你身旁突然走出了一個小孩
嚇得你花容失色，原來那個小孩正和其他小孩玩捉迷藏。突然，
有一輛飛船在你同頂飛過。這裡往北走可以到達皇宮大門。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"shop2",
  "west" : __DIR__"shop3",
  "north" : __DIR__"road5",
  "south" : __DIR__"middle",
]));
	set("outdoors","road");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
