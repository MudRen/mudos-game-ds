#include <ansi.h>
inherit NPC;
void create()
{
  set_name("燕非彥", ({ "yan fa yan","yan" }) );
  set("gender", "男性" );
  set("long",@LONG
神之四塔之一的守塔天王，少年時，在某次的武術大會裡，打敗
當今江湖最殘暴的人物，所以被天界聖神拉攏至神之四塔裡當任守塔
天王。
LONG
);

 set("age",997);
  set("level",41);
  set("title",HIR"四塔天王之一"NOR);
  set("max_hp",31012);
  set("max_mp",3000);
  set("max_ap",2900);
  set("race","human");
  set("chat_chance", 20);
  set_skill("unarmed",91);
  set_skill("sword",100);
set_skill("dodge",80);
  set("Merits/bar",4);

setup(); 
carry_object(__DIR__"wp/only1")->wield();
carry_object(__DIR__"eq/shu12")->wear();
carry_object(__DIR__"eq/shu11")->wear();
carry_object(__DIR__"eq/shu10")->wear();
carry_object(__DIR__"eq/shu9")->wear();
carry_object(__DIR__"eq/shu8")->wear();
carry_object(__DIR__"eq/shu7")->wear();
carry_object(__DIR__"eq/shu6")->wear();
carry_object(__DIR__"eq/shu5")->wear();
carry_object(__DIR__"eq/shu4")->wear();
carry_object(__DIR__"eq/shu3")->wear();
carry_object(__DIR__"eq/shu2")->wear();
carry_object(__DIR__"eq/shu1")->wear();
carry_object(__DIR__"eq/shu0")->wear();
carry_object(__DIR__"eq/shu00")->wear();
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

HIR"\n【武林驚傳】"+HIY""+ob->name(1)+"破了神之四塔之一的修羅塔。\n\n"NOR,users());
tell_object(ob,HIR"[殺了"HIB"燕飛彥"HIR"的你可得到3點聲望]\n"NOR);

 ob->add("popularity",3);
 ::die();
   return;

}

