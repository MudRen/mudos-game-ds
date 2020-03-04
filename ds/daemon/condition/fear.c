// 恐懼術(fear)
// -Acme-
#include <command.h>
#include <ansi.h>

int update_condition(object me, int duration)
{

    if( duration < 1 ) {
        tell_object(me,"你覺得你天不怕地不怕。\n");
        return 0;
    }

    message_vision(HIM"$N心裡產生巨大的恐懼感，想要逃離這個地方。\n"NOR, me);
    GO_CMD->do_flee(me);
   me->start_busy(3);

    me->apply_condition("fear", duration-1);
    return 1;
}
