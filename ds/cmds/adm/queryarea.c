// id.c
#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string area;
	object env;
	env=environment(me);
	area = area_domain(base_name(env));
	write("�A�Ҧb�ϰ쪺�����O:"+area+"\n");
	return 1;
}
int help(object me)
{
write(@HELP
���O�榡 : queryarea
 
�d�ߥثe�Ҧb���ɪŻ��.

HELP
    );
    return 1;
}
 
