//�ѱ� - �T�J�Z

#include <ansi.h> 
#include <condition.h>

inherit F_CLEAN_UP;
int update_condition(object me, int duration)
{
        int add;
        if( !duration )
        {
                add = me->query_temp("addcon");
                tell_object(me,"�A�Pı�m"HIG" �T �J �Z "NOR"�n�����A���O�q�w�g�����F�E\n");
                me->add_temp("apply/con",-add);
                me->delete_temp("addcon");
                me->delete_temp("e_con");
                return 0;
        } 
        else
        {         
                me->apply_condition("addcon", duration-1 );
        }
        return 1;
}

