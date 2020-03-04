// Room: /u/s/superbug/train/a-23.c

inherit ROOM;

void create()
{
	set("short", "商店");
	set("long", @LONG
這裡是貧民區唯一的一間收受舊貨的店，牆邊堆滿了堆積如山的貨品，如
果你有什麼貨品要賣的話，都可以拿到這裡來出售，貧民區大部分的貨品都是
在這裡出售的。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"a-7.c",
]));
set("objects", ([
__DIR__"npc/seller2.c" : 1,
]));
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
