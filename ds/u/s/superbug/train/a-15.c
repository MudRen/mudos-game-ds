// Room: /u/s/superbug/train/a-15.c

inherit ROOM;

void create()
{
	set("short", "貧民區[南街]");
	set("long", @LONG
這裡是貧民區的南街，這裡仍充滿著令你感到嘔心的氣味，在你的東
方有間櫥窗掛滿防具的防具店，招牌上寫著大大的「絕世」兩個字，看起
來似乎有一點令你感到心動，往北可以前往市中心。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"a-14.c",
  "south" : __DIR__"a-16.c",
  "east" : __DIR__"a-20.c",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
