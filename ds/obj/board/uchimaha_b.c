#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
  set_name(HIW+BLK"黑板"NOR, ({ "board" }) );
  set("location", "/u/u/uchimaha/workroom");
  set("board_id", "uchimaha_board");
  set("long","這是一面用來交換訊息的板子。\n" );
  setup();
  set("capacity", 100);
}

