#include <ansi.h>
inherit NPC;
void create()
{
  set_name("�B��", ({ "tiger soldier", "soldier" }) );
        set("attitude", "aggressive");

  set("long","�o�O�@�Ӫ�H�K��ڭx�������B��A���b�o�����ޡC\n");
  set("title","�K���");
  set("race","tiger");
  set("level",5);
  set("age",20);
  set_skill("blade", 60);
  set_skill("parry", 70);
  set_skill("unarmed", 76);
  set_skill("dodge", 65);
  setup();
  add_money("coin",600);
  carry_object(__DIR__"wp/blade")->wield();
}

