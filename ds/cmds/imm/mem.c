// mem.c

inherit F_CLEAN_UP;

string memory_expression(int m);

int main(object me, string arg)
{
	object obj;

	if (!arg) {
		printf( "%s�ثe�@�ϥ� %s bytes �O����C\n",
			MUD_NAME, memory_expression(memory_info()) );
		return 1;
	}

	if( arg=="-m" ) {
		malloc_status();
		write("\n");
		return 1;
	}

	seteuid(geteuid(me));
	obj = find_object(arg);
	if (!obj) obj = present(arg, me);
	if (!obj) obj = present(arg, environment(me));
	if (!obj) obj = find_object( resolve_path(me->query("cwd"), arg) );
	if (!obj) return notify_fail("�S���o�˪���....�C\n");

	printf( "%O �@�ϥ� %s bytes �O����C\n", obj, memory_expression(memory_info(obj)));
	return 1;
}

string memory_expression(int m)
{
	float mem;

	mem = m;
	if( mem<1024 ) return m + "";
	if( mem<1024*1024 )
		return sprintf("%.2f K", (float)mem / 1024);
	return sprintf("%.3f M", (float)mem / (1024*1024));
}

int help(object me)
{
  write(@HELP
���O�榡 : mem <���󤧦W�٩��ɦW>

�o�ӫ��O�i�D�A�Y�Ӫ�����Ϊ��O����ƶq�C
�Y�S����������, �h�|��ܥثe�C���Ҧ��Ϊ��O����.
HELP
    );
    return 1;
}
