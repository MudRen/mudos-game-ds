#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
  set_name(CYN"藤板"NOR, ({ "board" }) );
  set("location", "/u/s/sasa/workroom");
  set("board_id", "sasa_board");
  set("long","這是一面用來交換訊息的板子。\n" );
  setup();
  set("capacity", 60);
}

