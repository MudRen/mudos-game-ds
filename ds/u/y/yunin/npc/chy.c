#include <ansi.h>
inherit NPC;
void create()
{
  set_name("采臣", ({ "chy chen","chy" }) );
  set("gender", "男性" );
  set("long",@LONG
他是天下可以「疾風」、「八極」、「神武」所相提並論的門派─古月流派之傳人
他放下了接管門派的重責大任，而來此處當四塔天王，但其中似乎另有隱情。
LONG
);

 set("age",420);
  set("level",50);
  set("title",HIR"四塔天王之一"NOR);
  set("max_hp",50000);
  set("max_mp",3000);
  set("max_ap",3000);
  set("exp",35000+random(4000));
  set("race","human");
  set("chat_chance", 20);
  set_skill("unarmed",91);
  set_skill("sword",100);
  set_skill("parry",80);
  set_skill("dodge",80);
  set("Merits/bar",4);

setup();
  
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

 message("world:world1:vision",

HIR"\n【武林驚傳】"+HIW""+ob->name(1)+"破了神之四塔之一的玄月塔。\n\n"NOR,users());
tell_object(ob,HIR"[殺了"HIB"采臣"HIR"的你可得到3點聲望]\n"NOR);

 ob->add("popularity",3);
 ::die();
   return;

}

