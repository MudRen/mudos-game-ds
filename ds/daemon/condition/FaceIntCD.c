#include <ansi.h>

int update_condition(object me, int duration)
{
    if( duration < 1 ) {
        tell_object(me,"�Aı�o�A�S�Q�ܳª��y�F�C\n");
        return 0;
    }

    me->apply_condition("FaceIntCD", duration-1);
    return 1;
}
