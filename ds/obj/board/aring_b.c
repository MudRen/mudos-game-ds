#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
    set_name(HIC"劍"NOR+CYN"林碑"NOR,({"aring's board","board"}));
    set("location","/u/a/aring/workroom");
    set("board_id", "aring_b");
    set("master",({"acme"}) );
    set("long",
      "[36m紀錄一些大小事情的書。[0m\n");
    setup();
    set("capacity",100);

}



