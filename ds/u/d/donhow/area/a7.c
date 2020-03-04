// Room: /u/d/donhow/area/a7.c

inherit ROOM;

void create()
{
	set("short", "空房間");
	set("long", @LONG
這是一間什麼也沒有的空房間。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"a2",
  "west" : __DIR__"a6",
  "east" : __DIR__"a8",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
