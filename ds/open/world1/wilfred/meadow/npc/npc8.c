#include <ansi.h>
inherit NPC;

void create()
{
  set_name("���Ԭ���",({"meadow-war cow","cow"}) );
  set("long","�o�g���������A��������A�@�I�H�ɷ|�ĹL���ˤl�A���H�椧���ߡC\n");
  set("race", "beast");
  set("unit","�Y");
  set("age",6);
	set("title",HIG"�������"NOR);
  set("level",30);
  set("attitude", "aggressive");
  set("limbs", ({ "�Y��", "����","�ݳ�","�I��" }) );
  set("verbs", ({ "bite","claw" }) );
  set("chat_chance",30);
  set("chat_msg", ({
(: random_move :),
}) );

  setup();
  set_living_name("cow_war");
  carry_object(__DIR__"obj/meat");
   if( random(100) < 10 ) carry_object(__DIR__"obj/cow-skin");

}

void die()
{
   object ob, env, obj;
   int temp;
   string msg;

   if( !ob = query_temp("last_damage_from") )
   ob = this_player(1);
   if( !ob )
   {
     ::die();
     return;
   }

   if(!random(3))
   {
	   ob->add("popularity",1);
	   tell_object(ob,HIG"�A�o��@�I�n��C\n"NOR);
   }

   ::die();
   return;
}
