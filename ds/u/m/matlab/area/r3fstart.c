// Room: /u/m/matlab/area/r3fstart.c

inherit ROOM;

void create()
{
	set("short", "焚天閣3樓");
	set("long", @LONG
這是一間什麼也沒有的空房間。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"2fto3f.c",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
