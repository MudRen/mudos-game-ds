#include <ansi.h>

inherit NPC;



void create()

{

  set_name(HIY"�Ԫ�"NOR, ({ "god ninja","god","ninja"}) );

  set("gender", "�k��" );

  set("long",@LONG

�Ѭɤ���O�Ⱚ�������L�T

LONG

);



  set("title",HIW"�Ѭ�"HIR"���"NOR);

  set("age",950);

  set("level",35);

  set("race","human");

  set("chat_chance", 20);

  

  setup();

  

  

  carry_object(__DIR__"eq/e7")->wear();

  carry_object(__DIR__"wp/w7")->wield();

}

  

  



  
