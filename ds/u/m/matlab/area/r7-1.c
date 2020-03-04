// Room: /u/m/matlab/area/r7-1.c

inherit ROOM;

void create()
{
	set("short", "落星殿");
	set("long", @LONG
這是一間什麼也沒有的空房間。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"r8.c",
  "southwest" : __DIR__"r6.c",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
