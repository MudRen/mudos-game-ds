#include <ansi.h>
inherit BULLETIN_BOARD;
void create()
{
  set_name(" 神風留言板",({"board"}));
  set("location","/u/s/sonicct/workroom");
  set("board_id", "sonicct_b");
  set("long",
    "這是一塊留言板 你想在上面留下你的建議。\n");
  setup();
  set("capacity",100);

}
