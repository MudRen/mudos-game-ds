// Room: /u/m/mulder/area/shop6.c

inherit ROOM;

void create()
{
	set("short", "新彼得城 - 小巷");
	set("long", @LONG
這是一間什麼也沒有的空房間。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"road8",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
