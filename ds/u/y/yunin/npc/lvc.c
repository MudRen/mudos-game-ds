#include <ansi.h>

inherit NPC;



void create()

{

  set_name(HIC"�u��"NOR, ({ "god guard","god","guard"}) );

  set("gender", "�k��" );

  set("long",@LONG

�Ѭɤ���O�⤤�U�����u���`�ޡT

LONG

);



  set("title",HIW"�Ѭ�"HIR"�ѯ�"NOR);

  set("age",900);

  set("level",27);

  set("race","human");

  set("chat_chance", 20);

  

  setup();

  

  

  carry_object(__DIR__"eq/e4")->wear();

  carry_object(__DIR__"wp/w4")->wield();

}

  

  



  
