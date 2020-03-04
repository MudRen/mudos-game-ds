//�_�����r(hot-poison)       sk 40  �d��ĤH �R�� & �{��    (�T�w�� sk/5)     
#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
        int anti = me->query_skill("anti_poison"),
            damage = me->query("shouyu-poison/hot-poison/effect");
        if( !duration )
        {
                tell_object(me,HIB"�A���W�ݾl���_�����r�r�ʮ����F�C\n"NOR);
                me->delete_temp("conditions/hot-poison");
                me->delete_temp("shouyu-poison/hot-poison/effect");
                me->add_temp("apply/dodge", me->query_temp("shouyu-poison/hot-poison/damage"));
                me->add_temp("apply/hit", me->query_temp("shouyu-poison/hot-poison/damage"));
                return 0;
        } else 
        {
                if(random(8+duration)<random(5))
                {
                        me->apply_condition("hot-poison", duration);
                        return 1;
                }
 //        if( !living(me) ) {
//                message("vision",HIW + me->name() + "���o�ݡA�������W�@�h�����������C\n"NOR, environment(me), me);
//        }
//        else {
                tell_object(me, HIR "���M�@�Ѥ�������ŧ�ӡA�S�o�A��}�oŸ�I\n" NOR );
                tell_room(environment(me), HIR + me->name()+"��M�����_�X�}�}���ϡA�L�B�����A����J�æa���R�ۡC\n" NOR,({me}));
//                }
                damage /= 5;
                damage -= random(anti/20);
                if( damage < 0 ) damage = 0;
                me->set("shouyu-poison/hot-poison/damage", damage);
                if( !me->query_temp("shouyu-poison/hot-poison/damage") ){
                  me->add_temp("apply/dodge", -damage);
                me->add_temp("apply/hit", -damage);
                }
                me->add_block(1);
                me->improve_skill("anti_poison", duration+random(me->query_con()));
                me->set_temp("conditions/hot-poison",duration - 1);
                me->apply_condition("hot-poison", duration - 1);
        }
        return 1;
}
