// id.c
#include <ansi.h>
inherit F_CLEAN_UP;
void creat()
{
	seteuid(getuid());
}

int main(object me, string arg)
{
	object undead_ob,shadows;
	int check;
	seteuid( geteuid(me) );
	undead_ob=load_object("/feature/undead");
	if(!undead_ob) return notify_fail("不死物件遺失。\n");
	if(arg=="?")
	{
		shadows = query_shadowing( me );
		if(shadows) write(sprintf("%s 的投影物件是: %O\n",me->name(),shadows));
		shadows = query_shadowing( undead_ob );
		if(shadows) write(sprintf("%s 的投影物件是: %O\n",base_name(undead_ob),shadows));
		return 1;
	}
	if(arg == "off")
	{
		shadows = query_shadowing( undead_ob );
		if(!shadows) return notify_fail("不死邪神並沒有降臨這個世界。\n");
		if(shadows!=me) return notify_fail("不死邪神並沒有附在你的身上。\n");
		remove_shadow(undead_ob);
		message_vision("一陣黑影飄過，不死邪神離開了$N的軀體。\n",me);
		return 1;
	}
	if(shadows = query_shadowing( undead_ob ))
	{
		if(shadows==me) return notify_fail("不死邪神已經附在你的身上了。\n");
		return notify_fail(sprintf("%s 的投影物件是: %O\n",base_name(undead_ob),shadows));
	}
	check = undead_ob->apply_undead(me);
	if(check)
	{
		message_vision(HIW+"\n\t突然間陰風陣陣，$N被不死邪神附體了!!\n\n"+NOR,me);
		return 1;
	}
	else return notify_fail("無法呼叫不死邪神附體。\n");
}
int help(object me)
{
write(@HELP
指令格式 : undead
 
利用shadow變成不死身.

HELP
    );
    return 1;
}
 
