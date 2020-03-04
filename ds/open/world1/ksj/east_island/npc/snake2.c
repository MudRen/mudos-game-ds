inherit NPC;

void create()
{
  set_name("�¦�r�D",({"black snake","snake"}) );
  set("long","�@����ؾl�����ۤT�����Y�����³D�C\n");
  set("race", "���~");    
  set("unit","��");
  set("village",1);
  set("age",5);
  set("level",12+random(6));
  set("attitude", "aggressive");
  set("limbs", ({ "�Y��", "����","����"}) ); 
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
    message_vision("$N���X�r���A�������r�F$n�@�f�I\n", this_object(), target);
    target->apply_condition("poison", target->query_condition("poison")+(random(5)+1));
    return 1;
  }
  return 0;
}
