//�ѱ� - �T�J�Z

#include <ansi.h> 
#include <condition.h>

inherit F_CLEAN_UP;
int update_condition(object me, int duration)
{
        int add;

		// ���a�i�঳quit�L
		if(me->query_temp("advkee") == 0)
				return 0;

        if( !duration )
        {
                tell_object(me,"�A�Pı�m"HIC"���@�Z"NOR"�n���ĪG�w�g�����F�E\n");
                me->delete_temp("advkee");
                return 0;
        } 

        add = me->query_temp("advkee");
		me->receive_heal("hp", add );	// ��_hp
		tell_object(me, "���b�A�ݵį��D�ޤW��"HIC"���@�Z"NOR"�A���w�w�a�v�ǧA���˶աC\n"NOR);

        me->apply_condition("advkee", duration-1 );
        return 1;
}

