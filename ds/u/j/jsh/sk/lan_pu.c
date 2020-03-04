#include <ansi.h>
#define SKILL_NAME "連砍"
inherit SKILL;
inherit SSERVER;  
string *au_axe=({
HIW"$N兇猛的拿著手中之斧，砍向$n的頭！\n"NOR, 
HIW"$N兇猛的拿著手中之斧，砍向$n的身！\n"NOR,
HIW"$N兇猛的拿著手中之斧，砍向$n的手！\n"NOR,
HIW"$N兇猛的拿著手中之斧，砍向$n的腰！\n"NOR,
HIW"$N兇猛的拿著手中之斧，砍向$n的腳！\n"NOR, 
});

int exert(object me, object target,string arg)
{
    string msg="";
    int damage,sk,i,c,te;
    object weapon; 
    weapon=me->query_temp("weapon");
    me=this_player();  
    if(!me) return 0;
    if(!me->is_fighting()) return notify_fail(SKILL_NAME+"是一種戰鬥技能!\n");
  if( !target ) target = offensive_target(me);
  if( !target ) return notify_fail("你要對誰使出"+SKILL_NAME+"?\n");     
  if(weapon->query("skill_type")!="axe") 
    return notify_fail("使用"+SKILL_NAME+"必須要有斧。\n");  
  if((int)me->query("ap") < 100)
    return notify_fail("你目前的身體狀況無法使用這麼劇烈的武功\﹗\n"); 
  if(me->query_skill("axe")<60)
    return notify_fail("使用"+SKILL_NAME+"需要極為紮實的斧法。\n"); 
  if(me->query_str() <70) 
    return notify_fail("使用"+SKILL_NAME+"需要足夠的力量。\n");

  sk=me->query_skill("lan_pu");  
  te=me->query_Merits("bar"); 
  c=target->query_armor(); 
     if(me->is_busy()) return 0;
    if(me->query_skill("axe")<60)
      return notify_fail("\n你的基本斧法還沒到那境界。\n");  
    if(arg == "damnall")  
    { 
    if(me->query_skill("lan_pu") <100) return notify_fail("你的技能等級不夠\n");
    if(me->query("level") <45) return notify_fail("你的等級不夠\n");
    if(me->query("ap") < 1000) return notify_fail("你的氣勁不足.\n");
    if(me->query("mp") < 500 ) return notify_fail("你的魔力不足.\n");
     {      
       message_vision(HIW"$N"HIR"狂怒：都給我消失吧！！！！！！！\n"NOR,me,target); 
           for(i=0;i<21;i++)
           {
           msg=au_axe[random(sizeof(au_axe))];
           message_vision(msg,me,target);
           }
       damage = 500 + sk + random(99) - c + target->query("max_hp")/7 +random(33); 
       target->receive_damage("hp",damage,me);
       tell_object(me,HIR"("+damage+")點的傷害\n"NOR); 
       COMBAT_D->report_status(target);
       me->receive_damage("ap",500+random(399)); 
       me->receive_damage("mp",300+random(299));
       me->start_busy(2); 
       target->start_busy(4);
       me->improve_skill("lan_pu",100); 
       }
       return 1;
     }

    if( random(me->query_skill("dodge")+50) < random(target->query("dex")*2) )
    { 
    msg += "\n"HIW""+target->name()+"左閃右閃，避開了$N的招式。\n"NOR;  
    me->receive_damage("ap",30+sk/3);  
    message_vision(msg,me,target);
    me->start_busy(2);
    me->improve_skill("lan_pu",5);  
    return 1;
    }
     else{
  
         switch(random(3))          { 
       case 0:
       damage = 50+random(39)+me->query_damage()+sk+me->query_dex()-c*2;
       message_vision(HIR"$N突然爆走！瘋狂的揮舞著手中之斧！\n"NOR,me,target); 
           for(i=0;i<6;i++)
           {
           msg=au_axe[random(sizeof(au_axe))];
           message_vision(msg,me,target);
           }
      target->receive_damage("hp",damage,me);  
      me->receive_damage("ap",30+sk/3);  
      tell_object(me,HIR"("+damage+")點的傷害\n"NOR); 
      COMBAT_D->report_status(target);
      target->start_busy(2);
      me->start_busy(1);   
      me->improve_skill("lan_pu",5+me->query_skill("lan_pu")*2); 
          return 1;  
       break;
      case 1: 
       damage = 100+random(50)+me->query_damage()+sk*2+me->query_dex()*2-c*2;
       message_vision(HIR"$N突然爆走！瘋狂的揮舞著手中之斧！失去了理智！\n"
                      HIY"但也被自己強大的攻擊力給震傷了..\n"NOR,me,target); 
           for(i=0;i<13;i++)
           {
           msg=au_axe[random(sizeof(au_axe))];
           message_vision(msg,me,target);
           }
      target->receive_damage("hp",damage,me);   
      me->receive_damage("ap",30+sk/3);  
      me->receive_damage("hp",random(50)+random(2+me->query("sk")-20)+damage/3,me);
      tell_object(me,HIR"("+damage+")點的傷害\n"NOR); 
      COMBAT_D->report_status(target);
      target->start_busy(3);
      me->start_busy(2);   
      me->improve_skill("lan_pu",5+me->query_skill("lan_pu")*2); 
          return 1;  
       break;       
      default: return 0;
        }   

    } 
}

int improve_limite(object ob)
{
  return 100;
}

