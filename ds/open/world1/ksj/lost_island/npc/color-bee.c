#include <ansi.h>
inherit NPC;

void create()
{
  set_name(HIM"五"HIG"彩"HIC"蜂"NOR, ({"color bee","bee"}) );
  set("long",@LONG
一隻色彩斑爛的小蜜蜂，正在勤快地採集花蜜。
LONG
);
  set("race", "beast");
  set("gender", "雄性");
  set("unit","隻");
  set("age",1);
  set("level",16+random(3));
  set("limbs", ({ "身體"}) );
  set("verbs", ({ "bite"}) );
  set("chat_chance", 20);
  set("chat_msg", ({
     (: random_move :),
  }));
  setup();
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
  switch( random(10) )
  {
    case  0: new(__DIR__"eq/honey")->move(this_object());
    break;
  }
  ::die();
  return;
}
