#include <ansi.h>
inherit NPC; 

void create() 
{ 
  set_name(HIG"碧眼"HIW"巨鵰"NOR,({"blue-eyes roc","roc"}));
  set("race","beast");
  set("level",55);
  set("max_hp",25000);  
  set("combat_exp",400000);       set("age",432+random(32));      
  set("attitude","unfriendly");
  set("devil",20); 
  set("limbs", ({ "頭部", "身體", "左腳爪", "右腳爪", "左翼","右翼" }) );
  set("verbs", ({ "bite","claw"}) ); 
  set("chat_chance", 10);  
  set("chat_msg", ({
     (: this_object(), "random_move" :), 
      "碧眼巨鵰揮動著大翅膀，劃起了一陣陣強風。\n" }) );
  set("long",@LONG       
好個巨大的怪鵰，有著碧綠如鬼火的雙眼，兩翼展開來竟可遮天蓋地，
而且鵰腳竟是五爪，更奇怪的是如鋼鐵般的鳥嘴上還插著一把閃耀紫光
的長劍。 
LONG); 
  setup(); 
  set_living_name("pool_npc");
  carry_object(__DIR__"obj/chisel-claw")->wield();
  carry_object(__DIR__"obj/purple-sword");
}
 
void die()
{
    object ob;
  if( !ob = query_temp("last_damage_from") )
    ob = this_player(1);
  if( !ob ) 
  {
    ::die();
    return;
  } 
  ob->add("popularity",4);
  message("world:world1:vision",
    HIW"\n\t天空中那顆代表碧眼巨鵰的宿命星殞落了，你似乎可以聽見"+ob->name(1)+"的輕笑聲。\n\n"+NOR
    ,users());
  message_vision( "$N垂死鼓動著翅膀，想再飛起來，可惜••可惜••" ,this_object() );
  ::die();
  return;
}
