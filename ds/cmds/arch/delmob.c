// force.c

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	int i;
	string dest, cmd;
	object ob;
	if(!arg) return notify_fail("格式: delmob <mob> \n");
	i = strlen(arg);
	if( !me ) return 0;
	while(i--)
		if( arg[i]<'a' || arg[i]>'z' )
		{
			write("對不起﹐mob的id只能用英文字母而且不能空行。\n");
			return 0;
		}
	if( !(ob = present(arg, environment(me))) )
		return notify_fail("這裡沒有 " + arg + "。\n");
	if( !living(ob) )
		return notify_fail("這個物件不能加入mob一族。\n");
		
	return IDCHECK_D->set_mob_id(me,ob,1);
}

int help(object me)
{
	write(@Help
指令格式﹕addmob <mob> 

刪除某一個NPC id於/adm/etc/moblist, 必須是在同一個房間裡。
Help
	);
	return 1;
}
