// Room: /u/c/cominging/past/death/island2.c

inherit ROOM;

void create()
{
	set("short", "小島上");
	set("long", @LONG
這是一間什麼也沒有的空房間。
LONG
	);
	set("current_light", 2);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"island9",
  "east" : __DIR__"island3",
]));
	set("world", "undefine");

	setup();
	replace_program(ROOM);
}
