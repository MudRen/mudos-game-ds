#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
    set_name(HIC+"���˷��F�d����"+NOR,({"frank board","board"}));
    set("location","/u/f/frank/workroom");
    set("board_id","frank_b");
    set("long","�o�ӬO���˷��F�d�����C\n");
        setup();
        set("capacity",100);;
	set("master", ({"frank"}));

}
