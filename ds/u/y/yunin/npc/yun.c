#include <ansi.h>

inherit NPC;



void create()

{

  set_name(MAG"羽夜子"NOR, ({ "ya general","ya","general"}) );

  set("gender", "男性" );

  set("long",@LONG

號名-天界尊者。有兩人之下，萬人之上的權威。

LONG

);



  set("title",HIW"天界"HIC"尊者"NOR);

  set("age",1021);

  set("level",39);

  set("race","human");

  set("chat_chance", 20);

  set_skill("sword",90);

  set_skill("unarmed",90);

  set_skill("parry",90);

  set_skill("dodge",90);

  setup();

  set_living_name("cow_master");

  add_money("coin",2000+random(1000));

  carry_object(__DIR__"eq/e2")->wear();

  carry_object(__DIR__"wp/w2")->wield();

}

  

  



  
