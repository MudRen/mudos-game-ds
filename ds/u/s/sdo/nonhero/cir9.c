inherit ROOM;

void create()
{
	set("short", "無相法環");
	set("long", @LONG
這裡一邊的牆上寫著大大的『無』字，而另一邊的牆上寫著：『
藥王佛十二願四願安立大乘：願我來世得菩提時，若諸有情行邪道者
，悉令安住菩薩道中；若行聲聞獨覺乘者，皆以大乘而安立之。』西
邊有一扇拱門，裡面好像有一尊雕像。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  		"northwest" : __DIR__"cir4",
  		"west" : __DIR__"cir8",
  		"south" : __DIR__"cir13",
	]));
	set("current_light", 0);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
