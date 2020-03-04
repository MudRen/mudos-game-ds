// Room: /u/s/superbug/train/a-7.c

inherit ROOM;

void create()
{
	set("short", "貧民區[東街]");
	set("long", @LONG
這裡是貧民區的東街，這裡仍充滿著令你感到嘔心的氣味，在你的南
方是一間巨大的商店，門口還堆著許多的商品，也許你可以找到一些好東
西，往西可以通往市中心。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"a-6.c",
  "south" : __DIR__"a-23.c",
  "east" : __DIR__"a-8.c",
]));
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
