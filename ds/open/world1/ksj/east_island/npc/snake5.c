inherit NPC;

void create()
{
  set_name("�C�ؤj�D",({"long snake","snake"}) );
  set("long","�@���C�ت����j�D�C\n");
  set("race", "���~");    
  set("unit","��");
  set("village",1);
  set("age",7);
  set("level",14+random(6));
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
