#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
  set_name(HIW"�B��"NOR, ({ "ice Board","board" }) );
  set("location", "/u/k/kula/workroom");
  set("board_id", "kula_board");
  setup();
  set("capacity", 50);
  set("master",({ "kula" }));
}

