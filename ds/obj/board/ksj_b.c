#include <ansi.h>
inherit BULLETIN_BOARD;
void create()
{
	set_name(HIW"ＫＳＪ之留言板"NOR, ({ "board" }));
	set("location", "/u/k/ksj/workroom");
	set("board_id", "ksj_b");
        set("long",
        "這是一塊用軟木做的留言板 你忍不住想要在上面留下你的建議。\n");
        setup();
        set("capacity",100);
        replace_program(BULLETIN_BOARD);
}
