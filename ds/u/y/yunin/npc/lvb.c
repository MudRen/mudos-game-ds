#include <ansi.h>

inherit NPC;



void create()

{

  set_name(HIC"�W��"NOR, ({ "god general","god","general"}) );

  set("gender", "�k��" );

  set("long",@LONG

�Ѭɤ���O�⤤�����u�äW�աT

LONG

);



  set("title",HIW"�Ѭ�"HIR"�Я�"NOR);

  set("age",900);

  set("level",29);

  set("race","human");

  set("chat_chance", 20);

  

  setup();

  

  

  carry_object(__DIR__"eq/e5")->wear();

  carry_object(__DIR__"wp/w5")->wield();

}

  

  



  
