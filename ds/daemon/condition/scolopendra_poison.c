// 蜈蚣毒 by alick
#include <ansi2.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	if( !duration )
	{
		tell_object(me, HIW"你身上的蜈蚣毒已經清除了。\n"NOR);
		return 0;
	} else {
		message_vision(HBK"$N身上的傷口流出黑色的血來。\n"NOR, me);
		me->set_temp("temp/death_type", "["+HIR"中蜈蚣毒而死"NOR+"]");
                me->receive_damage("hp", 100+duration*20);
		me->receive_damage("ap", 50+duration*5);
		me->receive_damage("mp", 50+duration*5);
		me->start_busy(1);
		me->apply_condition("scolopendra_poison", duration - 1);
	}
	return CND_CONTINUE;
}
