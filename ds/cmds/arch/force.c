// force.c

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string dest, cmd;
	object ob;

	if( me != this_player(1) ) return 0;

	if( !arg || sscanf(arg, "%s to %s", dest, cmd) != 2 )
		return notify_fail("���O�榡�Rforce <�Y�H> to <���O>\n");
	if( !(ob = present(dest, environment(me))) )
	{
		if(wizhood(me) == "(admin)") ob = find_living(dest);
		if(!ob) return notify_fail("�o�̨S�� " + dest + "�C\n");
	}
	if( !living(ob) )
		return notify_fail("�o�Ӫ��󤣯����R�O�C\n");
	if(wiz_level(me) <= wiz_level(ob) && getuid(ob) != me->query("id") )
		return notify_fail("�A�S���j��" + ob->name() + "������O���v�O�C\n");
	if( userp(ob) )
		log_file("FORCE_PLAYER", sprintf("[%s] %s forces %s to %s\n",  
			ctime(time()), geteuid(me), geteuid(ob), cmd));
	return ob->force_me(cmd);
}

int help(object me)
{
	write(@Help
���O�榡�Rforce <�Y�H> to <���O>

�j���Y�H���Y��, ���A���Ův���ť������谪, �ӥB�����O�b�P�@�өж��̡C
Help
	);
	return 1;
}
