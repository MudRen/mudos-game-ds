#include <ansi.h>
inherit NPC;

void create()
{
  set_name("野戰牯牛",({"meadow-war cow","cow"}) );
  set("long","發狂中的牯牛，雙眼血紅，一付隨時會衝過的樣子，今人望之生懼。\n");
  set("race", "beast");
  set("unit","頭");
  set("age",6);
	set("title",HIG"牯牛草原"NOR);
  set("level",30);
  set("attitude", "aggressive");
  set("limbs", ({ "頭部", "腹部","胸部","背部" }) );
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
	   tell_object(ob,HIG"你得到一點聲望。\n"NOR);
   }

   ::die();
   return;
}
