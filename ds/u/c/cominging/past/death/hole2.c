// Room: /u/c/cominging/past/death/hole2.c

inherit ROOM;

void create()
{
	set("short", "黑暗的小洞窟");
	set("long", @LONG
這是一間什麼也沒有的空房間。
LONG
	);
	set("current_light", 2);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"island8",
]));
	set("world", "undefine");

	setup();
	replace_program(ROOM);
}
