// �H����
// tmr 2007/03/03

#include <ansi.h> 
#include <condition.h>

inherit F_CLEAN_UP;
int update_condition(object me, int duration)
{
		// ���a�i�঳quit�L
		if( !me->query_temp("pure-energy/threshing") )
				return 0;

        if( !duration )
        {
			    message_vision(  "$N�����@�}�ĳ¡A���U���ɪ��ĪG�]�����F�C\n" ,me);
                  me->add_temp("apply/damage",-me->query_temp("pure-energy/threshing"));
			    me->delete_temp("pure-energy/threshing");
                return 0;
        } 

        me->apply_condition("frost_threshing", duration-1 );
        return 1;
}

