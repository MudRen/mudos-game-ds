// Room: /u/m/matlab/area/2f3.c

inherit ROOM;

void create()
{
	set("short", "空房間");
	set("long", @LONG
這是一間什麼也沒有的空房間。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "northeast" : __DIR__"2f6.c",
  "south" : __DIR__"2f10.c",
  "north" : __DIR__"r2fstart.c",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
