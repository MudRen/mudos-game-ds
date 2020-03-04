// Room: /u/d/donhow/area/c1.c

inherit ROOM;

void create()
{
	set("short", "空房間");
	set("long", @LONG
這是一間什麼也沒有的空房間。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"c3",
  "down" : __DIR__"b10",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
