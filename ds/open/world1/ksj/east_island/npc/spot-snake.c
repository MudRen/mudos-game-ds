inherit NPC;

void create()
{
  set_name("�Z����D",({"spot snake","snake"}) );
  set("long","�@����ؾl�������Ĵ�����D�C\n");
  set("race", "���~");    
  set("unit","��");
  set("age",3);
  set("level",6);
  set("attitude", "heroism");  
  set("limbs", ({ "�Y��", "����","����"}) ); 
  set("verbs", ({ "bite" }) );     
  set("chat_chance", 15);
  set("chat_msg", ({
      "�Z����D���ɦR�X�D�H�A�R��R��C\n",
     }));                                
  setup();
  add_money("coin",25);
}
