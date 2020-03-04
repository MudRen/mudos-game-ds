#include <ansi.h> 

int update_condition(object me, int duration)
{
    if( me->query_temp("CombatDanceDamage") == 0 ) return 0;

    if( duration < 1 ) {
        tell_object(me,"�A�Pı�ԻR�����A�������O�q�w�g�����F�E\n");
        me->add_temp("apply/damage", -me->query_temp("CombatDanceDamage"));
        me->delete_temp("CombatDanceDamage");
        return 0;
    } 

    me->apply_condition("CombatDanceDamage", duration-1 );
    return 1;
}
