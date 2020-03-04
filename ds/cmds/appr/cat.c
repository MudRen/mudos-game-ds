// cat.c

#include "/doc/help.h"

inherit F_CLEAN_UP;
int help(object me);

int main(object me, string arg)
{
	string file;

	seteuid(geteuid(me));
    if (!arg) return notify_fail("�A�Q�n��ܨ����ɮ�?\n");
	file = resolve_path(me->query("cwd"), arg);
	if( file_size(file)<0 ) return notify_fail("�S���o���ɮסC\n");
	cat(file);
	return 1;
}

int help(object me)
{
write(@HELP
���O�榡 : cat <�ɮ�>

�����O�i���A(�p)����Ū���Y�ɮפ��{���C
HELP
    );
    return 1;
}
