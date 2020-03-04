// Room: /u/d/domy/area/dep001.c

inherit ROOM;

void create()
{
	set("short", "一樓");
	set("long", @LONG
這是一間什麼也沒有的空房間。
LONG
	);
	set("world", "undefine");
	set("west", "dep002");
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"dep004",
  "west" : __DIR__"dep002",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
