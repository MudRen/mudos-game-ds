#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
        set_name(HIC"發呆記錄器"NOR,({"idle board","board"}));
          set("location","/u/i/idle/workroom");
        set("board_id", "idle_b");
        set("long",
        HIC"紀錄發呆時間的計費器。\n"NOR);
        setup();
        set("capacity",100);
  set("master",({ "idle"}));

}
