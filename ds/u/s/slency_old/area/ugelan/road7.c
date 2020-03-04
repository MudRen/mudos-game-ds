// Room: /u/s/slency/area/ugelan/road7.c

inherit ROOM;

void create()
{
	set("short", "青石街道");
	set("long", @LONG
這裡是一條人潮洶湧的街道，旁邊有一家當鋪，專收旅客們不要或
在旅程上所收集的奇珍異品，假如你身上有許多寶物，不如去那裡賣, 
說不定也有一筆可觀的收入，你也可以以較高的價錢在那裡收購一些難
得的寶物，往東便是那間當鋪，往北可以看見一間教堂。
LONG
	);
	set("outdoors", "land");
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"sell",
  "north" : __DIR__"road16",
  "south" : __DIR__"road17",
]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
