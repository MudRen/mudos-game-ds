#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
  set_name(HIW"�P���Ȫe"NOR, ({ "board","wd_board" }) );
  set("location", "/u/w/wilfred/workroom");
  set("board_id", "WD_board");
  set("long","�mø�P�šC\n" );
  setup();
  set("capacity", 50);
  set("master",({ "wilfred" }));
}
