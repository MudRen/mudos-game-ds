#include <ansi.h>
inherit NPC;

void create()
{
  set_name("門生", ({"shinin-ryuu apprentice","apprentice"}));
  set("long",@long
村裡較年輕的村民，也是新陰流的新進門徒，正在這裡勤奮的鍛練武
藝。
long);      
  set("gender", "男性" );
  set("age",18);
  set("title",HIG"新陰流"NOR);
  set("level",15+random(6));
  set("race","human");
  set_skill("blade", 30+random(11));
  set_skill("parry", 20+random(11));
  set_skill("dodge", 30+random(11));
  set_skill("unarmed", 30);
  add("addition_armor",20+random(5));
  set("talk_reply","我正在練習中，請別打擾。\n");
  set("chat_chance", 8);
  set("chat_msg", ({
      "門生高舉竹刀，用力往前方揮下的同時大喊一聲：喝！\n",
      "門生空手凝神，大喊一聲的同時雙掌已穩穩夾住對手的竹刀。\n",
      "門生奮力地縱跳翻滾，一面喊出：嘿嚇！的叫聲。\n",
     }));                
  setup();
  carry_object(__DIR__"eq/bamboo-blade")->wield();
  add_money("coin",200+random(50));
}
