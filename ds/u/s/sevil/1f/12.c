// Room: /u/s/sevil/1f/12.c

inherit ROOM;

void create()
{
	set("short", "寬廣的走道");
	set("long", @LONG
這是一間什麼也沒有的空房間。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"13.c",
  "north" : __DIR__"17.c",
  "south" : __DIR__"7.c",
  "east" : __DIR__"11.c",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
