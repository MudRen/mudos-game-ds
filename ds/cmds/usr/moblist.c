// moblist.c by luky

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string *list;

	list = sort_array(IDCHECK_D->query_moblist(), 1);
	write(MUD_NAME + "目前登記有案的怪物有"+sprintf("%d",sizeof(list))+"種﹕\n");
	for(int i=0; i<sizeof(list); i++)
		printf("%-15s%c", list[i],  (i%5==4) ? '\n' : ' ');
	write("\n還有一些尚未登記的喔..\n");
	return 1;
}

int help(object me)
{
write(@HELP
指令格式 : moblist

用途 : 列出本MUD目前所有的怪物名單。
HELP
     );
     return 1;
}
