#include <ansi.h>
inherit NPC;

void create()
{
  set_name(HIC"電魂"NOR, ({"dang soul", "soul"}) );
  set("long",@LONG
九天雲魂的新進成員。
LONG
);
  set("race", "human");
        set("attitude", "aggressive");
  set("unit","隻"); 
  set("title",HIR"九天雲魂"NOR);    
  set("age",230);
  set("level",28);
  setup();
set_living_name("westwar");
}

