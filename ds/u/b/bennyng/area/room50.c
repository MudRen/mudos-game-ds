// Room: /u/b/bennyng/area/room50.c

inherit ROOM;

void create()
{
	set("short", "射手宮外");
	set("long", @LONG
這就是射手宮後的花園，四處荒蕪一片，這裡一直沒有人打理．很奇
怪耶！！為什麼會這樣？？相信這個迷連巫師們都不知道，因為連我黑瞳
都不知道呀！！嘻嘻！！
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"room49",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
