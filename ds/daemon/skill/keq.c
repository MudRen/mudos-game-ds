//打壞eq拳法 (keq) 測試版 Wilfred@DS

#include <ansi.h>
inherit SKILL;
inherit SSERVER;

mapping *action = ({
                       ([
                            "action": YEL"$N用keq拳法擊向$n$l"NOR,
                            "damage":                25,
                            "dodge" :                15,
                            "parry" :                20,
                            "attact_type":  "durable",    // 類型 打壞 eq
                            "damage_type":  "搥傷",
                        ]),

                   });

int exert(object me, object target, string arg)
{
    string msg;
    object weapon;

    weapon=me->query_temp("weapon");
    if(arg=="off" )
    {
        if( me->query_skill_mapped("unarmed")!="keq")
            return notify_fail("你並沒有施展keq拳法\n");
        me->map_skill("unarmed");
        me->reset_action();
        message_vision(HIW "$N停止使用keq拳法。\n"NOR,me);
        return 1;
    }
    if(weapon && weapon->query("skill_type")!="unarmed")
        return notify_fail("你拿著此類武器，無法施展keq拳法。\n");
    if(me->query_skill_mapped("unarmed")=="keq")
        return notify_fail("你已經在施展keq拳法。\n");
    me->map_skill("unarmed", "keq");
    me->reset_action();
    message_vision(HIW "$N開始施展keq拳法。\n"NOR,me);

    return 1;
}

mapping query_action(object me, object weapon)
{  return action[random(sizeof(action))]; }

int practice_skill(object me) { return 1; }

