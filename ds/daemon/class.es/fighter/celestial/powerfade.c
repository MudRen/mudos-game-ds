// powerfade.c

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
	int skill;

	if( target != me ) return notify_fail("�A�u��ΤѨ����\\����ۤv������C\n");

	if( (int)me->query("force") < 100 )	return notify_fail("�A�����O�����C\n");
	if( me->query_temp("powerup") )	return notify_fail("�A�w�g�b�B�\\���F�C\n");
	if( (int)me->query("bellicosity") <= 0 )
		return notify_fail("�A�{�b�@�L����C\n");

	skill = me->query_skill("force");

	me->add("bellicosity", - 100 - skill/3 );
	me->add("force", -100);
	me->receive_damage("sen", 100);

	message_vision(
		HIC "$N�L�@�����M�B�_�Ѩ����\\�M��C�I�l�M�}�l���Ħۤv������ ....\n" NOR, me);

	if( me->is_fighting()
	&&	(random(skill) < (int)me->query("cps") * 3 ) )
		me->unconcious();

	return 1;
}

void remove_effect(object me, int amount)
{
	me->add_temp("apply/attack", - amount);
	me->add_temp("apply/dodge", - amount);
	me->add_temp("apply/damage", - amount);
	me->delete_temp("powerup");
	tell_object(me, "�A���Ѩ����\\�B�槹���M�N���O���^���СC\n");
}
