//�ѱ� - �����@��Z

#include <ansi2.h> 
#include <condition.h>

inherit F_CLEAN_UP;
int update_condition(object me, int duration)
{
        int add;
        if( !duration )
        {
                add = me->query_temp("ghost");
                tell_object(me,"�A�Pı�m"HBWHT+BLK" �� �� �@ �� �Z "NOR"�n�����A���O�q�w�g�����F�E\n");
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

