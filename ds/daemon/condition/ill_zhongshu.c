#include <ansi.h>

int update_condition(object me, int duration)
{
        if( duration < 1 ) return 0;

        me->receive_damage("hp", 1);
          me->improve_skill("strong-body", 1 + random(me->query_con()));
        message_vision(CYN"$N頭重腳輕，腦門發熱，看來是中暑了。\n" NOR,me);

        me->apply_condition("ill_zhongshu", duration -1);

        return 1;
}

