#include <ansi.h>
inherit BULLETIN_BOARD;
void create()
{
        set_name("小琳的留言板",({"board"}));
        set("location","u/c/cutekelly/workroom.c");
        set("board_id", "cutekelly_b");
        set("long",
        "有什麼話就大聲的給他寫進去吧∼∼。\n");
        setup();
        set("capacity",100);
        replace_program(BULLETIN_BOARD);
}
