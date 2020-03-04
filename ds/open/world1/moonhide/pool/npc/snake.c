#include <ansi.h>
inherit NPC; 

void create() 
{ 
  set_name(HIR"血蛟"NOR,({"blood snake","snake"}));
  set("race", "beast");
  set("level",53+random(5));
  set("max_hp",33333); 
  set("age",432+random(32));     
  set("combat_exp",500000); 
  set("attitude","unfriendly");
  set("devil",40); 
  set("limbs", ({ "頭部", "身體", "腹部","背部","腰部" }) );
  set("verbs", ({ "bite","claw"}) ); 
  set("long",@LONG        
渾身通紅的蛟龍，與點液算是同出一徹，但比點液更加兇猛！
LONG); 
  setup(); 
  set_living_name("pool_npc");
  carry_object(__DIR__"obj/snake-waist")->wear();
  carry_object(__DIR__"obj/snake-liver");
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
    HIR"\n\t"+ob->name(1)+"怒道：仆街吧！！與點液同出一徹的血蛟！！\n\n"+NOR
    ,users());
  ::die();
  return;
}
