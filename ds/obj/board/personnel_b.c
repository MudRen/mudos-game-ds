#include <ansi.h>

inherit BULLETIN_BOARD;

void create()
{
    set_name(HIC+"人事管理處留言版"+NOR,({"personnel board","board"}));
    set("location","/d/wiz/personnel");
    set("board_id","personnel_b");
    set("long","這個是人事管理處留言版。\n");
	setup();
	set("capacity",150);

}
