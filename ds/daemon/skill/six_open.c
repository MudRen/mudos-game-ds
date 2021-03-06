/*
   Editor-Js@DS
   SK : 八極門之六大開
   用途: 製造慢性傷害
*/
// Last update Tmr 2006/10/12
// 調整傷害力公式，加上「閻王三點手」
        
#include <ansi.h>
#define SKILL_NAME "六大開"   
inherit SKILL;
inherit SSERVER;

string *actions=({
                     "攉打頂肘","抱打頂肘","單腿","胯打","翻身小纏","抱腿"
                 });

void clear(object me);
                         
int exert(object me, object target, string arg)
{
        int damage;
    int sk = me->query_skill("six_open");
        if(!target) target = offensive_target(me);  // 敵人
    if( !target )
        return notify_fail("你要對誰使出"+SKILL_NAME+"？\n");
    
    if(me->query_temp("SIX_OPEN_DAMAGE") )
        return notify_fail("你短時間內無法再使用六大開。\n");
    
    if(me->query("ap") < 200) return notify_fail("你的內勁不夠使出"+SKILL_NAME+"\n");
    if(!me->is_fighting()) return notify_fail(SKILL_NAME+"是一種戰鬥技能!\n");
    if(me->query_skill("bagi_fist")<100)
        return notify_fail("使用"+SKILL_NAME+"需要先精通八極拳法。\n");
    if(me->query_skill("horse-steps")<100)
        return notify_fail("使用"+SKILL_NAME+"需要深厚的八極扎馬。\n");
    if(me->query_skill("unarmed")<100)
        return notify_fail("使用"+SKILL_NAME+"需要熟練的空手搏擊技巧。\n");
    if(me->query_skill("parry")<70)
        return notify_fail("使用"+SKILL_NAME+"需要熟練的武器招架。\n");

     damage = me->query_damage()*2;
    damage -= target->query_armor() + random(target->query_armor());
        damage = COMBAT_D->Merits_damage(me, target, damage, "bar");
    
    message_vision(HIG "\n$N使出「六大開」強烈內勁，一股強勁而燥熱的螺蜁氣勁四散而出...\n" NOR,me,target);
    message_vision(HIG "$N一招"+ HIB "「"+ actions[random(sizeof(actions))] + "」"+HIG"，簡潔而迅速地挾著螺蜁勁狠狠擊向$n"HIG"胸前要害！！\n"NOR,me,target);

    // 攻擊命中
    if( damage > 0 &&
            ( random(sk*2) > COMBAT_D->attack_factor(me,"unarmed")*10/15
            || random(sk*2) > -COMBAT_D->dodge_factor(target,"dodge") ) ) {
          message_vision(HIR "$n"HIR"閃躲不及，狠狠被$N"HIR"擊中胸口，喀啦一聲響，竟是肋骨碎掉的聲音！！[" + damage +"]\n"
                       NOR,me,target);
        target->receive_damage("hp",damage,me);
          target->start_busy(1);
        me->start_busy(1);
        me->receive_damage("ap", 50, me);
        me->improve_skill("six_open",1 + random(me->query_con()) );
        // 加上condition
                  if(sk>=10) target->apply_condition("six_open_force", sk/10);
    } else {
        switch(random(3))
        {
        case 0:
            message_vision(HIW ""+target->query("name")+"在千釣一髮之際，閃開了"+me->query("name")+"猛烈的攻擊....\n" NOR,target,me);
            me->start_busy(2);
            break;
        case 1:
            message_vision(HIW ""+target->query("name")+"輕巧巧地跳了開去，躲開了這一次的攻勢....\n" NOR,target,me);
            me->start_busy(2);
            break;
        case 2:
            message_vision(HIW ""+target->query("name")+"「哇」一聲尖叫，抱著頭翻身滾了開去，躲開了這次的險些致命的攻擊...\n" NOR,target,me);
            me->start_busy(2);
            break;
        }
    }
        me->set_temp("SIX_OPEN_DAMAGE",1);
          if( me->query_bar() <= 5 )
                call_out("clear", 20-me->query_bar()*2 , me);
            else
                call_out("clear", 8 , me);

    return 1;
}

void clear(object me)
{
    if(!me) return;
        tell_object(me,"你之前因使用六大開所造成的身體傷害，已經恢復了。\n");
    me->delete_temp("SIX_OPEN_DAMAGE");
}
int improve_limite(object ob)
{
      return 100;
}

