// recover.c

inherit SSERVER;

int exert(object me, object target)
{
	if( target != me ) return notify_fail("�A�u��Τ��\\�դæۤv���𮧡C\n");

	if( (int)me->query("force") < 20 )
		return notify_fail("�A�����O�����C\n");

	me->receive_heal("kee", 10 + (int)me->query_skill("force")/3 );
	me->add("force", -20);

	message_vision("$N�`�`�l�F�X�f��M�y��ݰ_�Ӧn�h�F�C\n", me);

	if( me->is_fighting() ) me->start_busy(1);

	return 1;
}
