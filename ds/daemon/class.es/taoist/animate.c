// animate.c

inherit F_CLEAN_UP;

int cast(object me, object target)
{
	if( me->is_fighting() )	return notify_fail("�A���b�԰����T\n");
	
	if( !target || !target->is_corpse() ) return notify_fail("�A�n�X�ʭ��@�����S\n");
	
	if( (int)me->query("mana") < 50 ) return notify_fail("�A���k�O�����F�T\n");

	message_vision(
		"$N��ۦa�W��$n���a���F�X�y�G�y�M$n���z�F�X�U�����F�_�ӡT\n", me, target);

	target->animate(me, (int)me->query_skill("spells") * 3 + 30);

	me->add("mana", -50);
	me->receive_damage("sen", 30);

	return 1;
}
