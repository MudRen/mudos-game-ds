inherit NPC;

void create()
{
  set_name("�C��j�D",({"green snake","snake"}) );
  set("long","�@���|�ؾl�����j�C�D�C\n");
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
