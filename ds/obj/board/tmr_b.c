#include <ansi.h>
inherit BULLETIN_BOARD;
void create()
{
        set_name("有面留言版",({"board"}));
        set("location","/u/t/tmr/room/square.c");
        set("board_id", "tmr_b");
        set("long",
        "一張破舊的大木板，如你想在上面留言，倒也勉強可行。\n");
        setup();
          set("capacity",1000);
      set("master", ({"tmr"}) );

}

