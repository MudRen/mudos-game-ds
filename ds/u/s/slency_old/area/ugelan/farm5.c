// Room: /u/s/slency/area/ugelan/farm5.c

inherit ROOM;

void create()
{
	set("short","城門外");
	set("long", "你來到了幽遮蘭城的城門外，高聳的城門就聳立在你的眼前，遠遠\n""地可以看到一些守城護衛站在城門口撿查著出入旅客的行李，因為這座\n""城是附近最大的一座城, 因此總是有很多痞子喜歡到城裡作亂，守城護\n""衛不得以只好時常撿查有什麼不法人士企圖闖入幽遮蘭城，由這裡往北\n""走就到城門了。
"
	);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"bigdoor",
  "south" : __DIR__"farm1",
  "west" : __DIR__"farm6",
  "east" : __DIR__"farm4",
]));
	set("no_clean_up", 0);
	set("outdoors", "land");
	setup();
	replace_program(ROOM);
}
