#include <ansi.h> 

int update_condition(object me, int duration)
{
    if( me->query_temp("CombatDanceInt") == 0 ) return 0;

    if( duration < 1 ) {
        tell_object(me,"�A�Pı�ԻR�����A�����z�w�g�����F�E\n");
        me->add_temp("apply/int", -me->query_temp("CombatDanceInt"));
        me->delete_temp("CombatDanceInt");
        return 0;
    } 

    me->apply_condition("CombatDanceInt", duration-1 );
    return 1;
}
