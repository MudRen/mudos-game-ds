#include <ansi.h> 

int update_condition(object me, int duration)
{
    if( me->query_temp("CombatDanceDex") == 0 ) return 0;

    if( duration < 1 ) {
        tell_object(me,"�A�Pı�ԻR�����A���ӱ��w�g�����F�E\n");
        me->add_temp("apply/dex", -me->query_temp("CombatDanceDex"));
        me->delete_temp("CombatDanceDex");
        return 0;
    } 

    me->apply_condition("CombatDanceDex", duration-1 );
    return 1;
}
