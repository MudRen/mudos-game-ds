#include <ansi.h>
inherit NPC;
void create()
{
  set_name("洛曲江", ({ "luo qi-jiang","qi","jiang","luo" }) );
  set("gender", "男性" );
  set("long",@LONG
洛曲江是洛家的義子，最近跟著大哥們到處見識朝天湖的名勝景觀。
LONG
);      
  set("age",25);
  set("level",25);
  set("race","human"); 
  setup();
}