// �H����
// tmr 2007/03/03

#include <ansi.h> 
#include <condition.h>

inherit F_CLEAN_UP;
int update_condition(object me, int duration)
{
        if( !duration )
        {
			    message_vision(  "$N�����@�}�ĳ¡A�Ы��b�ɪ��ĪG�]�����F�C\n" ,me);
                return 0;
        } 

        me->apply_condition("frost_dust", duration-1 );
        return 1;
}

