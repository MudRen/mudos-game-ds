#include <ansi2.h>

inherit BULLETIN_BOARD;

void create()
{
        set_name(HIR"程式討論版 "HIY"[Java 2 Version]"NOR, ({ "board" }) );
	set("location", "/u/a/alickyuen/programming.c");
	set("board_id", "c++_b");
	set("long",
		"這塊是現時最先進的電子顯示版，記錄了很多有關程式寫作的資料。\n");
	setup();
	set("capacity", 500);
	replace_program(BULLETIN_BOARD);
}
