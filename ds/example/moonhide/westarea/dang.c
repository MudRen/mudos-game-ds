#include <ansi.h>
inherit NPC;

void create()
{
  set_name(HIG"電"HIW"魂", ({"dang soul"}) );
  set("long",@LONG
九天雲魂的新進成員。
LONG
);
  set("race", "human");
  set("unit","隻"); 
  set("title",HIR"九天雲魂");    set("age",230);
  set("level",28);
  setup();
  add_money("coin",200);
}

