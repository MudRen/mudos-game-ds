//���u�۬r(gu-poison)        sk 60  �d��ĤH str & con & int & dex         (�T�w�� sk/10) 
#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
        int anti = me->query_skill("anti_poison"),
            damage = me->query_temp("shouyu-poison/gu-poison/effect");
        if( !duration )
        {
                tell_object(me,HIB"�A���W�ݾl�����u�۬r�r�ʮ����F�C\n"NOR);
                me->delete_temp("conditions/gu-poison");
                me->add_temp("apply/str", me->query_temp("shouyu-poison/gu-poison/damage"));
                me->add_temp("apply/con", me->query_temp("shouyu-poison/gu-poison/damage"));
                me->add_temp("apply/int", me->query_temp("shouyu-poison/gu-poison/damage"));
                me->add_temp("apply/dex", me->query_temp("shouyu-poison/gu-poison/damage"));
                return 0;
        } else 
        {
                if(random(8+duration)<random(5))
                {
                        me->apply_condition("gu-poison", duration);
                        return 1;
                }
 //        if( !living(me) ) {
//                message("vision",HIW + me->name() + "���o�ݡA�������W�@�h�����������C\n"NOR, environment(me), me);
//        }
//        else {
        if( duration < 5) 
           tell_room(environment(me), YEL+me->name()+"��M�u���s���A���l�C�C���U�A�f���o�X���H���~���������n�C\n" NOR, ({ me }));            
        else if( duration < 15) 
                tell_room(environment(me), BLU+me->name()+"���M�������w���L�H���A����o�޲��L�ۡC\n" NOR,  ({ me }));        
        else if( duration < 25)
                tell_room(environment(me), HIB+me->name()+"���ɯ�����[�k��A���F����A�çq�ër�C\n" NOR,({ me }));           
        else    tell_room(environment(me), HIR+me->name()+"��M�Y���@�ΡA�u�b�a�W�����a�oŸ�C\n" NOR,({ me }));
        tell_object(me, HIR "�A���M�P�쨭������A�w�g��ť�ϳ�F�C\n" NOR );

//                }
                damage *= 10;
                damage -= random(anti*5);
                if( damage < 0 ) damage = 0;
                if( !me->query_temp("shouyu-poison/gu-poison/damage") ){
                me->set_temp("shouyu-poison/gu-poison/damage", damage);
                me->add_temp("apply/str", -damage);
                me->add_temp("apply/con", -damage);
                me->add_temp("apply/int", -damage);
                me->add_temp("apply/dex", -damage);
                }
                me->add_block(1);
                me->improve_skill("anti_poison", duration+random(me->query_con()));
                me->set_temp("conditions/gu-poison",duration - 1);
                me->apply_condition("gu-poison", duration - 1);
        }
        return 1;
}
