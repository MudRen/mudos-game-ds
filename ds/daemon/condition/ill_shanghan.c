#include <ansi.h>

int update_condition(object me, int duration)
{
        if( duration < 1 ) return 0;

        me->receive_damage("hp", 1);
          me->improve_skill("strong-body", 1 + random(me->query_con()));
        message_vision(CYN"$N���F�ӧNŸ�A�Y���I�I���A�n���O�o�˴H�f�F�C\n" NOR,me);

        me->apply_condition("ill_shanghan", duration -1);

        return 1;
}

