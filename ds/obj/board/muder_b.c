#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
  set_name(HIR"留言板"NOR, ({ "muder's board" }) );
  set("location", "/u/m/muder/workroom");
  set("board_id", "muder_b");
  set("long","如果大家對小弟我有啥建議和要求的請留言在此版中。\n" );
  setup();
  set("capacity",100);
  set("master",({ "muder" }));
}

