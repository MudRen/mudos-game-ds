#include <ansi.h>
inherit NPC;
void create()
{
  set_name("�u���u��", ({ "gate guard","guard" }) );
  set("long","�u�ýY�s�������H�A���`�t�d�ˬd�X�J�������Ӷ��C\n");
  set("level",30);
  set("age",40);

  set("combat_exp", 29000);
  set("chat_chance", 20);
  set("chat_msg", ({
(: command("say �o���٤���q��A��p�C") :),
}));
  set("chat_chance_combat", 14);
  set("chat_msg_combat", ({
HIW"�u�û��G�ϤF�ϤF�A���ѤƤ餧�U�����s�����[\n"NOR,
"�u�û��G�S�̡̭A��L���F\n"NOR
}));
  set_skill("sword", 60);
  set_skill("parry", 70);
  set_skill("unarmed", 76);
  set_skill("dodge", 65);
  setup();
  add_money("coin",600);
  carry_object(__DIR__"wp/wp3")->wield();
}
