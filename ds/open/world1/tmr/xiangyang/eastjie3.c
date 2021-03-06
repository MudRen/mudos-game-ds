// Room: /open/world1/tmr/xiangyang/eastjie3.c

inherit ROOM;

void create()
{
	set("short", "東大街");
	set("long", @LONG
這是一條寬闊的青石街道，向東西兩頭延伸。東面是青龍
內門，南邊是木匠鋪，鋸木聲、刨木聲聲聲入耳。北面是襄陽
城的東兵營，隱隱能聽見裡面傳來宋兵的操練聲。西邊是一個
十字街口，只見人來人往、絡繹不絕。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"eastjie2_e1",
  "south" : __DIR__"mujiang",
  "east" : __DIR__"eastgate1",
  "north" : __DIR__"bingying2",
]));
	set("coor", ([ /* sizeof() == 3 */
  "y" : -510,
  "x" : -470,
  "z" : 0,
]));
	set("current_light", 1);
	set("no_clean_up", 0);
	set("outdoors", "xiangyang");

	setup();
	replace_program(ROOM);
}
