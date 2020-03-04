// mkdir.c

inherit F_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
	string dir;

	if(!arg) return help(me);

	dir = resolve_path(me->query("cwd"), arg);

	seteuid(geteuid(me));
	if( mkdir(dir) )
		write("Ok.\n");
	else
		write("�A�S���b�o�̫ؤl�ؿ����v�Q�C\n");
	return 1;	
}

int help(object me)
{
	write(@HELP
���O�榡 : mkdir <�l�ؿ��W>

�إߤ@�Ӥl�ؿ��C
HELP
	);
	return 1;
}
