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
		return notify_fail("�A�n��֬I�i�o�Ӫk�N�S\n");

	if((int)me->query("mp") < 30 )
		return notify_fail("�A���k�O�����T\n");
	if(me->query("hp")>=me->query("max_hp") ) return notify_fail("�A�{�b���ͩR���p�w�g��F�A�p�F�C\n");
		if(me->is_ghost() ) return notify_fail("�A�٬O����C\n");
	if(me->is_busy() ) return notify_fail("(�A���W�@�Ӱʧ@�٨S�������C)\n");
		
	me->receive_heal("mp", -5);

	if( random(me->query("max_mp")) < 30 ) {
		write("�A���ѤF�C\n");
		return 1;
	}
	if( sizeof(me->query_temp("is_busy")) ) return notify_fail("�A�{�b���b���C\n");
	if(!me->spell_active( "heal",(: call_other, __FILE__, "delay", me ,5:), 5))
	return notify_fail("�A�����������ʧ@�٨S�����C\n");
	msg = HIY "$N�f�����a��۩G��M����@���M�⤤�E�_�@��"HIM"����"NOR"�g�V$n�T\n\n" NOR;

	msg += "$n���ˤf�����_�X�F�C\n";

	message_vision(msg, me, target);

	target->receive_heal("hp", 3+(me->query_int()/2)+random(me->query_spell("heal")));

	me->improve_spell("heal",1+me->query_int()/10);
	target->start_busy(1);
	return 1;
}
int valid_learn(object me) { return 1; }
int practice_skill(object me) { return 1; }



