#include <ansi.h> 

int update_condition(object me, int duration)
{
    if( me->query_temp("CombatDanceHit") == 0 ) return 0;

    if( duration < 1 ) {
        tell_object(me,"�A�Pı�ԻR�����A���R����O�w�g�����F�E\n");
        me->add_temp("apply/hit", -me->query_temp("CombatDanceHit"));
        me->delete_temp("CombatDanceHit");
        return 0;
    } 

    me->apply_condition("CombatDanceHit", duration-1 );
    return 1;
}
