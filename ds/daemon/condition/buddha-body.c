#include <ansi.h>

int update_condition(object me, int duration)
{
        if( duration < 1 ) {
                tell_object(me,"你可以再使用「肉身成佛」了。\n");
                return 0;
        }
        me->apply_condition("buddha-body", duration -1);
        me->improve_skill("buddha-body", 1 + random(10) );
        return 1;
}
