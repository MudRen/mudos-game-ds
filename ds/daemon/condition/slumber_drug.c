// drunk.c

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	int limit;

	limit = (me->query("con") + (int)me->query("max_force") / 50) * 2;

	if( duration > limit
	&&	living(me) ) {
		me->unconcious();
		return 0;
	} else if( duration > limit/2 ) {
		tell_object(me, "�Aı�o���������I�I�M�ߤ��ſ������M���Q���U�ӺΤ@ı�C\n");
		message("vision", me->name() + "�n�Y�̸��a��������í�M��M�O�X���Ī��ĤO�o�@�F�C\n",
			environment(me), me);
	}

	me->apply_condition("slumber_drug", duration - 1);
	if( !duration ) return 0;
	return 1;
}
