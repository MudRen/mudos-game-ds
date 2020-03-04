#include <ansi.h>
inherit NPC;

void create()
{
  set_name(HIB"�l�u�s"NOR,({"wing dragon","dragon"}) );
  set("long",@LONG
���s����Ӫ��A�o�������j���e�H�A�q��H�šA�E�ݤ��U����
�Ŧ⪺�j���C
LONG
);
  set("race", "dragon");
  set("unit","��");
  set("age",300);
  set("level",40);
  set("attitude", "aggressive");
  set("limbs", ({ "�Y��", "����","�ݳ�","����","����","�I��" }) );
  set("verbs", ({ "bite","claw" }) );
  add("addition_armor",60);
  add("addition_damage",60);

  set("chat_chance", 5 );
  set("chat_msg", ({
(: random_move :),
}) );

  setup();
  set_living_name("dragon_war");
  carry_object(__DIR__"eq/eq19")->wear();
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
   ob->add("popularity",1);
   tell_object(ob,HIC"[�A�o���B�~�� 1 �I�n��!!]\n"NOR);

   ::die();
   return;
}
