//�ѱ� - �Ӷ��Z

#include <ansi.h> 
#include <condition.h>

inherit F_CLEAN_UP;
int update_condition(object me, int duration)
{
        int add;

		// ���a�i�঳quit�L
		if(me->query_temp("addstr") == 0)
				return 0;

        if( !duration )
        {
                add = me->query_temp("addstr");
                tell_object(me,"�A�Pı�m"HIY" �� �� �Z"NOR" �n�����A���O�q�w�g�����F�E\n");
                me->add_temp("apply/str",-add);
                me->delete_temp("addstr");
                return 0;
        } 

        me->apply_condition("addstr", duration-1 );
        return 1;
}

