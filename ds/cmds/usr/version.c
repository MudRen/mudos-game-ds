// version.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        write("MudOS Driver:" + __VERSION__+"\n");
        write("DS Mudlib: ds.060617\n");
        return 1;
}
int help(object me)
{
  write(@HELP
���O�榡 : version
 
�o�ӫ��O�|��ܹC���ثe�ҥΪ� MudOS driver ����.
 
HELP
    );
    return 1;
}

