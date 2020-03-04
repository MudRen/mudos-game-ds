inherit NPC;

void create()
{
  set_name("班紋草蛇",({"spot snake","snake"}) );
  set("long","一條兩尺餘長全身棕斑的草蛇。\n");
  set("race", "野獸");    
  set("unit","條");
  set("age",3);
  set("level",6);
  set("attitude", "heroism");  
  set("limbs", ({ "頭部", "身體","尾巴"}) ); 
  set("verbs", ({ "bite" }) );     
  set("chat_chance", 15);
  set("chat_msg", ({
      "班紋草蛇不時吐出蛇信，嘶∼嘶∼。\n",
     }));                                
  setup();
  add_money("coin",25);
}
