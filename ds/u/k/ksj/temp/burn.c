#include <ansi.h>
#include <condition.h>
inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
        int anti,damage;
        if( !duration )
        {
                tell_object(me,HIG"�A���W���N�ˤw�g���h�F�C\n"NOR);
                me->delete_temp("conditions/burn");
                return 0;
        } 
        else 
        {
                if(random(8+duration)<random(5))
                {
                        me->apply_condition("burn", duration);
                        return 1;
                }
//                anti=me->query_skill("anti_poison");
//                anti=100-anti+random(21);
//                damage=duration*anti/50;
                  damage=duration+random(5);
                tell_object(me,HIR"�A���W���N�˨ϧA�k�h���w�C\n"NOR);
                tell_room(environment(me),me->name()+"���W���N�˦]����Ĳ��Ů�ӯk�h����C\n",({me}));
                me->set_temp("temp/death_type","[�N�˹L�צӦ�]"); 
                me->receive_damage("hp", 4+damage);
                me->receive_damage("ap", 3+damage);
                me->receive_damage("mp", 5+damage);
                me->add_block(1);
                if(duration>50) duration=50;
//                me->improve_skill("anti_poison", duration+random(me->query_con()));
//                me->set_temp("conditions/burn",duration - 1);
                me->apply_condition("burn", duration - 1);
        }
        return 1;
}
