/* 凌雲步法(reachcloud-steps)
 *  
 * Advanced Thief Dodge
 *
 */
#include <ansi.h>
inherit SKILL;

string *dodge_msg = ({
                         NOR"\n$n使出「雲蹤飄渺」，身形飄乎不定，使得$N的攻擊完全落空。\n"NOR,
                         NOR"\n$n縱身一躍，使出「幻影迷蹤」，$n以肉眼無法看清的驚人速度躲避了$N的攻擊。\n"NOR,
                         NOR"\n$n使出「風雲無定」，身法更快，四周猶如狂風吹襲，$n身形一挫閃開了$N的攻擊。\n"NOR,
                         NOR"\n只見$n身影飛快閃動，使出「行雲流水」，$n的身影如清湮飛逝一樣，閃開了$N攻擊。\n"NOR,

                     } );

int exert(object me, object target, string arg)
{

    if(arg=="off" )
    {
        if( me->query_skill_mapped("dodge")!="reachcloud-steps")
            return notify_fail("你並沒有使用「凌雲步法」。\n");
        me->map_skill("dodge");
        me->reset_action();
        write("技能「凌雲步法」已取消。\n");
        return 1;
    }

    if(me->query_skill("dodge")<20)
        return notify_fail("你的輕功\基礎不夠無法使用「凌雲步法」。\n");
    if(me->query_skill_mapped("dodge")=="reachcloud-steps")
        return notify_fail("你已經在使用「凌雲步法」。\n");
    if(me->query("ap")<10 || me->query("hp")<10)
        return notify_fail("你目前的身體狀況無法使用「凌雲步法」。\n");
    me->map_skill("dodge", "reachcloud-steps");
    me->reset_action();
    message_vision(HIC"$N身輕若羽，靈巧地翻了幾個觔斗，開始施展起凌雲步法。\n"NOR,me);
    me->receive_damage("ap",10);
    me->start_busy(1);
    return 1;
}

int valid_learn(object me) {    return 1;       }
string query_dodge_msg(string limb)
{
    return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me) { return 1; }
int improve_limite(object ob)
{
    return 100;  // 可以升到100級 by -Acme-
/*
    int a=ob->query_skill("reachcloud-steps");
    a=a+ob->query_int();
    if(a > 80) a=80;
    return a;
*/
}

