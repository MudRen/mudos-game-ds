#include <ansi.h>

inherit BULLETIN_BOARD;



void create()

{

  set_name(HIM"漂漂"HIB"筆記本"NOR, ({ "board","basic notebook" }) );

  set("location", "/u/w/wilfred/workroom");

  set("board_id", "basic_notebook");

  set("long","可把意見記載在我的筆計簿裡讓我參考。\n" );


  setup();

  set("capacity", 50);
replace_program(BULLETIN_BOARD);

}
