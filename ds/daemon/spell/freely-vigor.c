// 邪極宗 魔功 - 魔氣縱橫 (freely-vigor)
// Tmr 2007/10/11

#include <ansi.h>
inherit SSERVER;
inherit SKILL;

int attack_b(object me, object target);

int cast(object me, object target)
{
     int sk,inn,cost;

    sk=me->query_spell("freely-vigor");
    inn=me->query_int();

    if(sk < 10)
        return notify_fail("你的「魔氣縱橫」還未成火侯，尚無能力使用。\n");
    if(me->query("ap") < 50 || me->query("mp") < 50 || me->query_temp("power_cast") )
        return notify_fail("你現在的身體狀況無法使用「魔氣縱橫」。\n");
    if( !target )
          target = offensive_target(me);
    if( !target )
        return notify_fail("沒有這個人可以攻擊。\n");
    if( !me->can_fight(target))
        return notify_fail("你無法與對方產生戰鬥。\n");
    if( !me->is_fighting(target) )
        return notify_fail("你並沒有與對方發生戰鬥。\n");
    
    message_vision( HBK"$N對著$n"HBK"施展魔門絕技" HIG "「魔氣縱橫」" HBK "，四週陰氣逐漸凝聚，散發出慘綠色光芒！！\n" NOR, me, target);
    cost = (sk*3 + inn)/6;
    me->start_busy(1);
    call_out("attack_b", 2,me,target);
    me->receive_damage("mp", cost);
    me->set_temp("power_cast", 1 + sk/20 );
    return 1;
}

int attack_b(object me,object target)
{
    int damage;
      int sk, inn;
        sk=me->query_spell("freely-vigor");
    inn=me->query_int();

    if(!me) {
         me->delete_temp("power_cast");
        return 0;
        }

    if(!me->query_temp("power_cast") || me->query_temp("power_cast") < 1)
    {
        message_vision(HIW"$N"HIW"因為受到創傷而亂了思緒, 無法順利施展下去。\n"NOR,me);
        return 1;
    }
    me->delete_temp("power_cast");

    if(!target)
        return notify_fail("目標消失了。\n");
    if( environment(me) != environment(target) )
        return notify_fail("目標離開了你的施法範圍。\n");

    if(random(target->query_skill("dodge")*2)/3+random(target->query_shield())+1 < random( sk*2 )/3+inn )
    {
        damage = me->query_damage()*2 + (sk + inn*2);
        damage -= target->query_shield();
        damage = COMBAT_D->Merits_damage(me,target,damage, "sou");

                if(damage < 1) damage = 1 + random(10) ;
        message_vision(HIG"魔氣縱橫"HIR"猶如強酸似腐蝕$n"HIR"血脈，$n"HIR"發出痛苦淒厲的叫聲！！("+ damage + ")\n"NOR,me,target);
        target->receive_damage("hp", damage, me);
            
                // 種魔
                CLASS_D("ancestor")->addMagic(me, target, damage, 2);

        target->start_busy(1);
    }
    else {
          message_vision(HIG"魔氣縱橫"NOR"凝聚不起來，無法對$n"NOR"造成任何傷害。\n"NOR,me,target);
    }

    if(!target->is_fighting(me)) target->kill_ob(me);
    if(!me->is_fighting(target)) me->kill_ob(target);
    me->improve_spell("freely-vigor", random(1+me->query_int()) );
}

int improve_limite(object ob)
{
    if(ob->query("int") < 60) return 90;
    
    return 100;
}

