inherit SKILL;
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

	if((int)me->query("mp") < 30 )
		return notify_fail("你的法力不夠﹗\n");
	if(me->query("hp")>=me->query("max_hp") ) return notify_fail("你現在的生命狀況已經到達顛峰了。\n");
		if(me->is_ghost() ) return notify_fail("你還是鬼魂。\n");
	if(me->is_busy() ) return notify_fail("(你的上一個動作還沒有完成。)\n");
		
	me->receive_heal("mp", -5);

	if( random(me->query("max_mp")) < 30 ) {
		write("你失敗了。\n");
		return 1;
	}
	if( sizeof(me->query_temp("is_busy")) ) return notify_fail("你現在正在忙。\n");
	if(!me->spell_active( "heal",(: call_other, __FILE__, "delay", me ,5:), 5))
	return notify_fail("你結束醫療的動作還沒完成。\n");
	msg = HIY "$N口中喃喃地唸著咒文﹐左手一揮﹐手中聚起一團"HIM"紫光"NOR"射向$n﹗\n\n" NOR;

	msg += "$n的傷口漸漸縫合了。\n";

	message_vision(msg, me, target);

	target->receive_heal("hp", 3+(me->query_int()/2)+random(me->query_spell("heal")));

	me->improve_spell("heal",1+me->query_int()/10);
	target->start_busy(1);
	return 1;
}
int valid_learn(object me) { return 1; }
int practice_skill(object me) { return 1; }



