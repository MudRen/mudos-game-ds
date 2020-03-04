inherit ROOM;

void create()
{
	set("short", "小倉庫");
	set("long", @LONG
這裡是瀧堆放東西的地方。這些東西很可能有失敗的實驗品、測
試中的物品等等，所以這些東西有時候會發揮意想不到的效果。
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 1);
	set("exits", ([ /* sizeof() == 1 */
  		"out" : __DIR__"workroom",
	]));
	set("objects",([
		__DIR__"pill.c":1,
		__DIR__"lion.c":1,
	]));
	setup();
	replace_program(ROOM);
}
