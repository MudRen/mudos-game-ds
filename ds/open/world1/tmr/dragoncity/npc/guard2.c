#include <ansi.h>
inherit NPC;
void create()
{
  set_name("���N", ({ "gate guard","guard" }) );
  set("long","�u�ýY�s�����Y�����N�C\n");
  set("title",HIR"�֫ӭx"NOR);
  set("level",25);
  set("age",40);
  set_skill("blade", 70);
  set_skill("parry", 70);
  set_skill("unarmed", 76);
  set_skill("dodge", 65);
  set_skill("block", 65);
  setup();
  add_money("coin",600);
  carry_object(__DIR__"wp/blade")->wield();
}

