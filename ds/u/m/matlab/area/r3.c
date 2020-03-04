// Room: /u/m/matlab/area/r3.c

inherit ROOM;

void create()
{
	set("short", "黑暗迴廊");
	set("long", @LONG
四周一片死寂，走道上隨目可見暗紅的血漬鑲嵌在斑駁的石柱上
血腥味更加刺鼻了!!!!北方的路似被阻斷了，但岩壁顯得十分光滑令
你好奇心頓起。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"r4.c",
  "west" : __DIR__"r2-2nwnnne.c",
  "east" : __DIR__"r2-1nennnw.c",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
