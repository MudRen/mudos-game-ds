#include <ansi.h>

inherit NPC;



void create()

{

  set_name(HIC"守衛"NOR, ({ "god guard","god","guard"}) );

  set("gender", "男性" );

  set("long",@LONG

天界中能力算中下等的守衛總管﹗

LONG

);



  set("title",HIW"天界"HIR"Ｃ級"NOR);

  set("age",900);

  set("level",27);

  set("race","human");

  set("chat_chance", 20);

  

  setup();

  

  

  carry_object(__DIR__"eq/e4")->wear();

  carry_object(__DIR__"wp/w4")->wield();

}

  

  



  
