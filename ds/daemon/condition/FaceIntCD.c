#include <ansi.h>

int update_condition(object me, int duration)
{
    if( duration < 1 ) {
        tell_object(me,"你覺得你又想變麻花臉了。\n");
        return 0;
    }

    me->apply_condition("FaceIntCD", duration-1);
    return 1;
}
