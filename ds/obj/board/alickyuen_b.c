#include <ansi.h>
inherit BULLETIN_BOARD;
void create()
{
	set_name(HIR"Release Board "HIY"[Final Version]"NOR, ({ "board" }) );
        set("location","/u/a/alickyuen/workroom.c");
        set("board_id", "alickyuen_b");
        set("long",
        "這是一塊用軟木做的留言板 你忍不住想要在上面留下你的建議。\n");
        setup();
	set("capacity", 500);
        replace_program(BULLETIN_BOARD);
}
