// call.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string objname, func, param, euid;
	object obj;
	mixed *args, result;
	int i;

	if( arg ) {
		if( sscanf(arg, "-%s %s", euid, arg)==2 ) {
			if( (string)SECURITY_D->get_status(me) != "(admin)" )
				return notify_fail("�A����]�w�ۤv�� euid�C\n");
			seteuid(euid);
		}
		else
			seteuid( geteuid(this_player(1)) );

		if( sscanf(arg, "%s->%s(%s)", objname, func, param)!=3 )
			return notify_fail("���O�榡�Rcall <����>-><���>( <�Ѽ�>, ... )\n");
	} else
		return notify_fail("���O�榡�Rcall <����>-><���>( <�Ѽ�>, ... )\n");

	obj = present(objname, environment(me));
	if(!obj) obj = present(objname, me);
	if(!obj) obj = find_player(objname);
	if(!obj || !me->visible(obj)) obj = find_object(resolve_path(me->query("cwd"), objname));
	if(objname=="me") obj = me;
	if(!obj) return notify_fail("�䤣����w������C\n");

	if( userp(obj) )
	{
		if( obj != me )
		{
			if( wiz_level(me) < 4 && userp(obj))
			{
				log_file("static/CALL_PLAYER",
				sprintf("%s(%s)�չϭק� %s(%s)->%s(%s) on %s\n",
				me->name(1), geteuid(me), obj->name(1), geteuid(obj), func, param,
				ctime(time()) ) );
				return notify_fail("�A����ק��L���a����ơC\n");
			}
			log_file("static/CALL_PLAYER",
			sprintf("%s(%s) call %s(%s)->%s(%s) on %s\n",
				me->name(1), geteuid(me), obj->name(1), geteuid(obj), func, param,
				ctime(time()) ) );
			if( !wizardp(obj) && wiz_level(me) < 4 )
			{
				log_file("static/CALL_PLAYER","[�H�ϧŮv�W�w] "+me->name(1)+"("+geteuid(me)+") �չϭק� "+obj->name(1)+"("+geteuid(obj)+")�����!!\n");
				return notify_fail("���w�����󤣦X�k�C\n");
			}
		}
	}
	 else if( !master()->valid_write( base_name(obj), me, "set" ) )
		return notify_fail("�A�S�������I�s�o�Ӫ��󪺨�ƪ��v�O�C\n");

	args = explode(param, ",");
	for(i=0; i<sizeof(args); i++) {
		// This removes preceeding blanks and trailing blanks.
		parse_command(args[i], environment(me), "%s", args[i]);
		if( sscanf(args[i], "%d", args[i]) ) continue;
		if( sscanf(args[i], "\"%s\"", args[i]) ) continue;
		//args[i] = restore_variable(args[i]);
	}

	args = ({ func }) + args;

	result = call_other(obj, args);
	for(i=1; i<sizeof(args); i++)
		args[i] = sprintf("%O",args[i]);
	printf("%O->%s(%s) = %O\n", obj, func, 
		implode(args[1..sizeof(args)-1], ", "), result);
	return 1;
}

int help(object me)
{
write(@HELP
���O�榡 : call <����>-><���>(<�Ѽ�>, ...... )
 
�I�s<����>�̪�<���>�öǤJ����<�Ѽ�>.

�`�N: ���i�N�ݩʩM�ޯ൥�P�p�⦳�����ƭȽդӰ�(���W�L100���з�),
      �H�K�y���t�ο��~���!!
 
HELP
    );
    return 1;
}
