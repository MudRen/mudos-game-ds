// ���Ѥ�u���j�}�v���l -Tmr 2002/02/24-
// six_open_force.c

#include <ansi.h>

int update_condition(object me, int duration)
{
        int r=me->query_temp("six_open_force");
        if( r > 0)
        {
                duration -=r;
                me->delete_temp("six_open+force");
        }

        if( duration < 1 ) return 0;

        me->receive_damage("hp", 50);
        me->start_busy(1);
         message_vision(HIR "$N"HIR"�ݤf�}�H���ذ����ۡu���j�}�v���t�l�ɵo�}�ӡA�h�o�ۤ��X�n....\n" NOR,me);

        me->apply_condition("six_open_force", duration -1);
        if( duration < 1 ) return 0;
        return 1;
}

