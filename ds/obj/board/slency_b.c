#include <ansi.h>
inherit BULLETIN_BOARD;
void create()
{
	set_name(GRN"思溪留言板"NOR,({"slency's board","board"}));
        set("location","/u/s/slency/workroom.c");
        set("board_id", "slency_b");
        set("long",
        "這是一塊用喬木所製成的留言版, 高水準的你當然要在這高水準的留言版上留言。\n");
        setup();
        set("capacity",100);

}

