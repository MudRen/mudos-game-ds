//�ѱ� - �T�J�Z

#include <ansi.h> 
#include <condition.h>

inherit F_CLEAN_UP;
int update_condition(object me, int duration)
{
        int add;

		// ���a�i�঳quit�L
		if(me->query_temp("addcon") == 0)
				return 0;

        if( !duration )
        {
                add = me->query_temp("addcon");
                tell_object(me,"�A�Pı�m"HIG" �T �J �Z "NOR"�n�����A���O�q�w�g�����F�E\n");
                me->add_temp("apply/con",-add);
                me->delete_temp("addcon");
                return 0;
        } 

        me->apply_condition("addcon", duration-1 );
        return 1;
}

