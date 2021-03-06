inherit NPC;

void create()
{
  set_name("黑色毒蛇",({"black snake","snake"}) );
  set("long","一條兩尺餘長有著三角形頭部的黑蛇。\n");
  set("race", "野獸");    
  set("unit","條");
  set("village",1);
  set("age",5);
  set("level",12+random(6));
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

int special_attack(object me, object target, int hitchance)
{
  if(!me) return 0;
  if(me->is_busy()) return 0;

  if(!random(3))
  {
    message_vision("$N伸出毒牙，狠狠的咬了$n一口！\n", this_object(), target);
    target->apply_condition("poison", target->query_condition("poison")+(random(5)+1));
    return 1;
  }
  return 0;
}
