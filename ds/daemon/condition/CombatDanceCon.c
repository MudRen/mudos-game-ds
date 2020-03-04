#include <ansi.h> 

int update_condition(object me, int duration)
{
    if( me->query_temp("CombatDanceCon") == 0 ) return 0;

    if( duration < 1 ) {
        tell_object(me,"你感覺戰舞給予你的體質已經消失了•\n");
        me->add_temp("apply/con", -me->query_temp("CombatDanceCon"));
        me->delete_temp("CombatDanceCon");
        return 0;
    } 

    me->apply_condition("CombatDanceCon", duration-1 );
    return 1;
}
