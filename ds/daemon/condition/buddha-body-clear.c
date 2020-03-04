#include <ansi.h>

int update_condition(object me, int duration)
{
        if( !me->query_temp("buddha-body") ) return 0;

        if( duration < 1 ) {
                message_vision(HIM"$N�C�դ����i���C�C���h�F�C\n"NOR,me);
                me->add_temp("apply/sou", -me->query_temp("buddha-body") );
                me->add_temp("apply/wit", -me->query_temp("buddha-body") );
                me->delete_temp("buddha-body");
                me->delete_temp("fly");
                return 0;
        }
        me->apply_condition("buddha-body-clear", duration -1);
        return 1;
}
