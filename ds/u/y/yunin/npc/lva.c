#include <ansi.h>

inherit NPC;



void create()

{

  set_name(HIC"恐怖人"NOR, ({ "god terrible","god","terrible"}) );

  set("gender", "男性" );

  set("long",@LONG

天界中能力算上等的神兵﹗

LONG

);



  set("title",HIW"天界"HIR"Ａ級"NOR);

  set("age",950);

  set("level",32);

  set("race","human");

  set("chat_chance", 20);

  

  setup();

  

  

  carry_object(__DIR__"eq/e6")->wear();

  carry_object(__DIR__"wp/w6")->wield();

}

  

  



  
