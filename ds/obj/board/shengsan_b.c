#include <ansi.h>

inherit BULLETIN_BOARD;

void create()
{
    set_name(HIC+"���Ū��ѯd����"+NOR,({"shengsan board","board"}));
    set("location","/u/s/shengsan/workroom");
    set("board_id","shengsan_b");
    set("long","�o�ӬO���Ū��ѯd�����C\n");
	setup();
	set("capacity",150);

}
