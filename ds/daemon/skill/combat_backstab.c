#include <ansi.h>
#define SKILL_NAME "戰鬥背刺"
inherit SKILL;
inherit SSERVER;

int exert(object me, object target,string dir)
{
    int damage,sk,c;
    int cost;
    object weapon;
    if(!me) return 0;
    if(!me->is_fighting()) return notify_fail(SKILL_NAME+"要在戰鬥中才能使用!\n");
    if( me->query("class2") != "thief" ) return notify_fail("要進階小偷才能使用喔！\n");
    if( !target ) target = offensive_target(me);
    if( !target ) return notify_fail("對誰施展"+SKILL_NAME+"?\n");
    if( !living(target) || target->is_corpse() )
        return notify_fail("你瞎了喔?!?這不是你應打的啦。\n");
    //        if( userp(me) && !wizardp(me) ) return notify_fail("A testing skills.\n");
    if((int)me->query("mp") < 75 || (int)me->query("ap") < 75 )
        return notify_fail("你目前的身體狀況無法使用這麼劇烈的武功\﹗\n");
    if(!weapon=me->query_temp("weapon")) return notify_fail("你手中沒有武器不能背刺。\n");
    if(!weapon->can_stab()) return notify_fail("你所使用的武器不適合用來背刺。\n");
    //	if(!me->can_fight(target))
    //		return me->can_fight(target);

    sk=me->query_skill("combat_backstab");
    cost = me->query("level")/2+sk/2;
    c=target->query_armor();
    message_vision("\n"HIW" 『嘿∼∼』 $N"HIW"冷笑一聲之後突然消失了蹤影，瞬間出現在$n"HIW"的身後!!\n"NOR,me,target);
    me->receive_damage("mp", cost);
    me->receive_damage("ap", cost);
    me->add_busy(3);
    if( random(me->query_dex()*3) < random(target->query_dex()+target->query_skill("dodge")))
    {
        message_vision("\n"HIW"$N迅速的將手中的"+weapon->name()+HIW"刺向$n"HIW"的身體，但是被$n"HIW"一個轉身閃了過去!!\n"NOR,me,target);
        return 1;
    }
    else
    {
        damage = me->query_damage()*2+sk/2;
        damage = damage + random(damage/2)+(int)weapon->query("backstab_bonus");
        damage = damage - c/2 -random(c/2);
        damage = COMBAT_D->Merits_damage(me,target,damage,"bar");
        message_vision("\n"HIW"$N迅速的將手中的"+weapon->name()+HIW"刺向$n"HIW"的身體，$n"HIW"慘叫一聲，"HIR"鮮血從傷口中泉湧而出!!\n"NOR,me,target);
        target->receive_damage("hp", damage,me);
        COMBAT_D->report_status(target);
        if(wizardp(me) && me->query("env/debug")) tell_object(me,"["+me->name()+"此次戰鬥背刺 damage: "+damage+"]\n");
        me->improve_skill("combat_backstab", 1+random(sk/2)+random(me->query("level")));
    }

    return 1;
}


