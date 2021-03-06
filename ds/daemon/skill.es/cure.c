#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	target->is_corpse())
		return notify_fail("你要對誰施展這個法術﹖\n");

	if((int)me->query("mp") < 5 )
		return notify_fail("你的法力不夠﹗\n");

	me->add("mp", -5);

	if( random(me->query("max_mp")) < 30 ) {
		write("你失敗了。\n");
		return 1;
	}

	msg = HIM "$N口中喃喃地唸著咒文﹐左手一揮﹐手中聚起一團紫光射向$n﹗\n\n" NOR;

	msg += "$n漸漸恢復了。\n";

	message_vision(msg, me, target);

	target->receive_heal("hp", 50);

	me->start_busy(2);
	return 1;
}

