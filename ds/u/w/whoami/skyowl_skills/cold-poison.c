//�_���H�r(cold-poison)          sk 20  ����ʫd��ĤH ap & mp & hp            (�C���d�� sk*2) 
#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
        int anti = me->query_skill("anti_poison"),
            damage = me->query_temp("shouyu-poison/cold-poison/effect");
        if( !duration )
        {
                tell_object(me,HIB"�A���W�ݾl���_���H�r�r�ʮ����F�C\n"NOR);
                me->delete_temp("conditions/cold-poison");
                me->delete_temp("shouyu-poison/cold-poison/effect");
                return 0;
        } else 
        {
                if(random(8+duration)<random(5))
                {
                        me->apply_condition("cold-poison", duration);
                        return 1;
                }
 //        if( !living(me) ) {
//                message("vision",HIW + me->name() + "���o�ݡA�������W�@�h�����������C\n"NOR, environment(me), me);
//        }
//        else {
                tell_object(me, HIW "���M�@�ѴH��S���B�b�A�`�ۤ��u�A���t�L�۪��g�J�ݽ��A�A�����H�r�o�@�F�I\n" NOR );
                tell_room(environment(me), HIW + me->name() + "�����oŸ�A�����ست��T�A�L�o����A�L�B�]���F�A�y�⺥���ѫC�ӥաC\n"NOR,({me}));
//                }
                damage *= 2;
                damage -= random(anti/4);
                if( damage < 0 ) damage = 0;
                me->set_temp("temp/death_type","[�_���H�r���`]"); 
                me->receive_damage("hp", damage);
                me->receive_damage("ap", damage);
                me->receive_damage("mp", damage);
                me->add_block(1);
                me->improve_skill("anti_poison", duration+random(me->query_con()));
                me->set_temp("conditions/cold-poison",duration - 1);
                me->apply_condition("cold-poison", duration - 1);
        }
        return 1;
}
