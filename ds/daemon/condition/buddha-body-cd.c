#include <ansi.h>

int update_condition(object me, int duration)
{
        if( duration < 1 ) {
                tell_object(me,"�A�i�H�A�ϥΡu�ר�����v�F�C\n");
                return 0;
        }
        me->apply_condition("buddha-body-cd", duration -1);
        me->improve_skill("buddha-body", 1 + random(10) );
        return 1;
}

