// Room: /u/s/superbug/train/a-24.c

inherit ROOM;

void create()
{
	set("short", "廉價服飾店");
	set("long", @LONG
這是一間以賣廉價服飾出名的店，貧民區裡大部分的人都是到這裡來
買衣服，由於年代久遠，本來的店名已經被逐漸遺忘，慢慢的大家都習慣
以「廉價」來稱呼它。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"a-10.c",
]));
set("objects", ([
__DIR__"npc/seller3.c" : 1,
]));
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
