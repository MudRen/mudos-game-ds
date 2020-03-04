// drunk.c

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	int limit;

	limit = (me->query("con") + (int)me->query("max_mp") / 60);

	if( duration > limit
	&&	living(me) ) {
		me->unconcious();
		me->receive_heal("all", 40);
		return 0;
	} else if( !living(me) ) {
		message("vision", me->name() + "���F�ӹj�M���L�̵M��K�p�d�C\n",
			environment(me), me);
			me->receive_heal("all", 32);
	} else if( duration > limit/2 ) {
		tell_object(me, "�Aı�o���������I�I�M���l�����Ʀa�M�j���O�K�F�C\n");
		message("vision", me->name() + "�n�Y�̸��a��������í�M��M�O�ܾK�F�C\n",
			environment(me), me);
		me->receive_heal("all", 15);
	} else if( duration > limit/4 ) {
		tell_object(me, "�Aı�o�@�}�s�N�W�ġM���֦��ǨI���F�C\n");
		message("vision", me->name() + "�y�W�w�g����s�N�F�C\n",
			environment(me), me);
		me->receive_heal("all", 25);
	} else 	{
		tell_object(me, "�Aı�o�Y���I�h�C\n");
		me->receive_heal("all", 8);
	}
	me->apply_condition("drunk", duration - 1);
	if( !duration ) return 0;
	return 1;
}
