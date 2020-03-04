//天梟 - 鬼陰世精訣

#include <ansi2.h> 
#include <condition.h>

inherit F_CLEAN_UP;
int update_condition(object me, int duration)
{
        int add;
        if( !duration )
        {
                add = me->query_temp("ghost");
                tell_object(me,"你感覺《"HBWHT+BLK" 鬼 陰 世 精 訣 "NOR"》給予你的力量已經消失了•\n");
                me->add_temp("apply/damage",-add);
                me->add_temp("apply/armor",-add);
                me->delete_temp("ghost");
                me->delete_temp("d_a_up");
                return 0;
        } 
        else
        {         
                me->apply_condition("ghost", duration-1 );
        }
        return 1;
}

