// Room: /u/m/matlab/area/r2-2.c

inherit ROOM;

void create()
{
	set("short", "黑暗迴廊");
	set("long", @LONG
四周一片死寂，走道上隨目可見暗紅的血漬鑲嵌在斑駁的石柱上
血腥味更加刺鼻了!!!!
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"r2.c",
  "northwest" : __DIR__"r2-2nw.c",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
