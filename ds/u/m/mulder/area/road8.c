// Room: /u/m/mulder/area/road8.c

inherit ROOM;

void create()
{
	set("short", "新彼得城 - 廣場大街");
	set("long", @LONG
這是一條直的大道，你可看到周圍的境色會隨時起變化，你
覺得真是十分神奇啊．但你又想我會不會象這境色隨時起變化呢
?希望各位能在這�堜w下一個目標前進．
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
"south" : __DIR__"chatroom",
  "west" : __DIR__"road7",
  "east" : __DIR__"road9",
]));
	set("新彼得城", "- 新彼得大道");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
