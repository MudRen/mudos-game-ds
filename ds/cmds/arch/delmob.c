// force.c

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	int i;
	string dest, cmd;
	object ob;
	if(!arg) return notify_fail("�榡: delmob <mob> \n");
	i = strlen(arg);
	if( !me ) return 0;
	while(i--)
		if( arg[i]<'a' || arg[i]>'z' )
		{
			write("�藍�_�Mmob��id�u��έ^��r���ӥB����Ŧ�C\n");
			return 0;
		}
	if( !(ob = present(arg, environment(me))) )
		return notify_fail("�o�̨S�� " + arg + "�C\n");
	if( !living(ob) )
		return notify_fail("�o�Ӫ��󤣯�[�Jmob�@�ڡC\n");
		
	return IDCHECK_D->set_mob_id(me,ob,1);
}

int help(object me)
{
	write(@Help
���O�榡�Raddmob <mob> 

�R���Y�@��NPC id��/adm/etc/moblist, �����O�b�P�@�өж��̡C
Help
	);
	return 1;
}
