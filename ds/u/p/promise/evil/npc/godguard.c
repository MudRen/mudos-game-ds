#include <ansi.h>
inherit NPC;
void create()
{
  set_name("�u��", ({ "god guard","guard" }) );
  set("long","�O�øt�g��ɪ��u�áA�Z�O���e�����C\n");
  set("level",55);
  set("age",140);
  set("title",YEL"�t�g"HIY"����"NOR);
  set("combat_exp",2900000);
  set("chat_chance", 20);
  set("chat_msg", ({
(: command("say ���a���O�A�i�H�[�d���a��A�������}�C") :),
}));
  set_skill("parry", 100);
  set_skill("unarmed", 100);
  set_skill("dodge", 100);
  //set_skill("sword", 100):
  set("max_hp",40000);
  set("max_mp",40000);
  set("max_ap",40000); 
  set("hp",40000);
  set("mp",40000);
  set("ap",40000);

  setup();
  add_money("coin",1000); 
  carry_object("/open/world1/tmr/bagi/npc/wp/six-sun-fist")->wield();
}

