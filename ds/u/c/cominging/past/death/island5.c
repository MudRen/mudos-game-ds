// Room: /u/c/cominging/past/death/island5.c

inherit ROOM;

void create()
{
	set("short", "洞窟前");
	set("long", @LONG
這是一間什麼也沒有的空房間。
LONG
	);
	set("current_light", 2);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "enter" : __DIR__"hole1",
  "north" : __DIR__"island6",
  "west" : __DIR__"island4",
]));
	set("world", "undefine");

	setup();
	replace_program(ROOM);
}
