#include <ansi.h>
inherit NPC;

void create()
{
  set_name(MAG"腐毒盲蛇"NOR, ({"poison snake","snake"}) );
  set("long",@LONG
一條全身呈紫黑色的大蛇，身長約過２０尺，身上只有幾塊要掉不掉
的蛇鱗，剩下的是千瘡百孔流著毒汁的蛇皮，這條蛇沒有眼睛，靠吐
出的毒氣毒斃獵物，然後吞食。
LONG
);
  set("race", "beast");
  set("unit","隻");
  set("age",30);
  set("gender", "雌性" );
  set("level",28+random(3));
  set("title",HIW"  奇獸 "NOR);
  set("limbs", ({ "頭部", "身體","尾巴" }) );
  set("verbs", ({ "bite" }) );
  set("chat_chance", 20);
  set("chat_msg", ({
     (: random_move :),
     }));
  setup();
}

int special_attack(object me, object target, int hitchance)
{
  if(!me) return 0;
  if(me->is_busy()) return 0;

  if(!random(10))
  {
    if( random(target->query_dex()) < 20 )
    {
      message_vision("$N朝著$n吐出一大團"MAG"紫色毒氣"NOR"，$n不小心吸了一口，頓時頭昏眼花！\n"NOR, me, target);
      target->apply_condition("poison", target->query_condition("poison")+(random(10)+20));
      return 1;
    }
    else
    {
      message_vision("$N朝著$n吐出一大團"MAG"紫色毒氣"NOR"，$n迅速地閃避到一旁！\n"NOR, me, target);
      return 1;
    }
  }
  else if(!random(10))
  {
    if( random(target->query_dex()) < 20 )
    {
      message_vision("$N朝著$n吐出一大團"GRN"腐蝕黏液"NOR"，$n不小心被沾到身上，造成嚴重的腐蝕！\n"NOR, me, target);
      target->receive_damage("hp",250-(target->query_shield()),me);
      return 1;
    }
    else
    {
      message_vision("$N朝著$n吐出一大團"GRN"腐蝕黏液"NOR"，$n眼明腳快閃過了黏液攻擊！\n"NOR, me, target);
      return 1;
    }
  }
  return 0;
}

void init()
{        
  ::init();
  switch( random(14) )
  {
    case 0:
         say(MAG"腐毒盲蛇"NOR"一溜煙消失在草叢間。\n");
         destruct(this_object());
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
  switch( random(100) )
  {
    case  0..3: new(__DIR__"eq/poison-snake-waist")->move(this_object());
          break;
    case  4..99: new(__DIR__"eq/poison-snake-pill")->move(this_object());
          break;
  }
  ::die();
  return;
}
