// id.c
#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string area;
	object env;
	env=environment(me);
	area = area_domain(base_name(env));
	write("你所在區域的的領域是:"+area+"\n");
	return 1;
}
int help(object me)
{
write(@HELP
指令格式 : queryarea
 
查詢目前所在的時空領域.

HELP
    );
    return 1;
}
 
