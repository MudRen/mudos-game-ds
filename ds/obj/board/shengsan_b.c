#include <ansi.h>

inherit BULLETIN_BOARD;

void create()
{
    set_name(HIC+"藍藍的天留言版"+NOR,({"shengsan board","board"}));
    set("location","/u/s/shengsan/workroom");
    set("board_id","shengsan_b");
    set("long","這個是藍藍的天留言版。\n");
	setup();
	set("capacity",150);

}
