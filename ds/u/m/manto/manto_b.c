#include <ansi.h>
inherit BULLETIN_BOARD;
void create()
{
    set_name("就是留言板",({"board"}));
    set("location","/u/m/manto/workroom.c");
    set("board_id", "manto_b");
    set("long","這是一塊用麵粉做的留言板。\n");
        setup();
    set("capacity",50);
     set("master","manto");
replace_program(BULLETIN_BOARD);
}


