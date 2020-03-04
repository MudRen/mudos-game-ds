#include <ansi.h>
#include <path.h>

inherit NPC;

void create()
{
  set_name("黃沙賊小頭目", ({ "desert robber","robber" }) );
  set("gender", "男性" );
  set("long",@LONG
這是江湖上惡名昭彰的賊幫－－『黃沙幫』小頭目，
明顯比其它人孔武有力多了。
LONG
);
  set("age",15);
  set("level",16);
  set("race","human");
  set_skill("dodge",30);
  set_skill("parry",20);
  set_skill("blade",50);

  setup();
  add_money("coin",50);
  carry_object(__DIR__"eq/eq10")->wear();
  carry_object(__DIR__"wp/wp5")->wield();
}

