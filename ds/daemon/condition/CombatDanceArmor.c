#include <ansi.h> 

int update_condition(object me, int duration)
{
    if( me->query_temp("CombatDanceArmor") == 0 ) return 0;

    if( duration < 1 ) {
        tell_object(me,"�A�Pı�ԻR�����A�����m�O�q�w�g�����F�E\n");
        me->add_temp("apply/armor", -me->query_temp("CombatDanceArmor"));
        me->delete_temp("CombatDanceArmor");
        return 0;
    } 

    me->apply_condition("CombatDanceArmor", duration-1 );
    return 1;
}
