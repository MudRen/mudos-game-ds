// Room: /u/f/fanny/area/town3.c

inherit ROOM;

void create()
{
	set("short", "袁家村");
	set("long", @LONG
這是一間什麼也沒有的空房間。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"town2",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
