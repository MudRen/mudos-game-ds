// Room: /u/d/darkfool/area1/15.c

inherit ROOM;

void create()
{
	set("short", "北住宅區街道");
	set("long", @LONG
北住宅區的一個角落，沒有什麼特別的地方。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"14",
]));

	setup();
	replace_program(ROOM);
}
