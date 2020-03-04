// cat.c

inherit F_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
          string file;
	object ob;

	seteuid(geteuid(me));
	if (!arg) return notify_fail("���O�榡 : more <�ɦW>|<����W> \n");
	file = resolve_path(me->query("cwd"), arg);
	if ( file_size( file ) == 0 ) return notify_fail("�o���ɮ׬O�Ū��C\n");
	if ( file_size( file ) < 0 )
	 	file = resolve_path(me->query("cwd"), arg+".c");
	if ( file_size( file ) == 0 ) return notify_fail("�o���ɮ׬O�Ū��C\n");
	if( file_size(file) < 0 )
	{
		ob = present(arg, me);
		if( !ob ) ob = present(arg, environment(me));
		if( !ob ) return notify_fail("�S���o���ɮסC\n");
		file = base_name(ob) + ".c";
	}
	if( !read_file(file) ) return notify_fail("�S���o���ɮסC\n");
	me->start_more( read_file(file) );
	return 1;
}

int help(object me)
{
write(@HELP
���O�榡 : more <�ɮ�>|<����W>
 
��������ɮפ��e�C
 
more �Ҧ��U�����O:
q      : ���} more.
b      : ��ܫe�@�������e.
[ENTER]: ��ܤU�@�������e.

HELP
    );
    return 1;
}
