#include <ansi.h>
inherit NPC;

void create()
{
  set_name(HIC"水紋鹿"NOR, ({"water deer","deer"}) );
  set("long",@LONG
一隻全身湛藍的麋鹿，牠身上的毛皮如水光般波動，可以反射周圍的
事物，讓敵人無法辨認出自己。
LONG
);
  set("race", "beast");
  set("unit","隻");
  set("age",15);
  set("gender", "雄性" );
  set("dex",65);
  set("level",32+random(4));
  set("title",HIW"  奇獸 "NOR);
  set("limbs", ({ "頭部", "身體","尾巴","前腳","後腳" }) );
  set("verbs", ({ "bite","crash" }) );
  set("chat_chance", 15);
  set("chat_msg", ({
     (: random_move :),
     }));
  setup();
}

void init()
{        
  ::init();
  switch( random(15) )
  {
    case 0:
         say(HIC"水紋鹿"NOR"跳進樹叢間消失不見了。\n");
         destruct(this_object());
         break;
    case 1..7:
         this_object()->set_temp("hide",1);
         break;
  }
} 

void die()
{
  object ob;
  if( !ob = query_temp("last_damage_from") )
    ob = this_player(1);
  if( !ob ) 
  {
    ::die();
    return;
  }
  switch( random(99) )
  {
    case  0..9: new(__DIR__"eq/deerskin-surcoat")->move(this_object());
          break;
  }
  ::die();
  return;
}
