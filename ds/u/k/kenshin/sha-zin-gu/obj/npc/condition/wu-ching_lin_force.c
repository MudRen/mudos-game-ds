#include <ansi.h>

int update_condition(object me, int duration)
{
        int r=me->query_temp("wu-ching_lin_force");
        if( r > 0)
        {
                duration -=r;
                me->delete_temp("wu-ching_lin+force");
        }

        if( duration < 1 ) return 0;

        me->receive_damage("hp", 30);
        me->start_busy(1);
        message_vision(HIR "$N�餺�ٴݯd�۹���M���ͭ����x�L�A�h�W�����I�I\n" NOR,me);
        me->apply_condition("wu-ching_lin", duration -1);
        if( duration < 1 ) return 0;
        return 1;
}

