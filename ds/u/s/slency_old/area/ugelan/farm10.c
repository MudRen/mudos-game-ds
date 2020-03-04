// Room: /u/s/slency/area/ugelan/farm10.c

inherit ROOM;

void create()
{
	set("short", "空房間");
	set("long", @LONG
這是一間什麼也沒有的空房間。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"farm11",
  "west" : __DIR__"farm9",
]));
	set("no_clean_up", 0);
	set("outdoors", "land");

	setup();
	replace_program(ROOM);
}
