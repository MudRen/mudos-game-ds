#include <ansi.h>
inherit NPC;
void create()
{
  set_name("華君乘", ({ "hua jun cheng","hua","jun","cheng" }) );
  set("gender", "女性" );
  set("long",@LONG
她正靜靜的吃著小菜。一襲黑色便裝，非常不予人親近的感覺。
LONG
);      
  set("age",25);
  set("level",20);
  set("race","human"); 
  setup();
}