// rm.c

#include "/doc/help.h"

inherit F_CLEAN_UP;
int help(object me);

int main(object me, string file)
{
	seteuid(geteuid(me));
    if (!file) return notify_fail("�A�n�R�������ɮ�?\n");
    file=resolve_path(me->query("cwd"),file);
	if( rm(file) )
	{
		log_file("rm.log",
			sprintf("%s(%s) �R�� %s on %s\n",
			me->name(1),   //�O���ϥΩR�O���H�W
			geteuid(me),   //�O���ϥΩR�O��ID
			file,          //�O���R���������|
			ctime(time()) ) ); //�O���ϥΩR�O���ɶ�
		write("Ok.\n");
	}
	else
		write("�A�S���R���o���ɮת��v�Q�C\n");
	return 1;
}

int help(object me)
{
  write(@HELP
���O�榡 : rm <�ɦW>

�����O�i���A(�p)�R�����v�ק諸�ɮסC
HELP
    );
    return 1;
}
