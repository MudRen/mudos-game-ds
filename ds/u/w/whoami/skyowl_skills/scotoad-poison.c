//�T��������(scotoad-poison) sk 80  �d��ĤH �����O & ���m�O & ���F��ܤO  (�T�w�� sk/2) 
#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
        int anti = me->query_skill("anti_poison"),
            damage = me->query_temp("shouyu-poison/scotoad-poison/effect");
        if( !duration )
        {
                tell_object(me,HIB"�A���W�ݾl���T�������Ϫ��r�ʮ����F�C\n"NOR);
                me->delete_temp("conditions/scotoad-poison");
                me->add_temp("apply/damage", me->query_temp("shouyu-poison/scotoad-poison/damage"));
                me->add_temp("apply/armor", me->query_temp("shouyu-poison/scotoad-poison/damage"));
                me->add_temp("apply/shield", me->query_temp("shouyu-poison/scotoad-poison/damage"));
                return 0;
        } else 
        {
                if(random(8+duration)<random(5))
                {
                        me->apply_condition("scotoad-poison", duration);
                        return 1;
                }
 //        if( !living(me) ) {
//                message("vision",HIW + me->name() + "���o�ݡA�������W�@�h�����������C\n"NOR, environment(me), me);
//        }
//        else {
                tell_object(me, HIY "�@�}���H���몺�h�P�ۧA�¤쪺�|�϶ǨӡK�K�K\n" NOR );
                tell_room(environment(me), HIG + me->name()+"�y�W�@�}�C�B�@�}���B�@�}���A�����Ӥ����y�СC\n" NOR,({me}));
//                }
                damage /= 2;
                damage -= random(anti/10);
                if( damage < 0 ) damage = 0;
                if( !me->query_temp("shouyu-poison/scotoad-poison/damage") ){
                me->set_temp("shouyu-poison/scotoad-poison/damage", damage);
                me->add_temp("apply/damage", -damage);
                me->add_temp("apply/armor", -damage);
                me->add_temp("apply/shield", -damage);
                }
                me->add_block(1);
                me->improve_skill("anti_poison", duration+random(me->query_con()));
                me->set_temp("conditions/scotoad-poison",duration - 1);
                me->apply_condition("scotoad-poison", duration - 1);
        }
        return 1;
}
