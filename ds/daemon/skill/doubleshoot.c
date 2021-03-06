#include <ansi.h>
#define SKILL_NAME "雙重射擊"
inherit SKILL;
inherit SSERVER;


int exert(object me, object target,string dir)
{
    object weapon,arrow;
    string msg;
    int sk,skk;
    seteuid(getuid());

    if( !target ) target = offensive_target(me);
    if( !target ) return notify_fail("對誰施展"+SKILL_NAME+"?\n");
    if((int)me->query("ap") < 30 || (int)me->query("mp") < 30 )
        return notify_fail("你目前的身體狀況無法施展這麼劇烈的動作﹗\n");
    if(!me->can_fight(target))
        return me->can_fight(target);
    if( !weapon=me->query_temp("weapon") ) return notify_fail("你沒有武器如何施展"+SKILL_NAME+"？\n");
    if( weapon->query("skill_type")=="bow")
    {
        if( !arrow=present("arrow 2", me ) ) return notify_fail(" 你的箭不夠。\n");
    }
    else
    {
        if(!weapon->query("can_shoot"))
            return notify_fail("你目前使用的武器無法射擊。\n");
        if(weapon->query_temp("loaded") < 2 )
            return notify_fail("使用"+SKILL_NAME+"至少要兩發彈藥。\n");
    }
    message_vision(HIC"\n$N迅速的拿起"+weapon->name()+HIC", 施展"+SKILL_NAME+"。\n\n"+NOR,me,target);
    if(weapon->do_shoot(me,target))
    {
        me->receive_damage("ap",15);
        me->receive_damage("mp",10);
    }
    if(weapon->do_shoot(me,target))
    {
        me->receive_damage("ap",15);
        me->receive_damage("mp",10);
    }
    sk=me->query_skill("doubleshoot");
    skk=sk/2+random(sk);
    me->improve_skill("doubleshoot",1+random(me->query_int()/5));
    if(skk < 50 ) me->add_busy(1);
    return 1;
}


