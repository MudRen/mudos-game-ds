//�ѱ� - �h�ƳZ

#include <ansi.h> 
#include <condition.h>

inherit F_CLEAN_UP;
int update_condition(object me, int duration)
{
        int add;

		// ���a�i�঳quit�L
		if(me->query_temp("adddex") == 0)
				return 0;

        if( !duration )
        {
                add = me->query_temp("adddex");
                tell_object(me,"�A�Pı�m"HIW" �h �� �Z"NOR" �n�����A���O�q�w�g�����F�E\n");
                me->add_temp("apply/dex",-add);
                me->delete_temp("adddex");
                return 0;
        } 

        me->apply_condition("adddex", duration-1 );
        return 1;
}

