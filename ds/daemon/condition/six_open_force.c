// 李書文「六大開」內勁 -Tmr 2002/02/24-
// six_open_force.c

#include <ansi.h>

int update_condition(object me, int duration)
{
        int r=me->query_temp("six_open_force");
        if( r > 0)
        {
                duration -=r;
                me->delete_temp("six_open+force");
        }

        if( duration < 1 ) return 0;

        me->receive_damage("hp", 50);
        me->start_busy(1);
         message_vision(HIR "$N"HIR"胸口破碎的肋骨挾著「六大開」的暗勁暴發開來，痛得喊不出聲....\n" NOR,me);

        me->apply_condition("six_open_force", duration -1);
        if( duration < 1 ) return 0;
        return 1;
}

