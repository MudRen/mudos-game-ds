#include <ansi.h>
inherit NPC;
void create()
{
  set_name("洛雲飛", ({ "luo yun-fei","yun","fei","luo" }) );
  set("gender", "男性" );
  set("long",@LONG
地方上的世家大少，其先祖以一套斷雲劍法一脈相乘，洛家上下多少
精通此劍法，其中以洛雲飛使劍最為優秀。但觀其外貌，便與一般人
無異，看不出是劍法高手。穿著一雙潔白如雪的靴子，人稱「飛雲靴
」。
LONG
);      
  set("age",25);
  set("level",25);
  set("race","human"); 
  setup();
}