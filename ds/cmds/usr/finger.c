// finger.c

inherit F_CLEAN_UP;

void create()
{
	seteuid(getuid());
}

int main(object me, string arg)
{
	object body;
	string msg,name,mud,t1,t2;
	if( !arg )
	{
		if(wizardp(me) || me->query("level")>24 ) me->start_more( FINGER_D->finger_all(1) );
		else me->start_more( FINGER_D->finger_all(0) );
	}
	 else if(arg == "-dn" )
	{
		if(wizardp(me) || me->query("level")>24 ) me->start_more( FINGER_D->finger_all(2) );
		else me->start_more( FINGER_D->finger_all(0) );
	}
	else
	{
		if(sscanf(arg, "%s %s", t1, t2) == 2 )	return notify_fail("�A�Q�d�֪���ơS\n");
		if(wizardp(me) || arg==getuid(me)) msg= FINGER_D->finger_user(arg,1);
		else msg= FINGER_D->finger_user(arg,0);
		if( sscanf(arg, "%s@%s", name, mud)==2 ) arg=name;
		if( objectp(body = find_player(arg)) && me->visible(body) )
		{
		 if(me==body) msg += sprintf("%s�ثe���b�q %s �s�u���C\n\n", body->name(1),query_ip_name(body) );
		 else if(wizardp(me) || me->query("level")>24 ) msg += sprintf("%s�ثe���b�q %s �s�u���C\n\n", body->name(1),
			wiz_level(me) < wiz_level(body) ? "??.??.??.??" : query_ip_name(body) );
		 else msg += sprintf("%s�ثe���b�s�u���C\n\n", body->name(1),);
		}
		write(msg);
	}
	return 1;
}

int help(object me)
{
  write(@HELP
���O�榡 : finger [�ϥΪ̩m�W]  (�Ův�ΰ��Ū��a: finger -dn �d�ߺ���W��)
 
�o�ӫ��O, �p�G�S�����w�ϥΪ̩m��, �|��ܥX�Ҧ����b�u�W���a
���s�u���. �Ϥ�, �h�i��ܦ����Y�Ӫ��a���s�u, �v�������.

see also : who

HELP
    );
    return 1;
}
 
