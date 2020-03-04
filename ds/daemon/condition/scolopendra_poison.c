// ���G�r by alick
#include <ansi2.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	if( !duration )
	{
		tell_object(me, HIW"�A���W�����G�r�w�g�M���F�C\n"NOR);
		return 0;
	} else {
		message_vision(HBK"$N���W���ˤf�y�X�¦⪺��ӡC\n"NOR, me);
		me->set_temp("temp/death_type", "["+HIR"�����G�r�Ӧ�"NOR+"]");
                me->receive_damage("hp", 100+duration*20);
		me->receive_damage("ap", 50+duration*5);
		me->receive_damage("mp", 50+duration*5);
		me->start_busy(1);
		me->apply_condition("scolopendra_poison", duration - 1);
	}
	return CND_CONTINUE;
}
