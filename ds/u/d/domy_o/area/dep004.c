// Room: /u/d/domy/area/dep004.c

inherit ROOM;

void create()
{
	set("short", "一樓");
	set("long", @LONG
這是一間什麼也沒有的空房間。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"dep003",
  "south" : __DIR__"dep001",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
