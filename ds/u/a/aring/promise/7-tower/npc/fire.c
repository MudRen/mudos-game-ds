#include <ansi.h>
inherit NPC;

int receive_damage(string type,int cost);
void create()
{
  set_name(HIR"火怪"NOR, ({"fire sprite","sprite","__GUARD__" }) );
  set("gender", "男性" );
  set("long",@LONG
生長在此的一種怪物，火功極強。
LONG
);
  set("race", "beast");
  set("unit","隻");
  set("age",1000);
  set("level",30);
  set("str",20+random(50));
  set("con",20+random(50));
  set("int",20+random(50));
  set("dex",20+random(50));
  set_skill("dodge",100);
  set_skill("block",100);
  set_skill("combat",100);
  set("max_hp",30000);
  set("hp",30000);
  set("limbs", ({ "頭部", "腹部","胸部","爪子","尾巴" }) );
  set("verbs", ({ "bite","claw" }) );

  set("chat_chance", 5);
  set("chat_msg", ({
(: command("say 殺殺殺殺殺∼∼∼") :),
}));
  
  setup();
  
}
int receive_damage(string type,int cost)
{
  object ob,me;
  int i;
  ob = this_object();
  me = this_player();
  // 反擊
  if(!random(4))
  {
    if(ob->is_busy()) ob->add_busy(-10);
    message_vision(HIR"\n\t\t《火雲反手》\n"NOR,ob);
   
 if(me->query("level") > 40)
    {
      COMBAT_D->do_attack(ob,me,ob->query_temp("weapon"),random(2)+3);
      if(query("hp") < query("max_hp")) add("hp",60+random(40));
    }
    
  }

  ::receive_damage(type,cost,me);
  return 0;
}  


