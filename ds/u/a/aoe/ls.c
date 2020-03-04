// ls.c
//
// Modified by Kenny@Broken.History (1/29/1997)
// �ɮרӷ�.. �V�P�ɪ�
 
#include <ansi.h>
 
inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
	int mark_loaded;
	int i, j, w, col;
	string dir;
	mixed *file;
 
	seteuid(geteuid(me));
	dir = resolve_path(me->query("cwd"), arg);
	if( file_size(dir)==-2 && dir[strlen(dir)-1] != '/' ) dir += "/";
	file = get_dir(dir, -1);
	if( !sizeof(file) )
	{if (file_size(dir) == -2) return notify_fail("�ؿ��O�Ū��C\n");
		else
		return notify_fail("�S���o�ӥؿ��C\n");
	}
 
	i = sizeof(file);
	w = 0;
	while(i--) {
		if (file[i][1]==-2) file[i][0] += "/";
		if (strlen(file[i][0])>w) w = strlen(file[i][0]) + 1;
	}
	write("�ؿ��R" + dir + "\n");
	col = 70 / (w+6);
	if (sizeof(file))
		for(i=0, j = sizeof(file); i<j; i++) {
			int mode=0;	// unloaded file
			
			if (strsrch(file[i][0], "/") >= 0) mode = 1; // dir
			else if (find_object(dir+file[i][0])) mode =2; // loaded file
 
			printf("%4d %-*s%s", file[i][1]/1024 + 1, w+1+
				(mode>0? 16: 9),
                                (mode==1? HIC: mode==2? HIR: "") +
				file[i][0] + (mode==2? "*": " ") + NOR,
				((i+1)%col)?"  ":"\n");
                }
	else write("    �S�������ɮסC\n");
	write("\n");
	
	return 1;	
}
 
int help(object me)
{
	write(@HELP
���O�榡�Rls [<���|�W>]
 
�C�X�ؿ��U�Ҧ����l�ؿ����ɮסM�p�G�S�����w�ؿ��M�h�C�X�Ҧb�ؿ�
�����e�M�ҦC�X���ɮפ��e���Х� * �����O�w�g���J������C
 
�d��:
'ls /' �|�C�X�Ҧ����ڥؿ��U���ɮפΤl�ؿ��C
 
�������O�Rcd�Bpwd�C
HELP
	);
	return 1;
}
