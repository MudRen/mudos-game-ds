#include <ansi.h>

inherit NPC;



void create()

{

  set_name(HIB"��T�l"NOR, ({ "moon wolf","wolf" }) );

  set("gender", "�k��" );

  set("long",@LONG

�ѬɲĤ@�r�N�A����"�B�Ѭ�"�A�k��"��T�٧��C"�A�n���­��C

LONG

);





  set("age",1020);

  set("level",41);

  set("title",HIW"�Ѭ�"HIR"�r�N"NOR);

  set("race","human");

  set("chat_chance", 20);

  set_skill("unarmed",91);

  set_skill("parry",80);

  set_skill("dodge",80);

  set("Merits/bar",4);

  

  setup();

  carry_object(__DIR__"eq/e1")->wear();

  carry_object(__DIR__"wp/w1")->wield();



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

HIM"\n�i�Ѭɫ�q�j"HIW"�Ѭ�"HIR"�r�N"HIB"��T�l"HIY"�Q"+ob->name(1)+"�����F�C\n\n"NOR,users());









   tell_object(ob,HIR"[���F"HIB"��T�l"HIR"���A�i�o��3�I�n��]\n"NOR);

   ob->add("popularity",3);

   ::die();

   return;

}





  



  





  









  

  
