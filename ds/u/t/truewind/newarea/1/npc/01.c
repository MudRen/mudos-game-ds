#include <ansi.h>
inherit NPC;
void create()
{
  set_name("公孫嬤嬤", ({ "Gon-sun madam","madam" }) );
  set("gender", "女性" );
  set("long",@LONG
嬤嬤擺起兩道橫眉，招招手，笑嘻嘻的打量著你。
公孫嬤嬤是春風樓的大管家，自從前任春風樓總管離開後，春風樓就由
嬤嬤一人總攬大小事務。
LONG
);      
  set("age",45);
  set("level",30);
  set("race","human");    
  setup();
  carry_object(__DIR__"wp/wp01")->wield();
}