#include <ansi.h>

inherit BULLETIN_BOARD;

void create()
{
    set_name(HIC+"�H�ƺ޲z�B�d����"+NOR,({"personnel board","board"}));
    set("location","/d/wiz/personnel");
    set("board_id","personnel_b");
    set("long","�o�ӬO�H�ƺ޲z�B�d�����C\n");
	setup();
	set("capacity",150);

}
