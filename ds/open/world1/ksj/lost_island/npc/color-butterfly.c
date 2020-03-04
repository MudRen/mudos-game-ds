#include <ansi.h>
inherit NPC;

void create()
{
  set_name(HIC"七"HIM"色"HIG"蝶"NOR, ({"color butterfly","butterfly"}) );
  set("long",@LONG
一隻七彩的蝴蝶，逍遙自在地穿梭在花叢間。
LONG
);
  set("race", "beast");
  set("gender", "雄性");
  set("unit","隻");
  set("age",1);
  set("level",17+random(3));
  set("limbs", ({ "身體"}) );
  set("verbs", ({ "crash"}) );
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
