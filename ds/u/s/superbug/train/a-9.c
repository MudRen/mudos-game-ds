// Room: /u/s/superbug/train/a-9.c

inherit ROOM;

void create()
{
	set("short", "貧民區[西街]");
	set("long", @LONG
這裡是貧民區的西街，這裡仍充滿著令你感到嘔心的氣味，你只想要
趕快的離開這裡，在牆角還躺著幾個流浪漢在看著你，似乎希望你捐獻點
什麼給他們，往東可以前往市中心。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"a-10.c",
  "east" : __DIR__"8.c",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
