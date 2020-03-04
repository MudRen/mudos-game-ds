// rmdir.c

inherit F_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
	string dir;

	if(!arg) return help(me);

	dir = resolve_path(me->query("cwd"), arg);

	seteuid(geteuid(me));
	if( rmdir(dir) )
		write("Ok.\n");
	else
		write("�R�����ѡC\n");
	return 1;	
}

int help(object me)
{
	write(@HELP
���O�榡 : rmdir <�l�ؿ��W>

�R���@�Ӥl�ؿ��C
HELP
	);
	return 1;
}
