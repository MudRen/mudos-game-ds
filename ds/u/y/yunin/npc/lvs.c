#include <ansi.h>

inherit NPC;



void create()

{

  set_name(HIY"忍者"NOR, ({ "god ninja","god","ninja"}) );

  set("gender", "男性" );

  set("long",@LONG

天界中能力算高等的神兵﹗

LONG

);



  set("title",HIW"天界"HIR"Ｓ級"NOR);

  set("age",950);

  set("level",35);

  set("race","human");

  set("chat_chance", 20);

  

  setup();

  

  

  carry_object(__DIR__"eq/e7")->wear();

  carry_object(__DIR__"wp/w7")->wield();

}

  

  



  
