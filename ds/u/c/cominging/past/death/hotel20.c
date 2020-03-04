// Room: /u/c/cominging/past/death/hotel20.c

inherit ROOM;

void create()
{
	set("short", "空房間");
	set("long", @LONG
這是一間什麼也沒有的空房間。
LONG
	);
	set("current_light", 1);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"hotel19",
  "west" : __DIR__"hotel21",
]));
	set("world", "undefine");

	setup();
	replace_program(ROOM);
}
