// Room: /u/s/sevil/1f/5.c

inherit ROOM;

void create()
{
	set("short", "安全門");
	set("long", @LONG
這是一間什麼也沒有的空房間。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"10.c",
  "west" : __DIR__"26.c",
  "east" : __DIR__"4.c",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
