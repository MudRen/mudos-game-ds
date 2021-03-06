#include <ansi.h>
inherit NPC;

void create()
{
  set_name(MAG"奇美拉"NOR, ({"chimera"}) );
  set("long",@LONG
獅子的身體，尾巴是毒蛇，有獅子跟山羊兩個頭，牠的嘴會吐出火來
，極端兇猛殘暴，是傳說中的魔物。
LONG
);
  set("race", "beast");
  set("unit","隻");
  set("age",45);
  set("gender", "雄性" );
  set("attitude", "aggressive");
  set("level",47+random(4));
  set("title",RED"  魔獸 "NOR);
  set("limbs", ({ "獅頭","身體","蛇尾","前腳","後腳","羊頭" }) );
  set("verbs", ({ "bite" }) );
  add("addition_damage",30+random(15));
  set("chat_chance", 20);
  set("chat_msg", ({
     (: random_move :),
     }));
  setup();
}

void init()
{
  ::init();
  if( environment(this_player())->query("no_kill") ) return;
  if( environment(this_player())->query("no_fight") ) return;
  if(!this_object()->visible(this_player())) return;
  if(userp(this_player()) )
    this_object()->kill_ob(this_player());
}

int special_attack(object me, object target, int hitchance)
{
  if(!me) return 0;
  if(me->is_busy()) return 0;

  if(!random(11))
  {
    message_vision(RED"\n$N"RED"的兩個頭同時咬住$n，奮力左右分扯造成嚴重的傷口！\n\n"NOR, this_object(), target);
    target->receive_damage("hp",random(50)+120,me);
    target->apply_condition("blooding", target->query_condition("blooding")+(random(2)+3));
    return 1;
  }
  else if(!random(11))
  {
    message_vision(HIR"\n$N"HIR"朝$n吐出熊熊烈火，燒得$n四處逃竄！\n\n"NOR, this_object(), target);
      if(target->query_shield() > 250) 
         target->receive_damage("hp", 1+random(50),me);
         else target->receive_damage("hp", 25 + 250-(target->query_shield()),me);
    return 1;
  }
  else if(!random(11))
  {
    message_vision(GRN"\n$N"GRN"的蛇尾冷不防地咬了$n一口，$n感覺到傷口腫脹疼痛！\n\n"NOR, this_object(), target);
    target->receive_damage("hp",random(50),me);
    target->apply_condition("poison", target->query_condition("poison")+(random(3)+1));
    return 1;
  }
  return 0;
}

int receive_damage(string type,int cost)
{
  object ob,target;
  ob = this_object();
  target = this_player();
  ::receive_damage(type,cost,target);
  return 0;
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
  ob->add("popularity",2);
  tell_object(ob,HIG"你得到 2 點聲望。"NOR);      
  switch( random(99) )
  {
    case  0..9: new(__DIR__"eq/chimera-boots")->move(this_object());
    break;
  }
  ::die();
  return;
}
