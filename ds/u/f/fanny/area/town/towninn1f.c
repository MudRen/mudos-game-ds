// Room: /u/f/fanny/area/towninn1f.c

inherit ROOM;

void create()
{
	set("short", "留步客棧");
	set("long", @LONG
這是一間什麼也沒有的空房間。
LONG
	);
	set("world", "undefine");
	set("shoet", "留步客棧");
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"town2",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
