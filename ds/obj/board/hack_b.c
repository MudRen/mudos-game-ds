#include <ansi.h>
inherit BULLETIN_BOARD;
void create()
{
    set_name("駭客留言板",({"board"}));
    set("location","/u/h/hack/workroom.c");
    set("board_id", "hack_b");
    set("long","這是一塊用龍蝦做的留言板。\n");
set("master","hack");
	setup();
    set("capacity",50);
replace_program(BULLETIN_BOARD);
}
