#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
  set_name(HIW"[MAGIC-BOARD]"NOR, ({ "board","magic-card_b" }) );
  set("location", "/open/world1/wilfred/magic-card/room1");
  set("board_id", "magic-card_b");
  set("long","這是給牌友留言用的板子。\n" );
  setup();
  set("capacity",30);
  set("master",({ "wilfred" }));
}

