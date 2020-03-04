#include <ansi.h> 

int update_condition(object me, int duration)
{
    if( me->query_temp("CombatDanceArmor") == 0 ) return 0;

    if( duration < 1 ) {
        tell_object(me,"你感覺戰舞給予你的防禦力量已經消失了•\n");
        me->add_temp("apply/armor", -me->query_temp("CombatDanceArmor"));
        me->delete_temp("CombatDanceArmor");
        return 0;
    } 

    me->apply_condition("CombatDanceArmor", duration-1 );
    return 1;
}
