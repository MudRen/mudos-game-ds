/*
天雷劫數 (thunder-doom) - 寒澈派(frost) 進階技能
Tmr 2008/02/02
*/

#include <ansi.h>

#define SKILL_NAME "thunder-doom"
#define MIN_DAMAGE 60
#define MAX_DAMAGE 100

inherit SSERVER;
inherit SKILL;

int cast_delay(object me);

int cast(object me, object target)
{
    int skill, cost;
    object *targets;
    targets = me->query_enemy();

    skill = me->query_spell(SKILL_NAME);
    cost = 30 + skill/3;

        if( !me->is_fighting() )
        return notify_fail("你並沒有在戰鬥中。\n");
    if ( sizeof(targets) < 0 )
        return notify_fail("你沒有可以攻擊的對像。\n");
    if ( me->query("mp") < cost )
        return notify_fail("你的法力不足，無法施法。\n");

    if (userp(me))
        me->start_busy(1);
    else
        me->start_busy(2);
    message_vision(HBK"$N念咒施展"HIC"『天雷劫數』"HBK"，召換雷雨之力，只見天空烏雲密佈，雷聲轟轟。\n"NOR, me, target);
    me->receive_damage("mp", cost);
call_out( (:cast_delay, me:), 2);

    return 1;
}

int getDamageWeight(object me)
{
    int bonus;
    // 每5級加3%
    bonus = (me->query_spell(SKILL_NAME)/5) * 3;
    return (MIN_DAMAGE + bonus) + random(MAX_DAMAGE - MIN_DAMAGE);
}

int getShield(object target)
{
    return target->query_shield() - random(target->query_shield()/2);
}

int getDamage(object me, object target)
{
        int damage;
        object symbol;
        // 加上 int
        damage = me->query_damage() + me->query_int()*2;
        if ( objectp(symbol=present("__LIFE_DEATH_SYMBOL_", me)) )
                damage += symbol->query("power")*3/2;
        damage = damage * getDamageWeight(me)/100;
        damage -= getShield(target);
        if ( damage < 1 )
        damage = 1;
        // 增加素質對傷害的影響
        return COMBAT_D->Merits_damage(me, target, damage,"wit");
}

void show_damage(object me, object target, int damage)
{
    if ( me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
        tell_object(me,HIY"( 傷害: "+damage+")"NOR);
    if ( target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
        tell_object(target,HIR"( 傷害: "+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");
    if (wizardp(me) && me->query("env/debug"))
        tell_object(me,"(debug):  造成"+damage+"點傷害!!\n");
}

// 電殛機率：技能等級40時為10%，每3級增加3%，最高機率到70%。
void do_attack(object me, object target)
{
    int  sk_lv, chance, damage;
    sk_lv = me->query_spell(SKILL_NAME);
    chance = 10 + (sk_lv-40)/3*3;
    if ( chance < random(100) )
        return; // nothing happen
    damage = getDamage(me, target) * 6/10; // 60%
    if (damage < 1) damage = 1;
    message_vision(RED"一陣"HIB"暴響"NOR RED"從$N體內傳出來，造成更嚴重的傷害！！"NOR,target);
        show_damage(me, target, damage);
    target->receive_damage("hp", damage, me );
    message_vision("\n", me, target);
}

int doAttack(object me, object target)
{
    int probit, damage;
    int sk_lv, hit;
    object symbol;

    sk_lv = me->query_spell(SKILL_NAME);
    probit = sk_lv + me->query_int();
    probit -= random(target->query_skill("dodge")+target->query_dex());
    hit =  probit > random(100) || target->is_busy() ;

    if ( !hit ) {
        if ( me->query_condition("frost_dust")
                && me->query_skill("pure-energy")/3 > random(100)  // 33%
                && 50 > random(100)   // 50%
           ) {
            // dust_clean 二次再命中
            hit = 1;
            message_vision(HIB"$N塵垢淨盡，身上發出低沉而歷久不歇的隆隆聲！！"NOR,me);
        }
    }


    if ( hit )
    {
        damage = getDamage(me, target);
        if ( objectp(symbol=present("__LIFE_DEATH_SYMBOL_", me)) ) {
            // add harvest by tmr 2007/03/03
            if ( me->query_condition("frost_harvest") && me->query_skill("pure-energy")/2 > random(100) ) {
                message_vision(HIC"$N全身淡淡寒氣飄逸，一道"BLU"天雷"HIC"伴著片薄冰竄出，轟隆聲響中轉瞬間就打上$n"HIC"！！"NOR,me, target);
            } else {
                symbol->add_amount(-1);    // 減少生死符
                message_vision(HIC"一道"BLU"天雷"HIC"伴著片薄冰竄出，轟隆聲響中轉瞬間就打上$N"HIC"！！"NOR,target);
            }
        } else {
            message_vision(HIC"一道"BLU"天雷"HIC"竄出，轟隆聲響中轉瞬間就打上$N"HIC"！！"NOR,target);
        }
        target->receive_damage("hp", damage, me );
        show_damage(me, target, damage);
        message_vision("\n", me, target);
        // 電殛
          if (sk_lv >= 40)
            do_attack(me, target);

        COMBAT_D->report_status(target);         //顯示target狀態

        me->improve_spell(SKILL_NAME, 1 + random(me->query_int()/4) );
    }
    else
    {
        message_vision(GRN"但是什麼事也沒有發生...\n"NOR,target);
        me->improve_spell(SKILL_NAME, 1 + random(me->query_int()/12) );
    }

    if ( !target->is_fighting(me) )
        target->kill_ob(me);
    if ( !me->is_fighting(target) )
        me->kill_ob(target);

    return 1;
}


int cast_delay(object me)
{
    object *targets;

    int i, sz, ct;
    if ( !me )
        return 0;
    targets = me->query_enemy();
    sz = sizeof(targets);
    if (sz<0)
        return notify_fail("你沒有任何可以攻擊的對像。\n");
    // 最多四個敵人
    for (i=0, ct =0 ;i<sz && ct < 4; i++) {
        if ( !targets[i] ) continue;
        if ( environment(me) != environment(targets[i]) ) continue;

        doAttack(me, targets[i]);
        ct++;
    }

    return 1;
}

