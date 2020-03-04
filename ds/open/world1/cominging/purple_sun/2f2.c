// 紫陽山第二層

inherit ROOM;

void create()
{
	set("short", "紫陽山");
	set("long", @LONG
這裡是紫陽山的小路上較南邊的地方，你還可以隱約看到滄縣熱鬧
的情形，那街路上人潮的樣子，往東是往上爬到山頂，而往西則是往山
下走去。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"2f3.c",
  "northwest" : __DIR__"2f1.c",
]));
	set("objects", ([
  __DIR__"npc/tiger" : 1,
]));
	set("world", "past");
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}
