// tchat.c		Shengsan@DS	1999.04.14

int main(object me, string arg)
{
	int i;
	string *t = ( { "pchat","nchat","fchat" } );

	if( arg==(string)me->query_temp("last_channel_msg") )
		return notify_fail("�Υ���W�D���ܽФ��n���ƬۦP���T���C\n");

	i = NATURE_D->which_world(environment(me));

	if( !i || i==0 )
		return notify_fail("�A�{�b���ɪŨä��ݩ����ɥN�A�ҥH�L�k�ϥ�tchat���O�C\n");
	CHANNEL_D->do_channel(me,t[i-1],arg);
	return 1;

		
}

int help (object me)
{
	write(@HELP
���O�榡: tchat <�T��>
 
�ɥN�W�D, ��T���ǵ��P�A�P�@�ɥN���Ҧ��H.

HELP
	);
	return 1;
}