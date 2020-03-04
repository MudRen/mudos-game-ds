//god-fire 神武真火 (改革版--革命就是非常之破壞再進而非常之建設)
#include <ansi.h>
inherit SSERVER;
inherit SKILL;
int cast(object me, object target)
{
  int inn,sk,cost,mk,busy,i,damage,shield,level,fireall;
  if(!me) me=this_player();
  inn=me->query_int();
  mk=me->query_spell("god-fire");
  sk=mk/10+1;
  cost=(mk/3)+10+random(me->query("level"));
  fireall=me->query_spell("god-fire")/33;
  if(environment(me)->query("no_cast")) return notify_fail("這裡不能施法。\n");
  if( (int)me->query("mp") <  cost ) return notify_fail("你的法力不夠。\n");
  if ( !target ) 
  {
     if( me->is_fighting() )
     {
        if ( !target ) target = offensive_target(me);
        if(me->query_temp("firepower") > 0)
        {
          message_vision("$N雙神噴火，烈焰蓋\日，手上的"+HIW+"『"+HIR+"神武真火"+HIW+"』"+NOR+"，怒地轟向$n。\n"NOR,me,target);
          if(!me) return 0;                                      
          if(!target) return notify_fail("目標消失了。\n");      
          if( environment(me) != environment(target) )           
          return notify_fail("目標離開了你的施法範圍。\n");
          sk=mk/20+random(mk/20)+1;
          inn=me->query_int();
          level=me->query("level");
          shield=target->query_shield();
          damage = mk+inn*3+random(level);
          damage = damage/3 + random(damage/3);
          if(userp(me)) damage=damage+(damage/5)-random(damage/7);
          damage = damage - shield/2 -random(shield/2);
          if(userp(target)) damage=damage-damage/5;
          if(damage<1) damage=random(inn+mk/3);
          if(damage > 0)
          {
           // COMBAT_D->dodge_factor(target,"dodge") 會傳回對方閃躲率(負值)
           if( inn + random(mk*2 + inn*2)  > random(-COMBAT_D->dodge_factor(target,"dodge")/2+target->query_int()))
           {
             // 增加素質對傷害的影響
             damage = COMBAT_D->Merits_damage(me,target,damage,"wit");
             target->receive_damage("hp", damage, me ); 
             message_vision("  只見$N閃躲不掉一道"HIW"『"HIR"神武真火"HIW"』"NOR"的攻勢，被燒得皮開肉綻！"NOR,target);
             if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
             tell_object(me,HIY"("+damage+")"NOR);
             if(target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
             tell_object(target,HIR"("+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");
             message_vision("\n",target);
             if(wizardp(me) && me->query("env/debug")) tell_object(me,"  造成"+damage+"點傷害!!\n"); 
             COMBAT_D->report_status(target);         //顯示target狀態
           }
          else
          {
           message_vision(GRN"  只見$N東閃西躲，好不容易躲開一道「神武真火」的猛烈攻勢。\n"NOR,target);
          }
          } else message_vision(GRN"  「神武真火」猛烈的燒向$N, 但似乎沒有造成$N絲毫的傷害。\n"NOR,target);
        if( random(40+inn) > 20 )
        {
          me->improve_spell("god-fire",inn/2+random(inn)+1);
        }
          if(random(2+mk/25)==0) me->start_busy(1);
          if(!target->is_fighting(me)) target->kill_ob(me);
          if(!me->is_fighting(target)) me->kill_ob(target);
          if(random(8)<1) me->add_busy(1);
          me->receive_damage("mp",cost/2); //施法扣MP
          me->start_busy(2); //施法動作時間
          i=me->query_temp("firepower");
          me->set_temp("firepower",i-1);
        }
        else {
          message_vision("$N雙手合十，喃喃自語道："HIW"「"HIG"天地合德，日月合明，四時合序，鬼神合火以滅敵。"HIW"」\n"NOR,me);
          busy=2;
          me->start_busy(busy); //施法動作時間
          me->receive_damage("mp",cost); //施法扣MP
          me->set_temp("power_cast",1+mk/33);
          if(userp(me)) call_out("delay",busy*2-1,target,me,mk);
          else call_out("delay",busy*2-2,target,me,mk);
        }
     }
     else {
       if(me->is_ghost() ) return notify_fail("你現在是鬼魂，無法使用神武真火。\n");
       if(me->is_busy() ) return notify_fail("你現在沒空，等你手邊事情做完再使用。\n");
       if(me->query("mp")<cost) return notify_fail("你的法力不夠哦。\n");
       if(me->query_temp("firepower") > (fireall -1) ) return notify_fail("你手上的神武真火之到達顛峰狀態。\n");
       i=me->query_temp("firepower");
       me->receive_damage("mp",cost); //施法扣MP
       me->set_temp("firepower",i+1);
       message_vision("\n$N雙手合十，喃喃自語道："HIW"「"HIG"天地合德，日月合明，四時合序，鬼神合火。"HIW"」\n"NOR,me);
       message_vision("一把"HIW"「"HIR"神武真火"HIW"」"NOR"凝聚在$N的手上。\n"NOR,me);
       me->start_busy(2); //施法動作時間
     }
  }
  else {
    if(!me->can_fight(target)) return me->can_fight(target);  //檢查是否可以攻擊
    if ( !target ) target = offensive_target(me);
    if(me->query_temp("firepower") > 0)
    {
          message_vision("$N雙神噴火，烈焰蓋\日，手上的"+HIW+"『"+HIR+"神武真火"+HIW+"』"+NOR+"，怒地轟向$n。\n"NOR,me,target);
          if(!me) return 0;                                      
          if(!target) return notify_fail("目標消失了。\n");      
          if( environment(me) != environment(target) )           
          return notify_fail("目標離開了你的施法範圍。\n");
          sk=mk/20+random(mk/20)+1;
          inn=me->query_int();
          level=me->query("level");
          shield=target->query_shield();
          damage = mk+inn*3+random(level);
          damage = damage/3 + random(damage/4);
          if(userp(me)) damage=damage+(damage/5)-random(damage/7);
          damage = damage - shield/2 -random(shield/2);
          if(userp(target)) damage=damage-damage/5;
          if(damage<1) damage=random(inn+mk/3);
          if(damage > 0)
          {
           // COMBAT_D->dodge_factor(target,"dodge") 會傳回對方閃躲率(負值)
           if( inn + random(mk*2 + inn*2)  > random(-COMBAT_D->dodge_factor(target,"dodge")/2+target->query_int()))
           {
             // 增加素質對傷害的影響
             damage = COMBAT_D->Merits_damage(me,target,damage,"wit");
             target->receive_damage("hp", damage, me ); 
             message_vision("  只見$N閃躲不掉一道"HIW"『"HIR"神武真火"HIW"』"NOR"的攻勢，被燒得皮開肉綻！"NOR,target);
             if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
             tell_object(me,HIY"("+damage+")"NOR);
             if(target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
             tell_object(target,HIR"("+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");
             message_vision("\n",target);
             if(wizardp(me) && me->query("env/debug")) tell_object(me,"  造成"+damage+"點傷害!!\n"); 
             COMBAT_D->report_status(target);         //顯示target狀態
           }
          else
          {
           message_vision(GRN"  只見$N東閃西躲，好不容易躲開一道「神武真火」的猛烈攻勢。\n"NOR,target);
          }
          } else message_vision(GRN"  「神武真火」猛烈的燒向$N, 但似乎沒有造成$N絲毫的傷害。\n"NOR,target);
        if( random(40+inn) > 20 )
        {
          me->improve_spell("god-fire",inn/2+random(inn)+1);
        }
          if(random(2+mk/25)==0) me->start_busy(1);
          if(!target->is_fighting(me)) target->kill_ob(me);
          if(!me->is_fighting(target)) me->kill_ob(target);
          if(random(8)<1) me->add_busy(1);
          me->receive_damage("mp",cost/2); //施法扣MP
          me->start_busy(2); //施法動作時間
          i=me->query_temp("firepower");
          me->set_temp("firepower",i-1);
    }
    else {
          message_vision("$N雙手合十，喃喃自語道："HIW"「"HIG"天地合德，日月合明，四時合序，鬼神合火以滅敵。"HIW"」\n"NOR,me);
          busy=2;
          me->start_busy(busy); //施法動作時間
          me->receive_damage("mp",cost); //施法扣MP
          me->set_temp("power_cast",1+mk/33);
          if(userp(me)) call_out("delay",busy*2-1,target,me,mk);
          else call_out("delay",busy*2-2,target,me,mk);
    }
  }
  return 1;
}
int delay(object target,object me,int mk)
{
 int inn,sk,damage,shield,level;
                                                        
 if(!me) return 0;                                      
 if(!target) return notify_fail("目標消失了。\n");      
 if( environment(me) != environment(target) )           
          return notify_fail("目標離開了你的施法範圍。\n");
 if( me->query_temp("power_cast") < 1 && me->query_temp("firepower") < 1 ) 
 {
  message_vision(HIW"$N"HIW"因為受到創傷而亂了思緒, 無法順利施展法術。\n"NOR,me);
  return 1;
 }
 me->delete_temp("power_cast");
 sk=mk/20+random(mk/20)+1;
 inn=me->query_int();
 level=me->query("level");
 shield=target->query_shield();

    damage = mk+inn*3+random(level);
    damage = damage/3 + random(damage/3);
    if(userp(me)) damage=damage+(damage/5)-random(damage/7);
    damage = damage - shield/2 -random(shield/2);
    if(userp(target)) damage=damage-damage/5;
    if(damage<1) damage=random(inn+mk/3);

message_vision("\n突然$N手上烈焰衝天,祭起一道"HIW"『"HIR"神武真火"HIW"』"NOR"直燒向$n！！"NOR,me,target);

 if(damage > 0)
 {
    // COMBAT_D->dodge_factor(target,"dodge") 會傳回對方閃躲率(負值)
    if( inn + random(mk*2 + inn*2)  > random(-COMBAT_D->dodge_factor(target,"dodge")/2+target->query_int()))
    {
        // 增加素質對傷害的影響
        damage = COMBAT_D->Merits_damage(me,target,damage,"wit");
       target->receive_damage("hp", damage, me ); 
       message_vision("  只見$N閃躲不掉一道"HIW"『"HIR"神武真火"HIW"』"NOR"的攻勢，被燒得皮開肉綻！"NOR,target);
       if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
        tell_object(me,HIY"("+damage+")"NOR);
       if(target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
        tell_object(target,HIR"("+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");
       message_vision("\n",target);
       if(wizardp(me) && me->query("env/debug")) tell_object(me,"  造成"+damage+"點傷害!!\n"); 
       COMBAT_D->report_status(target);         //顯示target狀態
    }
    else
        {
                message_vision(GRN"  只見$N東閃西躲，好不容易躲開一道「神武真火」的猛烈攻勢。\n"NOR,target);
        }
 } else message_vision(GRN"  「神武真火」猛烈的燒向$N, 但似乎沒有造成$N絲毫的傷害。\n"NOR,target);
 if( random(40+inn) > 20 )
 {
         me->improve_spell("god-fire",inn/2+random(inn)+1);
 }
 if(random(2+mk/25)==0) me->start_busy(1);
 if(!target->is_fighting(me)) target->kill_ob(me);
 if(!me->is_fighting(target)) me->kill_ob(target);
 if(random(8)<1) me->add_busy(1);
 if(me->query_spell("god-fire")>79 && random(mk/3 + inn ) > random(-(COMBAT_D->dodge_factor(target,"dodge")/2+target->query_int())))
 {
   call_out("delay2",1,target,me,mk);
 }
 return 1;
}
int delay2(object target,object me,int mk)
{
 int inn,sk,damage,shield,level;
                                                        
 if(!me) return 0;                                      
 if(!target) return notify_fail("目標消失了。\n");      
 if( environment(me) != environment(target) )           
          return notify_fail("目標離開了你的施法範圍。\n");

 sk=mk/20+random(mk/20)+1;
 inn=me->query_int();
 level=me->query("level");
 shield=target->query_shield();

    damage = mk+inn*3+random(level);
    damage = damage/3 + random(damage/3);
    if(userp(me)) damage=damage+(damage/3)-random(damage/7);
    damage = ( damage - shield/2 -random(shield/2) ) /2 + random(me->query_spell("god-fire"));
    if(userp(target)) damage=damage-damage/5;
    if(damage<1) damage=random(10);

 message_vision(HIR"剎那間！！$N的背後出現數道火龍，飛騰而出，直衝向$n！！"NOR,me,target);

 if(damage > 0)
 {
    // COMBAT_D->dodge_factor(target,"dodge") 會傳回對方閃躲率(負值)
    if( inn + random(mk*2 + inn*2)  > random(-COMBAT_D->dodge_factor(target,"dodge")/2+target->query_int()*3/2))
    {
        // 增加素質對傷害的影響
        damage = COMBAT_D->Merits_damage(me,target,damage,"wit");
        target->receive_damage("hp", damage, me ); 
        message_vision(HIC"  只見$N一時反應不過來，慘叫一聲，被火龍給吞噬了！！"NOR,target);
        if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
        tell_object(me,HIY"("+damage+")"NOR);
        if(target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
        tell_object(target,HIR"("+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");
        message_vision("\n",target);
        if(wizardp(me) && me->query("env/debug")) tell_object(me,"  造成"+damage+"點傷害!!\n"); 
        COMBAT_D->report_status(target);         //顯示target狀態
    }
    else
        {
               message_vision(GRN"\n  只見$N踉蹌的閃過了火龍的追擊。\n"NOR,target);
        }
 } else message_vision(GRN"  只見火龍猛然的吞噬著$N，但似乎沒有造成$N絲毫的傷害。\n"NOR,target);

 if( random(40+inn) > 20 )
 {
         me->improve_spell("god-fire",inn/2+random(inn)+1);
 }
 if(random(2+mk/25)==0) me->start_busy(1);
// if(!target->is_fighting(me)) target->kill_ob(me);
// if(!me->is_fighting(target)) me->kill_ob(target);
}
