#include <ansi.h>
inherit NPC;
void create()
{
  set_name("�u��", ({ "evil-guard","guard" }) );
  set("long","�O�è��]�쪺�u�áA�Z�O���e�����C\n");
  set("level",50);
  set("age",100);
  set("title",HIW+BLK"��"HIW"�]��"NOR);
  set("combat_exp",2900000);
  set("chat_chance", 20);
  set("chat_msg", ({
(: command("say ���a���O�A�i�H�[�d���a��A�������}�C") :),
}));
  set_skill("parry", 100);
  set_skill("unarmed", 100);
  set_skill("dodge", 100);
  set_skill("blade", 100);
  set("max_hp",40000);
  set("max_mp",40000);
  set("max_ap",40000); 
  set("hp",40000);
  set("mp",40000);

  set("ap",40000);  
  setup();
  add_money("coin",1000); 
  carry_object("/open/world1/wp/steel_blade")->wield();
}

