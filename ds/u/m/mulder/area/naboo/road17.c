// Room: /u/s/sonicct/area/road17.c

inherit ROOM;

void create()
{
	set("short", "市集入口");
	set("long", @LONG
這是Naboo城的市集，這裡的小販不斷向你賣他們的產品，但
是由於這裡太多人，你不能清楚看見他們賣什麼東西。你只好慢慢
向前走。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"shop7",
  "west" : __DIR__"road5",
]));
	set("outdoors","road");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
