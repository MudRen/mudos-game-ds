//�ѱ� - �Ӷ��Z

#include <ansi.h> 
#include <condition.h>

inherit F_CLEAN_UP;
int update_condition(object me, int duration)
{
        int add;
        if( !duration )
        {
                add = me->query_temp("addstr");
                tell_object(me,"�A�Pı�m"HIY" �� �� �Z"NOR" �n�����A���O�q�w�g�����F�E\n");
                me->add_temp("apply/str",-add);
                me->delete_temp("addstr");
                me->delete_temp("e_str");
                return 0;
        } 
        else
        {         
                me->apply_condition("addstr", duration-1 );
        }
        return 1;
}

