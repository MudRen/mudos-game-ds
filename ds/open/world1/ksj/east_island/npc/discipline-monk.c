#include <ansi.h>
inherit NPC;

void create()
{
  set_name("宗光", ({"discipline monk","monk"}));
  set("long",@long
真言宗的一支，專修祈禱符咒，跋涉山谷，經歷種種難行苦行，以求
得法力。修驗者又稱"山伏"。你面前的這位修驗道雖然全身破破爛爛
的，但儼然有股強大的氣勢。
long);      
  set("gender", "男性" );
  set("age",50);
  set("title","修驗道");
  set("evil",-30);
  set("level",45);
  set("race","human");
  set_skill("staff", 85);
  set_skill("parry", 70);
  set_skill("dodge", 70);
  set_skill("unarmed", 90);
  add("addition_armor",50+random(5));
  set("talk_reply","前方危險重重，請不要再深入森林。\n");
  setup();
  carry_object(__DIR__"eq/moon-arc-staff")->wield();
  carry_object(__DIR__"eq/water-pill");
  carry_object(__DIR__"eq/water-pill");
  carry_object(__DIR__"eq/water-pill");
  carry_object(__DIR__"eq/water-pill");
  carry_object(__DIR__"eq/water-pill");
  carry_object(__DIR__"eq/water-pill");
  carry_object(__DIR__"eq/water-pill");
  carry_object(__DIR__"eq/water-pill");
  carry_object(__DIR__"eq/water-pill");
  carry_object(__DIR__"eq/water-pill");
  carry_object(__DIR__"eq/food-pill");
  carry_object(__DIR__"eq/food-pill");
  carry_object(__DIR__"eq/food-pill");
  carry_object(__DIR__"eq/food-pill");
  carry_object(__DIR__"eq/food-pill");
  carry_object(__DIR__"eq/food-pill");
  carry_object(__DIR__"eq/food-pill");
  carry_object(__DIR__"eq/food-pill");
  carry_object(__DIR__"eq/food-pill");
  carry_object(__DIR__"eq/food-pill");
  add_money("coin",1000+random(500));
}

int special_attack(object me, object target, int hitchance)
{
  int damage,lv;
  lv=target->query("level");
  if(!me || !target) return 0;
  if(me->is_busy()) return 0;

  if( (me->query("hp"))  < (me->query("max_hp")/3))
  {
    if(!random(6) && me->query("ap") > 200)
    {
      damage=(75-lv)*10+random(100);
      message_vision(HIR"\n$N緊咬牙根，全身蓄力筋肉暴起，不顧傷口綻裂隔空朝$n擊出一掌，\n"
      +RED"$n被一股強大的勁力擊中，只覺得五內翻騰，口吐鮮血！。"HIR"("+damage+")\n\n"NOR,me, target);
      target->receive_damage("hp",damage,me);
      target->add_busy(3);
      me->receive_damage("ap",100,target);
      me->receive_damage("hp",100,target);
      message_vision(HIR"\n$N的身上噴出數道血柱！\n"NOR,me);
      return 1;
    }
    else if(me->query("ap") < 200)
    {
      command("eat water pill");
    }
    else
    {
      command("eat food pill");
    }
  }
  else if(!random(7) && me->query("ap") > 100)
  {
      damage = (100-lv) * 5 + random(100);
         if( damage < 1 ) damage = 10 + random(50);
    message_vision(HIW"\n$N口中喃喃唸著真言全身勁力爆增，接著大喝一聲，朝$n揮出一拳，\n"
    +RED"$n被無形的勁力擊中，嘴角滲血，全身筋骨欲裂！。"HIR"("+damage+")\n\n"NOR,me, target);
    target->receive_damage("hp",damage,me);
    me->receive_damage("ap",100,target);
    return 1;
  }
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
 
  switch( random(100) )
  {
    case  0..2: new(__DIR__"eq/perple-beads")->move(this_object());
    break;
  }
  ::die();
  return;
}
