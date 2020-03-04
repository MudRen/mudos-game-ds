#include <ansi.h> 

int update_condition(object me, int duration)
{
    if( me->query_temp("CombatDanceStr") == 0 ) return 0;

    if( duration < 1 ) {
        tell_object(me,"你感覺戰舞給予你的力量已經消失了•\n");
        me->add_temp("apply/str", -me->query_temp("CombatDanceStr"));
        me->delete_temp("CombatDanceStr");
        return 0;
    } 

    me->apply_condition("CombatDanceStr", duration-1 );
    return 1;
}
