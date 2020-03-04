// Room: /u/d/donhow/area/a3.c

inherit ROOM;

void create()
{
	set("short", "空房間");
	set("long", @LONG
這是一間什麼也沒有的空房間。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"a8",
  "south" : "/u/d/donhow/workroom.c",
  "west" : __DIR__"a2",
  "east" : __DIR__"a4",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
