// Room: /u/d/donhow/area/a4.c

inherit ROOM;

void create()
{
	set("short", "空房間");
	set("long", @LONG
這是一間什麼也沒有的空房間。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"a9",
  "west" : __DIR__"a3",
  "east" : __DIR__"a5",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
