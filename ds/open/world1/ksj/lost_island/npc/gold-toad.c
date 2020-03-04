#include <ansi.h>
inherit NPC;

void create()
{
  set_name(HIY"三足啣金蟾"NOR, ({"gold toad","toad"}) );
  set("long",@LONG
一隻三隻腳啣著金錢的蟾蜍，聽說會招來錢財。
LONG);
  set("race", "beast");
  set("gender", "雄性");
  set("unit","隻");
  set("age",7);
  set("level",22+random(2));
  set("title",HIW"  奇獸 "NOR);
  set("limbs", ({ "頭部","身體","前腳","後腳" }) );
  set("verbs", ({"crash" }) );
  set("chat_chance", 10);
  set("chat_msg", ({
     (: random_move :),
  }));
  setup();
  add_money("coin", 10000);
}

void init()
{        
  ::init();
  switch( random(14) )
  {
    case 0:
         say(HIY"三足啣金蟾"NOR"跳進草叢間消失不見了。\n");
         destruct(this_object());
         break;
  }
} 
