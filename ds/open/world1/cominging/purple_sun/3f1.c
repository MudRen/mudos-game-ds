// 紫陽山第三層

inherit ROOM;

void create()
{
	set("short", "紫陽山");
	set("long", @LONG
呼∼呼∼呼∼，你終於從陡坡爬了上來，這裡的地勢又顯得較為高
了許多，俯視走過的路，突然好像小了多，你越爬越高，不知道會不會
一不小心跌了下去。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"3f2.c",
  "down" : __DIR__"2f3.c",
]));
	set("world", "past");
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}
