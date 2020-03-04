#include <ansi.h>
inherit NPC;

void create()
{
  set_name("�����K�s",({"iron dragon","dragon"}) );
  set("long",@LONG
�@���K�s�������s�A���G���ѤO�q������ʡC
LONG
);
  set("race", "dragon");
  set("unit","��");
  set("age",200);
  set("level",25+random(5));
  set("attitude", "killer");
  set("limbs", ({ "�Y��", "����","�ݳ�","����","����","�I��" }) );
  set("verbs", ({ "bite","claw" }) );
  set("exp",9000+random(1000));
  add("addition_armor",30);
  add("addition_damage",30);

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

