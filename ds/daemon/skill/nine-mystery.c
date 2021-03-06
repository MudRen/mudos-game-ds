// 九玄大法 (nine-mystery)
// Tmr 2006/11/22

#include <ansi.h>
#define SKILL_NAME "nine-mystery"
        
inherit SKILL;


int exert(object me,object target, string arg)
{
    int force,sk,heal;

    force=me->query_skill("force",2);
    sk=me->query_skill(SKILL_NAME,2);
    heal=(force+sk)/2;

    //療傷功能
    if(arg =="heal" )
    {
        if( me->query_skill_mapped("force")==SKILL_NAME) return notify_fail("你正在修煉九玄大法。\n");
        if(me->query("hp") >= me->query("max_hp") ) return notify_fail("你的健康狀況已達顛峰。\n"); 
        if(me->query("ap") < heal/2 ) return notify_fail("你目前的身體狀況，不能使用療傷功\能。\n");
        if (me->is_fighting() ) return notify_fail("你正忙著戰鬥，沒有空療傷");

        message_vision( "$N使出九玄大法"HIW"真氣療傷"NOR"，進入先天呼吸，運息療傷。\n" ,me); 
        me->receive_damage("ap", heal/2);
                me->receive_heal("hp", heal);
        me->start_busy(1);
        me->improve_skill(SKILL_NAME,1+random(force/4)+me->query_int()/5 );
        me->improve_skill("force",1+random(me->query("level"))+me->query_int()/5 );
        return 1;
    }

    return notify_fail("九玄大法的功\能有：heal 。\n");

}

int valid_learn(object me)
{
    return 1;
}

int practice_skill(object me)
{
    return 1;
}



