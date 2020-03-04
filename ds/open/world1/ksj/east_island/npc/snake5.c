inherit NPC;

void create()
{
  set_name("七尺大蛇",({"long snake","snake"}) );
  set("long","一條七尺長的大蛇。\n");
  set("race", "野獸");    
  set("unit","條");
  set("village",1);
  set("age",7);
  set("level",14+random(6));
  set("attitude", "aggressive");
  set("limbs", ({ "頭部", "身體","尾巴"}) ); 
  set("verbs", ({ "bite" }) );     
  set("chat_chance", 10);
  set("chat_msg", ({
      (: random_move :),
     }));                                
  setup();
  add_money("coin",random(200)+200);
}
