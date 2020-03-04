// config.c

#include <runtime_config.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int num;

	if( !arg || sscanf(arg, "%d", num)!=1 ) {
		write("Mud �W�١R\t\t" + get_config(__MUD_NAME__) + "\n"); 
		write("�����a�}�W�٦��A���𸹡R" + get_config(__ADDR_SERVER_IP__) + "\n"); 
		write("Mudlib ���|�R\t\t" + get_config(__MUD_LIB_DIR__) + "\n"); 
		write("MudOS �����ɸ��|�R\t" + get_config(__BIN_DIR__) + "\n"); 
		return 1;
	}

	printf("get_config(%d) = %O\n", num, get_config(num));
	return 1;
}

int help(object me)
{
write(@HELP
���O�榡 : config

Show �X�� MUD �� Startup Configuration �C
HELP
     );
     return 1;
}
