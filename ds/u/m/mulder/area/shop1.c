// Room: /u/m/mulder/area/shop1.c

inherit ROOM;

void create()
{
	set("short", "新彼得城 - 街道");
	set("long", @LONG
在這�塈A看見一座設備很先進的大樓，原來這是新彼得城的
警察大樓．怪不得這麼威武！！
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"road6",
  "south" : __DIR__"road11",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
