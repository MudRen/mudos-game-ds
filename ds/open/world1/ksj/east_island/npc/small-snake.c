inherit NPC;

void create()
{
  set_name("小水蛇",({"small snake","snake"}) );
  set("long","細細長長的一條小水蛇，雖然沒有毒性，但是被咬到還是很痛的。\n");
  set("race", "野獸");    
  set("unit","條");
  set("age",1);
  set("level",4);
  set("attitude", "heroism");  
  set("limbs", ({ "頭部", "身體","尾巴"}) ); 
  set("verbs", ({ "bite" }) );     
  set("chat_chance", 15);
  set("chat_msg", ({
      "小水蛇迅速地在地面上遊竄。\n",
     }));                                
  setup();
  add_money("coin",25);
}
