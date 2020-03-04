#include <ansi.h>
inherit NPC;
void create()
{
  set_name("步卒", ({ "tiger soldier", "soldier" }) );
        set("attitude", "aggressive");

  set("long","這是一個虎人鐵櫻族軍隊中的步卒，正在這附近巡邏。\n");
  set("title","鐵櫻族");
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

