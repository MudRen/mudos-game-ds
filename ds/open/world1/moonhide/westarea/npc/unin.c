#include <ansi.h>
inherit NPC;

void create()
{
  set_name(HIC"元魂"NOR, ({"unin soul", "soul"}) );
  set("long",@LONG
九天雲魂的菜鳥。
LONG
);
        set("attitude", "aggressive");
  set("race", "human");
  set("unit","隻"); 
  set("title",HIR"九天雲魂"NOR);
  set("age",230);
  set("level",26);
  setup();
	set_living_name("westwar");
}

