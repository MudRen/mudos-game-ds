#include <ansi.h>
inherit NPC;

int receive_damage(string type,int cost);
void create()
{
  set_name(YEL"巨石怪"NOR, ({"rock sprite","sprite" }) );
  set("gender", "男性" );
  set("long",@LONG
生長在此的一種怪物，爆發力極強。
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
    message_vision(NOR+YEL"\n\t\t《巨石推擊》\n"NOR,ob);
   
 if(me->query("level") > 40)
    {
      COMBAT_D->do_attack(ob,me,ob->query_temp("weapon"),random(2)+3);
      if(query("hp") < query("max_hp")) add("hp",60+random(40));
    }
    
  }

  ::receive_damage(type,cost,me);
  return 0;
}  

void init()
{
  ::init();
  add_action("do_guard","go");
}

int do_guard(string arg)
{
  if(!userp(this_player())) return 0;
  if(arg == "north")
  {

    message_vision(HIW"$n狠狠的把$N檔了下來！！\n"NOR,this_player(),this_object());
        
  }
 if(arg == "west")
  {

    message_vision(HIW"$n狠狠的把$N檔了下來！！\n"NOR,this_player(),this_object());
        
  }
 if(arg == "south")
  {

    message_vision(HIW"$n狠狠的把$N檔了下來！！\n"NOR,this_player(),this_object());
        
  }
 if(arg == "east")
  {

    message_vision(HIW"$n狠狠的把$N檔了下來！！\n"NOR,this_player(),this_object());
        
  }
  return 0;
}




