// Room: /u/m/mulder/area/road15.c

inherit ROOM;

void create()
{
	set("short", "訓練所");
	set("long", @LONG
這是給新手的訓練所，如你是老玩家的話．請而玉步吧，到
另一邊．這�娷\設簡單以免讓你分心．
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"road10",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
