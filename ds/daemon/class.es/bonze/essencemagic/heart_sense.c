// heart_sense.c

#include <ansi.h>

inherit SSERVER;

int conjure(object me, object target)
{
	if( !target || !target->is_character() )
		return notify_fail("�A�n��֨ϥΤ��ѯ��q�S\n");
	if( target->is_corpse() )
		return notify_fail("�Ӥ��ΤF�M�u�����H�~��Ͽ��C\n");

	if( (int)me->query("atman") < 50 ) return notify_fail("�A���F�O�����T\n");
	me->add("atman", -50);
	me->receive_damage("sen", 30);
	message_vision( HIY "$N�@���b$n�����F�\\�W�M�@��K�b$n����ߡM���W�����w�w�C�u ...\n" NOR,
		me, target );
	if( random(me->query("max_atman")) > 100 )
		target->revive();
	else
		me->unconcious();
	if( me->is_fighting() )
		me->start_busy(3);
	return 1;
}
