#include <ansi.h>
inherit NPC;

void create()
{
  set_name("�������s",({"silver dragon","dragon"}) );
  set("long",@LONG
�@���Ȼs�������s�A���G���ѤO�q������ʡC
LONG
);
  set("race", "dragon");
  set("unit","��");
  set("age",200);
  set("level",30+random(5));
  set("attitude", "killer");
  set("limbs", ({ "�Y��", "����","�ݳ�","����","����","�I��" }) );
  set("verbs", ({ "bite","claw" }) );
  set("exp",10000+random(2000));
  add("addition_armor",40);
  add("addition_damage",40);

  set("chat_chance", 70 );
  set("chat_msg", ({
(: random_move :),
}) );

  setup();
  set_living_name("dragon_war");
}

void die()
{
   object ob;

   if( !ob = query_temp("last_damage_from") )
   ob = this_player(1);
   if( !ob )
   {
     ::die();
     return;
   }

   ob->add_temp("hero",1);

   ::die();
   return;
}

