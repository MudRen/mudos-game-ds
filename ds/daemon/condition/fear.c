// ���߳N(fear)
// -Acme-
#include <command.h>
#include <ansi.h>

int update_condition(object me, int duration)
{

    if( duration < 1 ) {
        tell_object(me,"�Aı�o�A�Ѥ��Ȧa���ȡC\n");
        return 0;
    }

    message_vision(HIM"$N�߸̲��ͥ��j�����߷P�A�Q�n�k���o�Ӧa��C\n"NOR, me);
    GO_CMD->do_flee(me);
   me->start_busy(3);

    me->apply_condition("fear", duration-1);
    return 1;
}
