/* aerial-dagger 飄渺匕法
 * advanced thief 門派技能
 * By Tmr 2002/04/04
 */
#include <ansi.h>
inherit SKILL;
inherit SSERVER;
mapping *action = ({
                       ([
                            "action": "$N握緊手中$w使出「煙雨瀰漫」，從另一方位斜斜朝$n"NOR"的$l刺去",
                            "damage":                10,
                            "dodge" :                8,
                            "parry" :                5,
                            "attact_type":  "bio",
                            "damage_type":  "刺傷",
                        ]),
                       ([
                            "action": "$N揮出手中$w使出一招「似霧像雲」，攻勢若隱若現，似乎正朝$n"NOR"的$l刺去",
                            "damage":                8,
                            "dodge" :                8,
                            "parry" :                5,
                            "attact_type":  "bio",
                            "damage_type":  "刺傷",
                        ]),
                       ([
                            "action": "$N手中$w"NOR"匕鋒閃爍，帶起一招「吞雲吐霧」趁$n"NOR"露出破綻，刺向$n"NOR"的$l刺去",
                            "damage":                12,
                            "dodge" :                8,
                            "parry" :                5,
                            "attact_type":  "bio",
                            "damage_type":  "刺傷",
                        ]),
                       ([
                            "action": "$N使出「霧裡看花」虛晃手上$w數下，趁$n"NOR"分心之際，猛地刺向$n"NOR"的$l刺去",
                            "damage":                12,
                            "dodge" :                8,
                            "parry" :                5,
                            "attact_type":  "bio",
                            "damage_type":  "刺傷",
                        ]),
                   });
void delay(object me,int cost);
int exert(object me, object target, string arg)
{
    object weapon;

    weapon=me->query_temp("weapon");
    if(arg=="off" )
    {
        if( me->query_skill_mapped("dagger")!="aerial-dagger")
            return notify_fail("你並沒有使用「飄渺匕法」\n");
        me->map_skill("dagger");
        me->reset_action();
        write("技能「飄渺匕法」已取消。\n");
        return 1;
    }
    if(!weapon)
        return notify_fail("你必須裝備匕首類武器。\n");
    if(weapon->query("skill_type")!="dagger")
        return notify_fail("你必須裝備匕首類武器。\n");
    if(me->query_skill_mapped("dagger")=="aerial-dagger")
        return notify_fail("你已經正在施展「飄渺匕法」了。\n");
    if(me->query("ap")<10 || me->query("hp")<10 )
        return notify_fail("你目前的身體狀況不好。\n");

    me->map_skill("dagger", "aerial-dagger");
    me->reset_action();
      message_vision(HIW"$N輕巧巧將手中"+weapon->name()+HIW"虛晃幾招，開始施展「飄渺匕法」。\n"NOR,me);
    me->receive_damage("ap",5);
    me->start_busy(1);

    return 1;
}

int valid_learn(object me) {    return 1;       }

mapping query_action(object me, object weapon)
{
    return action[random(sizeof(action))];
}

int practice_skill(object me) { return 1; }

