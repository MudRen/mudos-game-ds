// 
#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	int anti,damage;
	if( !duration )
	{
		tell_object(me,HIR"�A���W�ݾl�����r�r�ʮ����F�C\n"NOR);
		me->delete_temp("conditions/hot_poison");
		return 0;
	} else 
	{
		if(random(8+duration)<random(5))
		{
            		me->apply_condition("hot_poison", duration);
			return 1;
		}
		anti=me->query_skill("anti_poison");
		anti=100-anti+random(200);
		damage=duration*anti/50;

   if( !living(me) ) {
      message("vision", me->name() + "�����ܶ¡A���o�X�@�}�J�k���C\n", environment(me), me);
   }
   else {
		 tell_object(me, HIR "���M�@�Ѥ�������ŧ�ӡA�S�o�A��}�oŸ�I\n" NOR );
    		tell_room(environment(me), HIR + me->name()+"��M�����_�X�}�}���ϡA�L�B�����A����J�æa���R�ۡC\n" NOR,({me}));
   }
		me->set_temp("temp/death_type","[[1;31m�_�����r�Ӧ�[0m]"); 
		me->receive_damage("hp", 10+damage*5);
		me->receive_damage("ap", 5+damage*3);
		me->receive_damage("mp", 5+damage*3);
		me->add_block(1);
		if(duration>50) duration=50;
		me->improve_skill("anti_poison", duration+random(me->query_con()));
		me->set_temp("conditions/poison",duration - 1);
		me->apply_condition("poison", duration - 1);
	}
	return 1;
}
