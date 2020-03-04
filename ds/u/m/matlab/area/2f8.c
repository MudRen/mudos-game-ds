// Room: /u/m/matlab/area/2f8.c

inherit ROOM;

void create()
{
	set("short", "空房間");
	set("long", @LONG
這是一間什麼也沒有的空房間。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"2f9.c",
  "west" : __DIR__"2f7.c",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
