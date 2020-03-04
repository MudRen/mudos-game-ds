// five-thunder

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
        if(!me) return 0;
          me->receive_damage("mp", 50+random(10) );
          me->receive_damage("ap", 50+random(10) );

        if( objectp( me->query_temp("five-thunder-caster")) ) {
          me->receive_damage("hp", 50+random(10), me->query_temp("five-thunder-caster") );
        } else  {
          me->receive_damage("hp", 50+random(10) );
        }
        me->apply_condition("five-thunder", duration - 1);
         message_vision(HIB "遠方的天空忽然響起一陣暴響，一道急雷劈上$N"HIB"！！\n" NOR,me );
          message_vision(HIC "一陣陣焦臭味從$N"HIC"身上傳出來...\n" NOR ,me);
        if( duration < 1 ) return 0;

        return CND_CONTINUE;
}


