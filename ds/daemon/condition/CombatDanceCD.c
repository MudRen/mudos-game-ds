// �ԻR(combat dance) CD debuff 
// -Acme-

#include <ansi.h>

int update_condition(object me, int duration)
{
    if( duration < 1 ) {
        tell_object(me,"�Aı�o�A�S�Q���ԻR�F�C\n");
        return 0;
    }

    me->apply_condition("CombatDanceCD", duration-1);
    return 1;
}
