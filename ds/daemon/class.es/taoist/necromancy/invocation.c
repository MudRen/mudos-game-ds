// invocation.c

inherit SSERVER;

int cast(object me, object target)
{
	object soldier;

	if( !me->is_fighting() )
		return notify_fail("�u���԰����~��l��ѱN�T\n");
	
	if( (int)me->query("mana") < 100 )
		return notify_fail("�A���k�O�����F�T\n");

	if( (int)me->query("sen") < 60 )
		return notify_fail("�A���믫�L�k�����T\n");

	message_vision("$N���a���F�X�y�G�y�C\n", me);

	me->add("mana", -100);
	me->receive_damage("sen", 60);

	if( random(me->query("max_mana")) < 200 ) {
		message("vision", "���O����]�S���o�͡C\n", environment(me));
		return 1;
	}

	seteuid(getuid());
	if( random(1) )
		soldier = new("/obj/npc/heaven_soldier");
	else
		soldier = new("/obj/npc/hell_guard");

	soldier->move(environment(me));
	soldier->invocation(me);

	return 1;
}
