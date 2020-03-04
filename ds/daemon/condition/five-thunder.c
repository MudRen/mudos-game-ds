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
         message_vision(HIB "���誺�Ѫũ��M�T�_�@�}���T�A�@�D��p�A�W$N"HIB"�I�I\n" NOR,me );
          message_vision(HIC "�@�}�}�J����q$N"HIC"���W�ǥX��...\n" NOR ,me);
        if( duration < 1 ) return 0;

        return CND_CONTINUE;
}

