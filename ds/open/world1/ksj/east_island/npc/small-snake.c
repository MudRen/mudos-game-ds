inherit NPC;

void create()
{
  set_name("�p���D",({"small snake","snake"}) );
  set("long","�ӲӪ������@���p���D�A���M�S���r�ʡA���O�Q�r���٬O�ܵh���C\n");
  set("race", "���~");    
  set("unit","��");
  set("age",1);
  set("level",4);
  set("attitude", "heroism");  
  set("limbs", ({ "�Y��", "����","����"}) ); 
  set("verbs", ({ "bite" }) );     
  set("chat_chance", 15);
  set("chat_msg", ({
      "�p���D���t�a�b�a���W�C«�C\n",
     }));                                
  setup();
  add_money("coin",25);
}
