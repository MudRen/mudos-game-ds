// five-thunder (�����l�p)

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
        int cost;
        if(!me) return 0;
        cost=20+random(5);
        me->receive_damage("hp", cost );
        me->receive_damage("ap", cost );
        me->receive_damage("mp", cost );
        me->apply_condition("five-thunder", duration - 1);
        message_vision(HIB "���誺�Ѫũ��M�T�_�@�}���T�A�@�D��p�A�W$N�I�I\n" NOR,me );
        message_vision("�@�}�}�J����q$N���W�ǥX��......\n",me);
        if(me->query("hp") < cost)
        {
                me->die();
                duration =0;
        }
        if( !duration ) return 0;
        
        return CND_CONTINUE;
}

