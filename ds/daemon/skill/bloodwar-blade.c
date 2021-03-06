/*
血戰十式 少帥軍基本刀法
1. 兩軍對壘     2. 鋒芒畢露
3. 輕騎突出     4. 探囊取物
5. 一戰功成     6. 批亢搗虛
7. 兵無常勢     8. 死生存亡
9. 強而避之     10. 君臨天下

Tmr 2006/11/22

*/
#include <ansi.h>
inherit SKILL;
inherit SSERVER;

#define SKILL_NAME "bloodwar-blade"
        
void delay(object me);

mapping *action = ({
                       ([
                            "action": "$N擺\出"HIR"【"NOR"兩軍對壘"HIR"】"NOR"架勢，肅殺的氣氛從$w"NOR"的刀尖微微冒出，忽地一刀砍向$n"NOR"的$l",
                            "damage":                10,
                            "attact_type":  "bar",
                            "damage_type":  "砍傷",
                        ]),
                       ([
                            "action": "$N刀身殺氣騰騰，使出"HIR"【"NOR"鋒芒畢露"HIR"】"NOR"一刀往$n"NOR"的$l砍去",
                            "damage":                15,
                            "attact_type":  "bar",
                            "damage_type":  "砍傷",
                        ]),
                       ([
                            "action": "$N使出"HIR"【"NOR"輕騎突出"HIR"】"NOR"，$w"NOR"從腰間出刀假作搗往敵人胸口，但忽化成側劈硬生生砍向$n"NOR"的$l",
                            "damage":                10,
                            "attact_type":  "bar",
                            "damage_type":  "劈傷",
                        ]),
                       ([
                            "action": "$N忽然欺近身去，使出"HIR"【"NOR"探囊取物"HIR"】"NOR"，$w"NOR"刀招運轉如意，刷地一聲劈向$n"NOR"的$l",
                            "damage":                15,
                            "attact_type":  "bar",
                            "damage_type":  "劈傷",
                        ]),                   
                       ([
                            "action": "$N哈哈大笑，身隨意轉使出"HIR"【"NOR"一戰功\成"HIR"】"NOR"，手中$w"NOR"一往無悔地砍向$n"NOR"的$l",
                            "damage":                10,
                            "attact_type":  "bar",
                            "damage_type":  "砍傷",
                        ]),
                       ([
                            "action": "$N奇招層出不窮，使出"HIR"【"NOR"批亢搗虛"HIR"】"NOR"，手中$w"NOR"大無畏地硬是往$n"NOR"的$l劈去",
                            "damage":                15,
                            "attact_type":  "bar",
                            "damage_type":  "劈傷",
                        ]),                   
                         ([
                            "action": "$N刀招忽變使出"HIR"【"NOR"兵無常勢"HIR"】"NOR"，不停舞弄手中$w"NOR"，接著一瞬間劈出三刀都往$n"NOR"的$l砍去",
                            "damage":                10,
                            "attact_type":  "bar",
                            "damage_type":  "砍傷",
                        ]),
                       ([
                            "action": "只見$N忽陷險境之際使出"HIR"【"NOR"死生存亡"HIR"】"NOR"，手中$w"NOR"鋒銳異常，簡簡單單就是一刀往$n"NOR"的$l劈去",
                            "damage":                15,
                            "attact_type":  "bar",
                            "damage_type":  "劈傷",
                        ]),                         
                       });


void improve_skill(object me) {
    me->improve_skill(SKILL_NAME, 1 + random(me->query_int()/2));
    me->improve_skill("blade",1 + random(me->query_int()/2));
}

/* 武器損傷 */
void damage_weapon(object me) {
    if( objectp(me->query_temp("weapon")) )
        me->query_temp("weapon")->attack(); // wp 損壞率 add by wilfred
}

/* 判斷是否需要示傷害數字 */
void show_damage(object me, object target,int damage) {
    if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
        tell_object(me,HIY"("+damage+")"NOR);
    if(target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
        tell_object(target,HIR"("+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");
    if(wizardp(me) && me->query("env/debug"))
        tell_object(me,"  造成"+damage+"點傷害!!\n");
}

/* 判斷是否還未引發戰鬥 */
void check_combat(object me, object target) {
    if( !objectp(me) ) return;
    if( !objectp(target) ) return;
    if(!me->is_fighting(target)) me->kill_ob(target);
    if(!target->is_fighting(me)) target->kill_ob(me);
}

int get_tiger_damage(object me, object target)
{
     int damage;
    damage = me->query_skill(SKILL_NAME) + me->query_damage();
    damage = damage + random(damage/2);
    damage = damage - target->query_armor()/3 - random(target->query_armor()/3);

    return COMBAT_D->Merits_damage(me, target, damage, "bar");
}

void clear(object me){
        if( !objectp(me) ) return;
        tell_object(me,"你使用「君臨天下」的損害已經恢復了。\n");

        me->delete_temp("ARMY_BLOODWAR_BLADE");
}


/* 君臨天下 特攻 */
void do_tiger_attack(object me, object target) {

    object weapon;
    int damage, target_d,sk;
    string msg;

        me->start_busy(1);

     me->receive_damage("ap", 50, me);
        me->set_temp("ARMY_BLOODWAR_BLADE",1);

    weapon=me->query_temp("weapon");
    msg = HIY "\n$N大喝一聲使出【君臨天下】，手中" + weapon->query("name") + HIY "黃光陣陣，鋒芒畢露，接著「涮」地一刀狠狠劈向$n\n"NOR;

    damage = get_tiger_damage(me, target);
    if( damage <= 0 ) {
        msg += HIW "可是這一刀被看穿了，$n" HIW "避開這次攻擊...\n" NOR;
        message_vision(msg, me, target);
        check_combat(me, target);
        return;
    }

    target_d = -COMBAT_D->dodge_factor(target,"dodge")*10/15;
    sk = me->query_skill(SKILL_NAME);
    if( sk + random(sk/2) > random(target_d) ) {
        target->receive_damage("hp",damage,me);

        msg += HIR "$n"HIR"身中此刀，急退三步，身上傷口猶如血注﹗！" NOR;
        message_vision(msg, me, target);
        damage_weapon(me);                      // 武器損傷
        show_damage(me, target, damage);        // 顯示傷害數字
        message_vision("\n", me);
        COMBAT_D->report_status(target);
        improve_skill(me);
    } else {
        msg += HIW"可是被$n" HIW "躲了開去...\n" NOR;
        message_vision(msg, me, target);
    }
        call_out("clear", 8, me);
}


int exert(object me, object target, string arg)
{
     int sk;
    object weapon;
    sk = me->query_skill(SKILL_NAME);
    weapon=me->query_temp("weapon");
    if( me->is_ghost() ) return notify_fail("你已經死了，請快點去復活吧。\n");
    if (!weapon) return notify_fail("你手中必須有刀才能施展「血戰十式」。\n");
    if(weapon->query("skill_type")!="blade") return notify_fail("你手中必須有刀才能施展「血戰十式」。\n");

    if(arg=="off" )
    {
        if( me->query_skill_mapped("blade") != SKILL_NAME)
            return notify_fail("你並沒有使用「血戰十式」。\n");
        me->map_skill("blade");
        me->reset_action();
        write("技能「血戰十式」已取消。\n");
        return 1;
    }

    if(me->query("ap")<10 || me->query("hp")<10) return notify_fail("你的身體狀況無法使用「血戰十式」。\n");

    //第二次exert
    if(me->query_skill_mapped("blade")==SKILL_NAME)
    {
        if( !target ) target = offensive_target(me);
        if (!me->is_fighting())
            return notify_fail("你已正在施展「血戰十式」了。\n");
        if (me->query_skill(SKILL_NAME) < 50)
            return notify_fail("你目前還無法使出「君臨天下」的殺招。\n");
        if(me->query("ap") < 100)
            return notify_fail("你目前的內勁不足，無法使出「君臨天下」的殺招。\n");
            if(me->query_temp("ARMY_BLOODWAR_BLADE") )
            return notify_fail("你短時間內無法再使用「君臨天下」。\n");

        //攻擊性的要特別注意要加下面兩行.
        if(!me->can_fight(target)) return me->can_fight(target);
        if(!me->is_fighting(target) ) return notify_fail("你並沒有和對方在戰鬥中。\n");

        do_tiger_attack(me, target); // 特攻 君臨天下

        return 1;
    }

if(!me->skill_active( SKILL_NAME,(: call_other, __FILE__, "delay", me ,5:), 10)) return notify_fail("血戰十式的動作還沒完成。\n");
    me->map_skill("blade", SKILL_NAME);
    me->reset_action();
    message_vision("$N刀招一變，開始施展起「血戰十式」了。\n"NOR,me);
    me->receive_damage("ap",10);
    me->start_busy(2);
    //      me->start_call_out( (: call_other, __FILE__, "delay", me ,5:), 10);
    return 1;
}

void delay(object me)
{
    object weapon;
    if( !me ) return;

    weapon=me->query_temp( "weapon" );

    if( !weapon || weapon->query("skill_type") != "blade" )
    {
        me->map_skill("blade");
        me->reset_action();
        return;
    }

    if( me->query_skill_mapped("blade")!=SKILL_NAME )
    {
        return;
    }
    if( me->query("ap")<10 )
    {
        me->map_skill("blade");
        me->reset_action();
        message_vision("\n"HIW"$N"HIW"的體力不夠無法繼續施展血戰十式。\n"NOR,me);
        return ;
    }

    if( me->is_fighting() ) me->receive_damage("ap",5);
        me->skill_active( SKILL_NAME,(: call_other, __FILE__, "delay", me :), 8);
}

int valid_learn(object me) {    return 1;       }

mapping query_action(object me, object weapon)
{
    return action[random(sizeof(action))];
}

int practice_skill(object me) { return 1; }

int improve_limite(object ob)
{
     return 60 + ob->query_str();

}
