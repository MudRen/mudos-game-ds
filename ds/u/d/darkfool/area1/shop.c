// Room: /u/d/darkfool/area1/shop.c

inherit ROOM;

void create()
{
	set("short", "商店");
	set("long", @LONG
這是一間什麼也沒有的空房間。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"4",
]));

	setup();
	replace_program(ROOM);
}
