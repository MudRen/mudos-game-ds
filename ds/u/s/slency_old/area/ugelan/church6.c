// Room: /u/s/slency/area/ugelan/church6.c

inherit ROOM;

void create()
{
	set("short", "護城河畔小徑");
	set("long", @LONG
這裡是一條延著護城河河畔的小徑，處處可以看見許多旅客在此遊
玩，往河面對岸看去，圍繞在淡霧中的幽遮蘭皇宮，似乎充滿了神密的
感覺，如果有機會，還真想進宮去看一看呢！
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"church5",
  "north" : __DIR__"church7",
]));
	set("no_clean_up", 0);
	set("outdoors", "forest");

	setup();
	replace_program(ROOM);
}
