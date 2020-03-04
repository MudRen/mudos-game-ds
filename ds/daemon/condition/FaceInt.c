#include <ansi.h> 

int update_condition(object me, int duration)
{
    if( me->query_temp("FaceInt") == 0 ) return 0;

    if( duration < 1 ) {
        tell_object(me,"你感覺麻花臉譜給予你的智慧已經消失了•\n");
        me->add_temp("apply/int", -me->query_temp("FaceInt"));
        me->delete_temp("FaceInt");
        return 0;
    } 

    me->apply_condition("FaceInt", duration-1 );
    return 1;
}
