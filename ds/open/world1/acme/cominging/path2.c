inherit ROOM;

void create()
{
	set("short", "走道");
	set("long", @LONG
這裡是走道的中間，在你的頂上，就是藍藍的天空了，不知道為什
麼，這裡竟然建成這個樣子，不知道是什麼原因，守衛不停的在走道上
徘徊，不停的巡邏。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"path8",
  "west" : __DIR__"path5",
  "north" : __DIR__"path3",
  "south" : __DIR__"path1",
]));
	set("objects",([
  __DIR__"npc/guard" : 4,
]));
	set("light",1);
	setup();
	replace_program(ROOM);
}
