// Room: /u/c/cominging/past/death/island8.c

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
	set("exits", ([ /* sizeof() == 5 */
  "enter" : __DIR__"hole2",
  "north" : __DIR__"island13",
  "west" : __DIR__"island9",
  "south" : __DIR__"island3",
  "east" : __DIR__"island7",
]));
	set("world", "undefine");

	setup();
	replace_program(ROOM);
}
