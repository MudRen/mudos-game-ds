// Room: /u/s/superbug/train/a-2.c

inherit ROOM;

void create()
{
	set("short", "貧民區[北街]");
	set("long", @LONG
這裡是貧民區的北街，這裡仍充滿著令你感到嘔心的氣味，在你的西
方是一間ＰＵＢ，從裡面不時的傳出喧嘩的音樂，還有吵雜的吵鬧聲，往
南可以前往市中心。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"a-1.c",
  "north" : __DIR__"a-3.c",
  "west" : __DIR__"a-18.c",
]));
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
