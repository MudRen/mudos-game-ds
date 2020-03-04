#include <ansi.h>
inherit NPC;
void create()
{
  set_name("錢有名", ({ "chin yo min","chin" }) );
  set("gender", "男性" );
  set("long",@LONG
本是武林霸主錢安的兒子，但因一番的波折而來到了天界又當上了四塔天王之一。
LONG
);

 set("age",819);
  set("level",41);
  set("title",HIR"四塔天王之一"NOR);
  set("max_hp",41201);
  set("max_mp",2100);
  set("max_ap",3000);
  set("exp",35000+random(3000));
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

HIR"\n【武林驚傳】"+HIR""+ob->name(1)+"破了神之四塔之一的焱鍊塔。\n\n"NOR,users());
tell_object(ob,HIR"[殺了"HIB"錢有名"HIR"的你可得到3點聲望]\n"NOR);

 ob->add("popularity",3);
 ::die();
   return;

}

