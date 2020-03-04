// Room: /u/m/matlab/area/r2-1nennnw.c

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
  "southeast" : __DIR__"r2-1nenn.c",
  "west" : __DIR__"r3.c",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
