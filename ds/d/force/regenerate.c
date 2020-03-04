// regenerate.c

inherit SSERVER;

int exert(object me, object target)
{
	if( target != me ) return notify_fail("�A�u��Τ��\\�����ۤv����O�C\n");

	if( (int)me->query("force") < 20 )
		return notify_fail("�A�����O�����C\n");

	me->receive_heal("gin", 10 + (int)me->query_skill("force")/3 );
	me->add("force", -20);

	message_vision("$N�`�`�l�F�f��M��}���ʤF�X�U�M��ӤH�ݰ_�Ӧ����O�h�F�C\n", me);

	if( me->is_fighting() ) me->start_busy(1);

	return 1;
}
