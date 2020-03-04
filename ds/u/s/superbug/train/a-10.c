// Room: /u/s/superbug/train/a-10.c

inherit ROOM;

void create()
{
	set("short", "貧民區[西街]");
	set("long", @LONG
這裡是貧民區的西街，這裡仍充滿著令你感到嘔心的氣味，在你的北
方似乎是一間服飾店，從門口望進去似乎堆積著許多的衣服，門上還貼著
一張寫著「廉價出售」的紅單子，往東可以前往市中心。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"a-11.c",
  "north" : __DIR__"a-24.c",
  "east" : __DIR__"a-9.c",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
