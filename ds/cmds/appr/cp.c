// cp.c
 
inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
	string src, dst, *dirs;
 
	seteuid(geteuid(me));
	if (!arg || sscanf(arg, "%s %s", src, dst)!=2 ) return
		notify_fail("���O�榡: cp <���ɦW> <�ؼ��ɦW> \n");

	src = resolve_path(me->query("cwd"), src);
	dst = resolve_path(me->query("cwd"), dst);

	if( file_size(dst)==-2 ) {
		dirs = explode(src, "/");
		dst += "/" + dirs[sizeof(dirs)-1];
	}

	if( cp(src, dst) )
		write("Ok.\n");
	else
		write("�A�S��������Ū�g�v�Q�C\n");
	return 1;
}
 
int help(object me)
{
  write(@HELP
���O�榡 : cp <���ɦW> <�ؼ��ɦW>
 
�����O�i���A(�p)�����ɮסC
HELP
    );
    return 1;
}
 
