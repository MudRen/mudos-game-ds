#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
    set_name(HIC+"敦親睦鄰留言版"+NOR,({"frank board","board"}));
    set("location","/u/f/frank/workroom");
    set("board_id","frank_b");
    set("long","這個是敦親睦鄰留言版。\n");
        setup();
        set("capacity",100);;
	set("master", ({"frank"}));

}
