#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	target->is_corpse())
		return notify_fail("�A�n��֬I�i�o�Ӫk�N�S\n");

	if((int)me->query("mp") < 5 )
		return notify_fail("�A���k�O�����T\n");

	me->add("mp", -5);

	if( random(me->query("max_mp")) < 30 ) {
		write("�A���ѤF�C\n");
		return 1;
	}

	msg = HIM "$N�f�����a��۩G��M����@���M�⤤�E�_�@�ε����g�V$n�T\n\n" NOR;

	msg += "$n������_�F�C\n";

	message_vision(msg, me, target);

	target->receive_heal("hp", 50);

	me->start_busy(2);
	return 1;
}

