#include <ansi.h>
inherit BULLETIN_BOARD;
void create()
{
  set_name(HIW"電子佈告欄"NOR, ({ "board","online_b" }) );
  set("location", "/u/f/fedex/workroom");
  set("board_id", "fedex_b");
  set("long","這是一個掛在牆上的大型液晶螢幕．\n" );
  setup();
  set("capacity",100);
  set("master",({ "fedex" }));
}

