#include <ansi.h>
#include <path.h>

inherit NPC;

void create()
{
  set_name("���F���s", ({ "desert robber","robber" }) );
  set("gender", "�k��" );
  set("long",@LONG
�o�O����W�c�W�L���������ССy���F���z��s�C
LONG
);
  set("age",15);
  set("level",12);
  set("race","human");
  set_skill("dodge",30);
  set_skill("parry",20);

  setup();
  add_money("coin",50);
  carry_object(__DIR__"eq/eq10")->wear();
  carry_object(__DIR__"wp/wp5")->wield();
}

