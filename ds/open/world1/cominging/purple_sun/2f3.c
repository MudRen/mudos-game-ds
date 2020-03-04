// 紫陽山第二層

inherit ROOM;

void create()
{
	set("short", "紫陽山");
	set("long", @LONG
在你前面的是一堆堆的石頭，堆積在旁邊往上的路上，似乎最近常
有山崩的現象產生，要特別的小心一點，這裡往上的路上有點特別的陡
峭，一下起伏很大。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"3f1.c",
  "southwest" : __DIR__"2f2.c",
]));
	set("world", "past");
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}
