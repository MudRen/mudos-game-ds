#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
        set_name(HIC"Promise's Board"NOR,({"promise's board","board"}));
          set("location","/u/p/promise/workroom");
        set("board_id", "prmose_b");
        set("long",
        "[36m紀錄一些大小事情的書。[0m\n");
        setup();
        set("capacity",100);
  set("master",({ "promise"}));
 
}

