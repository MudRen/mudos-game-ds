#include <ansi.h>
inherit NPC;
inherit SSERVER;
void normal_ai();
void combat_ai();

void create()
{
  set_name("醫藥兵",({"corpsman","_CORPSMAN_"}) );
  set("long",@LONG
海軍中負責醫療的士兵，頭戴的帽子及肩膀上都繡有醫療的字樣。
LONG);
  set("race", "human");    
  set("unit","位");
  set("title",HIC"海軍"NOR);
  set("level",25);
  add("addition_armor",40);
  add("addition_damage",20);
  set_skill("unarmed", 40);
  set_skill("parry", 30);
  set_skill("dodge", 60);
  set("chat_chance", 30);
  set("chat_msg", ({
     (: normal_ai() :),
     }) );     
  set("chat_chance_combat", 100);
  set("chat_msg_combat", ({
     (: combat_ai() :),
     }) );     
  setup();
  set_living_name("_NPC_CORPSMAN_");
}

void normal_ai()
{        
  int mp,adm_hp,max_hp;
  object ob1;
  ::init();
  ob1=find_living("_NPC_REAR_ADMIRAL_");

  mp=this_object()->query("mp");
  adm_hp=ob1->query("hp");
  max_hp=ob1->query("max_hp");

  if( !random(7) )
  {
    message_vision("\n$N整理器材後，下去休息了。\n",this_object());
    destruct(this_object());
    return;
  }

  if( objectp(ob1) )
  {
    if(!environment(ob1) )
    {
      return;
    }
    else if( adm_hp < (max_hp-500) )
    {
      message_vision(HIG"\n$N迅速地從藥箱中取出傷藥及消毒藥水，為少將做緊急的醫療。\n"NOR,this_object());
      ob1->receive_heal("hp",300+random(100));
      return;
    }
  }
  else return;
}

void combat_ai()
{        
  int mp,adm_hp,max_hp;
  object me,ob1,target;
  ::init();
  ob1=find_living("_NPC_REAR_ADMIRAL_");
  target = offensive_target(ob1);
  me=this_object();

  adm_hp=ob1->query("hp");
  max_hp=ob1->query("max_hp");

  if(target->can_fight(me))
  {
    me->kill_ob(target);
  }

  if( objectp(ob1) )
  {
    if(!environment(ob1) )
    {
      return;
    }
    else if( adm_hp < (max_hp-1000) )
    {
      message_vision(HIG"\n$N迅速地在少將身上的傷口塗上止血劑，同時打了止痛針。\n"NOR,me);
      ob1->receive_heal("hp",300+random(100));
      return;
    }
  }
  else return;
}
