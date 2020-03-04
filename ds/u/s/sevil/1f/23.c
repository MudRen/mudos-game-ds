// Room: /u/s/sevil/1f/23.c

inherit ROOM;

void create()
{
	set("short", "空房間");
	set("long", @LONG
這是一間什麼也沒有的空房間。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"24.c",
  "south" : __DIR__"18.c",
  "east" : __DIR__"22.c",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
