// save.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object link_ob;

	seteuid(getuid());

	if( !objectp(link_ob = me->query_temp("link_ob")) )
		return notify_fail("�A���O�g�ѥ��`�s�u�i�J�M�����x�s�C\n");

	if( environment(me)->query("valid_startroom") ) {
		me->set("startroom", base_name(environment(me)));
		write("��A�U���s�u�i�ӮɡM�|�q�o�̶}�l�C\n");
	}

	if( (int)link_ob->save() && (int)me->save() )
	{
        	write("�ɮ��x�s�����C\n");
        	if(me->query("mud_age")>172800 && !wizardp(me))	RECORD_D->do_record(me);
		return 1;
	} else {
		write("�x�s���ѡC\n");
		return 0;
	}
}

int help(object me)
{
	write(@HELP
���O�榡�Rsave

��A���W�İ������G�s�_�ӡC
HELP
	);
	return 1;
}
