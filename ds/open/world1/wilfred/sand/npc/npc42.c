#include <ansi.h>
inherit NPC;

void create()
{
  set_name(HIM"�d�~�s"NOR,({"thousand dragon","dragon"}) );
  set("long",@LONG
�@�����������F�Ъ����s�A�����J���A�ȥզ⪺�sŽ�������ت��C
LONG
);
  set("race", "dragon");
  set("unit","��");
  set("age",1000);
  set("level",45);
  set("attitude", "aggressive");
  set("limbs", ({ "�Y��", "����","�ݳ�","����","����","�I��" }) );
  set("verbs", ({ "bite","claw" }) );
  add("addition_armor",70);
  add("addition_damage",70);

  set("chat_chance", 5 );
  set("chat_msg", ({
(: random_move :),
}) );

  setup();
  set_living_name("dragon_war");
  carry_object(__DIR__"eq/eq21")->wear();
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

   ob->add_temp("hero",2);
   ob->add("popularity",2);
   tell_object(ob,HIC"[�A�o���B�~�� 2 �I�n��!!]\n"NOR);

   ::die();
   return;
}