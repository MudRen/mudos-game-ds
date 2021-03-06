// Room: /open/world1/tmr/xiangyang/eastroad2_n1.c

inherit ROOM;

void create()
{
	set("short", "東內大街");
	set("long", @LONG
這是一條青石鋪就的大街。西面是一堵蓋著紅色琉璃瓦的
高牆，裡面是襄陽守城大將王堅的府邸大院。北面是一個十字
街道，只見人來人往，非常熱鬧，南面是用青石鋪的街道。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"eastroad2",
  "north" : __DIR__"eastroad2_n2",
]));
	set("no_clean_up", 0);
	set("current_light", 2);
	set("outdoors", "xiangyang");

	setup();
	replace_program(ROOM);
}
