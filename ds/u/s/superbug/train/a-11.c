// Room: /u/s/superbug/train/a-11.c

inherit ROOM;

void create()
{
	set("short", "貧民區[西街]");
	set("long", @LONG
這裡是貧民區的西街，這裡仍充滿著令你感到嘔心的氣味，在你的南
方是一間小小的速食店，門口放著幾張桌子和椅子，看起來似乎生意不錯
的樣子，有一群人在閒聊，往東可以前往市中心。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"a-12.c",
  "south" : __DIR__"a-25.c",
  "east" : __DIR__"a-10.c",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
