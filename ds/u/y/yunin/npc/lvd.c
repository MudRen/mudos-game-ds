#include <ansi.h>

inherit NPC;



void create()

{

  set_name(HIC"神兵"NOR, ({ "god solider","god","solider"}) );

  set("gender", "男性" );

  set("long",@LONG

天界中能力算下等的守衛兵﹗

LONG

);



  set("title",HIW"天界"HIR"Ｄ級"NOR);

  set("age",800);

  set("level",24);

  set("race","human");

  set("chat_chance", 20);

  

  setup();

  

  

  carry_object(__DIR__"eq/e3")->wear();

  carry_object(__DIR__"wp/w3")->wield();

}

  

  



  
