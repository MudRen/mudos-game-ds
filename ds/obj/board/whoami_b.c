#include <ansi.h>
inherit BULLETIN_BOARD;
void create()
{
        set_name("我是誰留言版",({"whoami board", "board"}));
        set("location","/u/w/whoami/workroom.c");
        set("board_id", "whoami_b");
        set("long",
        "一張大的木板留言版，上面有個哲學中最深奧的問題：「Who am I？」。\n");
        setup();
          set("capacity",500);
      set("master", ({"whoami"}) );

}

