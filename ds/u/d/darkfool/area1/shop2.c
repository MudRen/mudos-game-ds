// Room: /u/d/darkfool/area1/shop2.c

inherit ROOM;

void create()
{
	set("short", "採礦用品店");
	set("long", @LONG
這是一間什麼也沒有的空房間。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"s3",
]));

	setup();
	replace_program(ROOM);
}
