// bandaged.c
#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	if( !duration )
	{
		tell_object(me,HIW"�A���{�l�h�����F�C\n"NOR);
		me->delete_temp("conditions/eat_bad");
		return 0;
	} else 
	{
		if(random(2))
		{
			me->apply_condition("eat_bad", duration);
			return CND_CONTINUE;
		}

		tell_object(me,"�Aı�o�{�l�ܵh�C\n");
		me->set_temp("temp/death_type","[[1;31m�������r�Ӧ�[0m]"); 
		me->receive_damage("hp", 8+duration*2);
		me->receive_damage("ap", 5+duration);
		me->receive_damage("mp", 5+duration);
		me->add_block(1);
		if(duration>15) duration=15;
		me->set_temp("conditions/eat_bad",duration - 1);
		me->apply_condition("eat_bad", duration - 1);
	}
	return CND_CONTINUE;
}
