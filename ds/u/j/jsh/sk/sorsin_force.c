/*****************************************************/
/* Sorsin_Force V1.3             DATE:2006.3.25      */
/* EDITOR:Whoami                                     */ 
/* ..........其實也沒改什麼啦.....所以comment就免了..*/ 
/*****************************************************/

/*****************************************************/
/* WIND CLASS NEW SKILL          DATE:2003.5.24      */
/* EDITOR:Jangshow               NOTE:NO WEAPON SK   */ 
/* 一段時間後,看ppl的反應,再看要不要開御劍           */
/*****************************************************/
#include <ansi.h>
#define SKILL_NAME "索星奧義"
inherit SKILL;
inherit SSERVER; 


string *sor_str= ({
"$N隱身潛進，突然在$n身旁對$n出了一招"HIC"「"HIG"蔚"HIC"」\n"NOR,
"$N提劍虛畫七劃，似北斗七星，層層包住$n，趁機抽劍一擊，一招"HIC"「"HIB"罡\"HIC"」\n"NOR,
"$N屈劍一指，內力潛進劍中，使出"HIC"「"HIR"煜"HIC"」"NOR"字訣，劍招狠狠的斗直直進\n",
"$N口中喃喃念道『背故都之沃衍，適新邑之丘墟』，手中之劍突然挑起土，使了"HIC"「"YEL"沃"HIC"」\n"NOR,
"$N運氣於臂，手上的劍突然嗡嗡作響，氣勢驟升，對$n使出一招"HIC"「"HIW"奘"HIC"」\n"NOR,
});


int exert(object me, object target,string arg)
{
  string msg="";
  int damage,sk,c,te,i,x,delay_time,busy_time; 
  object weapon,wp;  
  me=this_player(); 
  if(!me) return 0;
  if(!me->is_fighting()) return notify_fail(SKILL_NAME+"是一種戰鬥技能!\n");
  if( !target ) target = offensive_target(me);
  if( !target ) return notify_fail("你要對誰使出"+SKILL_NAME+"?\n");    
  if( me->query_temp("nan") )
    return notify_fail("你短時間內不能使用"+SKILL_NAME+"！\n");     
  if((int)me->query("mp") < 50 || (int)me->query("ap") < 100)
    return notify_fail("你目前的身體狀況無法使用這麼劇烈的武功\﹗\n");
  if(!weapon=me->query_temp("weapon")) return notify_fail("使用索星奧義需要使用武器。\n"); 
  if(weapon->query("skill_type")!="sword") 
    return notify_fail("使用"+SKILL_NAME+"必須要有劍。\n"); 
  if(me->query_skill("sword")<100) 
    return notify_fail("使用"+SKILL_NAME+"需要極為紮實的劍法基礎。\n"); 
  if(me->query_skill("dodge")<100)
    return notify_fail("使用"+SKILL_NAME+"需要極為紮實的閃躲基礎。\n");
  if(me->query_skill("sorgi_sword")<100)
    return notify_fail("使用"+SKILL_NAME+"需要極為紮實的索極劍法。\n");
  if(me->query_skill("star-sword")<100)
    return notify_fail("使用"+SKILL_NAME+"需要極為紮實的昂星劍義。\n");
  if(me->query_skill("moon_force")<100)
    return notify_fail("使用"+SKILL_NAME+"需要渾厚的殘月心法。\n");
  if(me->query_skill("force")<100)
    return notify_fail("使用"+SKILL_NAME+"需要渾厚的內功\。\n"); 
  if(me->query_dex() <60) 
    return notify_fail("使用"+SKILL_NAME+"需要足夠的敏捷。\n"); 
  if(me->query_Merits("tec") <1)
    return notify_fail("使用"+SKILL_NAME+"，科技(TEC)不能等於零。\n"); 
  sk=me->query_skill("sorsin_force"); 
  te=me->query_Merits("tec");
  c=target->query_armor();
  me->receive_damage("mp",random(sk));
  me->receive_damage("ap",random(sk)+sk); 
  if(arg == "help" || !arg) 
     return notify_fail(HIC"\n"+SKILL_NAME+"目前有 one two three final 四項功\能，詳見 help sorsin_force。\n"NOR);
  if(arg == "one")
  {
  if(me->query_skill("sorsin_force") <1) return notify_fail("\n你的"+SKILL_NAME+"還沒到那境界。\n");  
  if( random(me->query("dex")*4) < random(target->query_skill("dodge")*2) )
  {
    msg += "\n"HIW""+target->name()+"先發制人！阻止了$N的出招。\n"NOR; 
    message_vision(msg,me,target); 
    me->add_temp("nan",1);
    me->start_busy(1);
    call_out("stop_delay",40/te,me);  
//    me->improve_skill("sorsin_force",5+me->query("int")*2/3);
  } else {
    damage = me->query_damage()-random(c);
    damage = damage * (random(3)+1);
    if( damage < 0 ) damage = 0;
    busy_time = random(me->query_skill("sorsin_force")/30);
    delay_time = 20/(me->query_skill("sorsin_force")/20);
    
    //damage = COMBAT_D->Merits_damage(me,target,damage,"tec"); 
    msg += "\n"HIM""+target->name()+"奮力迎擊！左閃右擋，硬是接下了數道劍氣！\n"NOR;  
    message_vision("\n"HIW"$N將內力貫注於手中之劍，充盈的"HIC"劍氣"HIW"蓄勢待發•••\n"NOR,me,target);
    message_vision(msg,me,target);
    target->receive_damage("hp",damage,me); 
    COMBAT_D->report_status(target);
    if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
                tell_object(me,HIY"("+damage+")\n"NOR);
    if(target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
                tell_object(target,HIR"("+damage+")\n"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");

    target->start_busy(busy_time); 
    me->start_busy(delay_time);  
    me->add_temp("nan",1);
    call_out("stop_delay",20/te,me); 
    me->improve_skill("sorsin_force",4+random(me->query_dex()/7+me->query_Merits("tec")/3+sk/8));   
  } 
  return 1;
  } 
  if(arg == "two") 
  {
  if(me->query_skill("sorsin_force") <66) 
    return notify_fail("\n你的"+SKILL_NAME+"還沒到那境界。\n");    
  if( random(me->query("dex")*5) < random(target->query_skill("dodge")*3) )
  {
    msg += HIW"\n"+target->name()+"先發制人！阻止了$N的出招。\n"NOR; 
    message_vision(msg,me,target); 
    me->add_temp("nan",1);
    me->start_busy(1);
    call_out("stop_delay",40/te,me);   
//    me->improve_skill("sorsin_force",5+me->query("int")*2/3);
  } else {
    damage = me->query_damage()-random(c);
    damage = damage * 4;
    damage = damage + 10*(me->query("Merits/bar") - random(target->query("Merits/bar")));
    damage = damage + me->query_skill("sorsin_force");
    if( damage < 0 ) damage = 0;
    busy_time = random(me->query_skill("sorsin_force")/30);
    delay_time = 15/(me->query_skill("sorsin_force")/20);
    
    //damage = COMBAT_D->Merits_damage(me,target,damage,"tec"); 
    msg += "\n\t"HIG"劍風一起！\n"
    "\t\t"HIB"『"HIC"殘月之祕•幻滅疾念"HIB"』\n"
    "\t\t"HIW"一股劍氣掃蕩在"+target->name()+"的周圍！四面空氣滋滋作響！\n"
    "\t\t"HIC"天疾星陣"HIW"奪劍而出！百道劍氣••由陣導入••\n"
    "\t\t"HIR"鮮血哀嚎••"+target->name()+"可見••\n"NOR;  
    message_vision("\n"HIW"$N將內力貫注於手中之劍，充盈的"HIC"劍氣"HIW"蓄勢待發•••\n"NOR,me,target);
    message_vision(msg,me,target); 
    if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
                tell_object(me,HIY"("+damage+")\n"NOR);
    if(target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
                tell_object(target,HIR"("+damage+")\n"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");
    target->receive_damage("hp",damage,me);
    COMBAT_D->report_status(target);
    target->start_busy(busy_time); 
    me->start_busy(delay_time);  
    me->add_temp("nan",1);
    call_out("stop_delay",40/te,me); 
    me->improve_skill("sorsin_force",2+random(me->query_dex()/8+me->query_Merits("tec")/4+sk/8));   
  }  
  return 1;
  }

  if(arg == "three") 
  {
  if(me->query_skill("sorsin_force") <99) return notify_fail("\n你的"+SKILL_NAME+"還沒到那境界。\n");  
  if( random(me->query("dex")*6) < random(target->query_skill("dodge")*4) )
  {
    msg += "\n"HIW""+target->name()+"先發制人！抑止了$N的招式。\n"NOR; 
    message_vision(msg,me,target); 
    me->add_temp("nan",1);
    me->start_busy(1);
    call_out("stop_delay",40/te,me);   
//    me->improve_skill("sorsin_force",5+me->query("int")*2/3);
  }  else  {
    busy_time = random(me->query_skill("sorsin_force")/25);
    delay_time = 20/(me->query_skill("sorsin_force")/20)+random(2);
    x = random(me->query_skill("sorsin_force")/20)+te/4;
    if( x > 6 ) x = 6;
    //damage = COMBAT_D->Merits_damage(me,target,damage,"tec"); 
/*
    msg += "\n\t"HIG"劍風一起！"HIR"$N的眼神被血紅所覆蓋\！\n"
    "\t\t"HIB"『"HIC"殘月之祕•幻滅疾念"HIW"•瞬•天•殺"HIB"』\n"  
    "\t\t"HIW"一股劍氣掃蕩在"+target->name()+"的周圍！四面空氣滋滋作響！\n"
    "\t\t"HIW"竟導出了雙重"HIC"天疾星陣"HIW"！千道劍氣！"HIR"殺無赦！\n"
    "\t\t"HIR""+target->name()+"卻在"HIW"白光"HIR"閃完之後，已倒在血泊當中••\n"NOR;  
*/
    msg += "\n\t"HIB"『"HIC"殘月之祕•幻滅疾念"HIW"•瞬•天•殺"HIB"』\n"NOR;
      
    message_vision("\n"HIW"$N將內力貫注於手中之劍，充盈的"HIC"劍氣"HIW"蓄勢待發•••\n"NOR,me,target);
    message_vision(msg,me,target);
    for(i=0;i<x;i++){
                     
    damage = me->query_damage()-random(c);
    damage = damage + (me->query_dex()/2)*random(x);
    if( damage < 0 ) damage = 0;
                        
    target->receive_damage("hp",damage,me); 
    COMBAT_D->report_status(target);                     
    if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
                tell_object(me,HIY"("+damage+")\n"NOR);
    if(target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
                tell_object(target,HIR"("+damage+")\n"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");
    }
    
    target->start_busy(busy_time); 
    me->start_busy(delay_time);  
    me->add_temp("nan",1);
    call_out("stop_delay",80/te,me);
    me->receive_damage("ap",x*40,me);
    me->receive_damage("mp",x*15,me);    
    me->improve_skill("sorsin_force",10+random(me->query_dex()/2+me->query_Merits("tec")*2+sk/2));  
  } 
  return 1;
  }

  if(arg == "final") 
  {
    if(me->query_skill("sorsin_force") <100) return notify_fail("\n你的"+SKILL_NAME+"還沒到那境界。\n");  
    if( random(me->query("dex")*7) < random(target->query_skill("dodge")*5) )
    {
      msg += "\n"HIW""+target->name()+"先發制人！抑止了$N的招式。\n"NOR;
      me->start_busy(1);
      message_vision(msg,me,target);
      me->add_temp("nan",1);
      call_out("stop_delay",40/te,me);  
//    me->improve_skill("sorsin_force",5+me->query("int")*2/3);
    } else {
    damage = me->query_damage()*5-random(c);
    damage = damage + me->query_dex()*random(10);
    damage = damage - (target->query_skill("force"))*(target->query("Merits/bio")/4);
    if( damage < 0 ) damage = 0;
    busy_time = random(me->query_skill("sorsin_force")/20);
    delay_time = 15/(me->query_skill("sorsin_force")/20)+random(3);
    x = me->query_skill("sorsin_force")/5+te/4;
    if( x > 25 ) x = 25;
    //damage = COMBAT_D->Merits_damage(me,target,damage,"tec"); 
    message_vision("\n\t"HIW"$N一股作氣！將"HIB"內勁"HIW"一次導入劍內，使出疾風連技『"HIC"索星天壁"HIW"』\n\n"NOR,me,target);
    for(i=0;i<x;i++)
    {
      msg=sor_str[random(sizeof(sor_str))];
      message_vision(msg,me,target);
    }
    target->receive_damage("hp",damage,me); 
    if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
                tell_object(me,HIY"("+damage+")\n"NOR);
    if(target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
                tell_object(target,HIR"("+damage+")\n"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")\n");
    COMBAT_D->report_status(target);
    target->start_busy(busy_time); 
    me->start_busy(delay_time);  
    me->receive_damage("ap",x*10,me);
    me->add_temp("nan",1);
    call_out("stop_delay",100/te,me);
  }          
  return 1;
  } 
}
                 
void stop_delay(object me)
{
 if(!me) return;
 me->delete_temp("nan");
}
int improve_limite(object ob)
{
 return 100;
}

