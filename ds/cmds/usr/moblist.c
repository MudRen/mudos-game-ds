// moblist.c by luky

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string *list;

	list = sort_array(IDCHECK_D->query_moblist(), 1);
	write(MUD_NAME + "�ثe�n�O���ת��Ǫ���"+sprintf("%d",sizeof(list))+"�ءR\n");
	for(int i=0; i<sizeof(list); i++)
		printf("%-15s%c", list[i],  (i%5==4) ? '\n' : ' ');
	write("\n�٦��@�ǩ|���n�O����..\n");
	return 1;
}

int help(object me)
{
write(@HELP
���O�榡 : moblist

�γ~ : �C�X��MUD�ثe�Ҧ����Ǫ��W��C
HELP
     );
     return 1;
}
