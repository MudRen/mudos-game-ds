// Room: /u/s/slency/area/ugelan/secretwood3.c

inherit ROOM;

void create()
{
	set("short", "空房間");
	set("long", @LONG
這是一間什麼也沒有的空房間。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"secretwood2",
]));
	set("no_clean_up", 0);
	set("outdoors", "forest");
	setup();
	replace_program(ROOM);
}
