//�ѱ� - ���߳Z

#include <ansi.h> 
#include <condition.h>

inherit F_CLEAN_UP;
int update_condition(object me, int duration)
{
        int add;

		// ���a�i�঳quit�L
		if(me->query_temp("addint") == 0)
				return 0;

        if( !duration )
        {
                add = me->query_temp("addint");
                tell_object(me,"�A�Pı�m"HIW+BLK" �� �� �Z"NOR" �n�����A���O�q�w�g�����F�E\n");
                me->add_temp("apply/int",-add);
                me->delete_temp("addint");
                return 0;
        } 

        me->apply_condition("addint", duration-1 );
        return 1;
}

