inherit NPC;

void create()
{
  set_name("�j�����D",({"big spot snake","snake"}) );
  set("long","�@���ʧ����Z���D�C\n");
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
