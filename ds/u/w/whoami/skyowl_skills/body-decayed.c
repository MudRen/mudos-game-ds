//�Ʀ�G���r(body-decayed)   sk 100 ���v�ʫd��ĤH merits                  (bar bio wit tec sou �ܤ@�ئ��@�I)
#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
        int anti = me->query_skill("anti_poison");
        string *merits = ({ "bio", "bar", "wit", "sou", "tec" }), merit;

        if( !duration )
        {
                tell_object(me,HIB"�A���W�ݾl���Ʀ�G���r�r�ʮ����F�C\n"NOR);
                me->delete_temp("conditions/body-decayed");
                me->add_temp("apply/"+me->query_temp("shouyu-poison/body-decayed/merits"), 1);
                return 0;
        } else 
        {
                if(random(8+duration)<random(5))
                {
                        me->apply_condition("body-decayed", duration);
                        return 1;
                }
 //        if( !living(me) ) {
//                message("vision",HIW + me->name() + "���o�ݡA�������W�@�h�����������C\n"NOR, environment(me), me);
//        }
//        else {
                tell_object(me, YEL "�A���W�ˤf���H�L�i�Q�����t�׻G��A�٤����d�X���⪺�@�C\n" NOR );
                tell_room(environment(me), HIR + me->name()+"�����W�U���X�}�}�G�ͤ@�몺�c��A���A���ѦۥD�������@�áC\n" NOR,({me}));
//                }
                merit = merits[random(4)];
                if( !me->query_temp("shouyu-poison/body-decayed/merits") ){
                me->set_temp("shouyu-poison/body-decayed/merits", merit);
                me->add_temp("apply/"+merit, -1);
                }
                me->add_block(1);
                me->improve_skill("anti_poison", duration+random(me->query_con()));
                me->set_temp("conditions/body-decayed",duration - 1);
                me->apply_condition("body-decayed", duration - 1);
        }
        return 1;
}
