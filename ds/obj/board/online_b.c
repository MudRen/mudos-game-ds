#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
  set_name(HIG"戰術討論板"NOR, ({ "board","online_b" }) );
  set("location", "/open/world1/wilfred/club/dragon/online");
  set("board_id", "online_b");
  set("long","這是給連線戰友留言用的板子。\n" );
  setup();
  set("capacity",100);
  set("master",({ "wilfred" }));
}

