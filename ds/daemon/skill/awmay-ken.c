//傲梅拳法 (awmay-ken) by tmr Sat Jan 1 2000

#include <ansi.h>
inherit SKILL;
inherit SSERVER;

mapping *action = ({
                       ([
                            "action": "$N一招「蒼松迎客」，雙拳右上左下直擊$n$l",
                            "damage":                20,
                            "dodge" :                10,
                            "parry" :                15,
                            "attact_type":  "bio",
                            "damage_type":  "搥傷",
                        ]),
                       ([
                            "action": "$N右拳在$n面前一晃，左拳一招「梅雪爭春」擊向$n$l",
                            "damage":                25,
                            "dodge" :                5,
                            "parry" :                20,
                            "attact_type":  "bio",
                            "damage_type":  "撞傷",
                        ]),
                       ([
                            "action": "$N陡地雙拳向著$n的$l要害快攻六拳，正是一招「梅花六出」",
                            "damage":                25,
                            "dodge" :                10,
                            "parry" :                20,
                            "attact_type":  "bio",
                            "damage_type":  "撞傷",
                        ]),
                       ([
                            "action": "$N一招「月色昏黃」，右臂在胸前轉了數圈，左拳陡地由圈子伸出擊向$n$l",
                            "damage":                20,
                            "dodge" :                10,
                            "parry" :                10,
                            "attact_type":  "bio",
                            "damage_type":  "撞傷",
                        ]),

                       ([
                            "action": "$N左右兩拳一招「暗香疏影」交錯攻向$n的$l要害",
                            "damage":                20,
                            "dodge" :                5,
                            "parry" :                5,
                            "attact_type":  "bio",
                            "damage_type":  "撞傷",
                        ]),

                       ([
                            "action": "$N施展快招「明駝西來」，雙拳一瞬間向著$n攻了十八拳！",
                            "damage":                25,
                            "dodge" :                5,
                            "parry" :                20,
                            "attact_type":  "bio",
                            "damage_type":  "撞傷",
                        ]),


                   });

mapping *s_action = ({
                         ([
                              "action":
                              HIW "忽然陣陣霜氣從$N雙拳冒出，正是傲梅拳法最強一招「傲寒天下」！\n\n"
                              +   "\t$N眼露寒光，氣勢萬千重重一拳擊向$n$l" NOR,
                              "damage":                120,
                              "dodge" :                30,
                              "parry" :                30,
                              "attact_type":  "bio",
                              "damage_type":  "撞傷",
                          ]),
                     });

int exert(object me, object target, string arg)
{
    string msg;
    object weapon;

    weapon=me->query_temp("weapon");
    if(arg=="off" )
    {
        if( me->query_skill_mapped("unarmed")!="awmay-ken")
            return notify_fail("你並沒有施展傲梅拳法\n");
        me->map_skill("unarmed");
        me->reset_action();
        write("技能[傲梅拳法]已取消。\n");
        return 1;
    }
    if(weapon && weapon->query("skill_type")!="unarmed")
        return notify_fail("你拿著此類武器，無法施展傲梅拳法。\n");

    if(me->query_skill_mapped("unarmed")=="awmay-ken")
        return notify_fail("你已經在施展傲梅拳法。\n");
    if(me->query("ap")<10 || me->query("hp")<10 )
        return notify_fail("你的身體狀況無法使用傲梅拳法。\n");
    me->map_skill("unarmed", "awmay-ken");
    me->reset_action();
    message_vision(HIW "$N雙拳陡地凝結一陣薄霜，開始施展了傲梅拳法！！。\n"NOR,me);
    me->receive_damage("ap",5);
    me->start_busy(1);

    return 1;
}



mapping query_action(object me, object weapon)
{
    if ( me->query_skill("awmay-ken") >= 80  && me->query("ap") > 500 && random(30)>=27 )
    {
        me->receive_damage("ap",30);
        return s_action[0];
    }
    else
        return action[random(sizeof(action))];
}

int practice_skill(object me) { return 1; }
