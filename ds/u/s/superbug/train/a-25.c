// Room: /u/s/superbug/train/a-25.c

inherit ROOM;

void create()
{
	set("short", "傑特速食屋");
	set("long", @LONG
這裡是一間販賣食物的店，大部分的人休閒時都會來這裡吃些東西，
順便聊聊天，慢慢的這裡變成整個貧民區人民聚集的地方，也是小道消息
最流通的地方。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"a-11.c",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
