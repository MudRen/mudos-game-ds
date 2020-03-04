inherit ROOM;

void create()
{
	set("short", "民房");
	set("long", @LONG
你一走進這間民房，就發現這間民房跟別間有很大的不同，那就
是牆壁四周都是書櫃，書櫃上滿滿的都是書本，數量之多，簡直可以
媲美小型的讀書館。中央有一張大桌子，桌子上有許多被打開的書零
亂的攤在那，可見主人非常的勤於閱讀。你又仔細的看看了書櫃上的
書，發現不但有一般的通用語言，還有用魔法語言寫成的稀有魔法書
和幾本你根本看不懂得文字寫成的書籍。
LONG
	);
	set("current_light", 1);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  		"west" : __DIR__"burg2",
	]));
	set("objects",([
		__DIR__"npc/jialermi.c":1,
	]));

	setup();
	replace_program(ROOM);
}
