#include <ansi.h>
inherit NPC;

void create()
{
  set_name("瘋狂牯牛",({"crazy cow","cow"}) );
  set("long","發狂中的牯牛，雙眼血紅，一付隨時會衝過來咬人的樣子，今人望之生懼。\n");
  set("race", "beast");
  set("unit","頭");
	set("title",HIG"牯牛草原"NOR);
  set("age",6);
  set("level",35);
  set("attitude", "killer");
  set("limbs", ({ "頭部", "腹部","胸部","背部" }) );
  set("verbs", ({ "bite","claw" }) );
  set("chat_chance",30);
  set("chat_msg", ({
(: random_move :),
}) );

  setup();
  carry_object(__DIR__"obj/meat");
       if(random(100)<5) carry_object(__DIR__"obj/paper-box");

  set_living_name("cow_war");
}

int special_attack(object me,object target,int hitchance)
{
  int i, hit = random(4)+1, damage, dodge;
  if(!me || !target) return 0;
  if(random(5)) return 0;

  message_vision(HIR"\n\t$N雙眼佈滿血絲，朝著$n瘋狂的衝了過來！！\n\n"NOR,me,target);
  dodge = target->query_skill("dodge");
  for(i=1;i<hit;i++)
  {
    message_vision(HIY"$N發狂般的向$n急衝而來！！",me,target);
    if(dodge + random(dodge) < 100)
    {
      damage = 15+random(40);
      message_vision("$N一時閃避不及，被正面撞上，受到不小的傷害！ "HIR"("+damage+")\n"NOR,target);
      target->receive_damage("hp",damage);
    }
    else
    {
      if(dodge + random(dodge) < 200)
      {
        damage = 5+random(20);
        message_vision("$N一個閃身，堪堪避過，但身體仍被勁風割傷！ "HIR"("+damage+")\n"NOR,target);
        target->receive_damage("hp",damage);
      }
      else message_vision("$N身形一晃，輕鬆避過此擊！\n"NOR,target);
    }
  }
  return 1;
}

void die()
{
   object ob, env, obj;
   int temp;
   string msg;

   if( !ob = query_temp("last_damage_from") )
   ob = this_player(1);
   if( !ob )
   {
     ::die();
     return;
   }

   ob->add("popularity",1);
   tell_object(ob,HIG"你得到一點聲望。\n"NOR);

   ::die();
   return;
}

