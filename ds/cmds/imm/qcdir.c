// ls.c
//
// Modified by Kenny@Broken.History (1/29/1997)
// �ɮרӷ�.. �V�P�ɪ�
 
#include <ansi.h>
 
inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
	int i, j, w, col,k;
	string dir,out,code,name;
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
 	if(file_size(dir+"file_list.txt")>0)
 	{
 		out="�o�{�֨��� file_list.txt Ū���֨���.\n�Y�n��s�֨���rm file_list.txt\n";
 		out+=read_file(dir+"file_list.txt");
 		write(out);
 		return 1;
 	}
	i = sizeof(file);
	w = 0;
	while(i--) {
		if (file[i][1]==-2) file[i][0] += "/";
		if (strlen(file[i][0])>w) w = strlen(file[i][0]) + 1;
	}
	out="�ؿ��R" + dir + "\n";
	col = 70 / (w+6);
	k=0;
	if (sizeof(file))
		for(i=0, j = sizeof(file); i<j; i++) {
			if (strsrch(file[i][0], "/") >= 0) continue; // dir
			if(file[i][0][strlen(file[i][0])-2..strlen(file[i][0])-1]!=".c") continue;
			write(file[i][0]+" ...");
 			if(!code=read_file(dir+file[i][0]))
 			{
 				write("error. can't read_file \n");
 				continue;
 			}
 			if(sscanf(code,"%*sset_name(\"%s\"%*s",name)!=3)
 			if(sscanf(code,"%*sset_name(%*s\"%s\"%*s",name)!=4)
 			{
 				write("error. can't find name \n");
 				continue;
 			}
			if(strlen(name)>30)
			{
				write(sprintf("%d -> %s\n",strlen(name),name));
				continue;
			}
			write("ok\n");
			out+=sprintf("%-18s  %-18s%s"
				,file[i][0]
				,name
				,((k+1)%2)?"  ":"\n"
				);
			k++;
                }
	else out+="    �S�������ɮסC\n";
	out+="\n";
	write(out);
	write_file(dir+"file_list.txt", out);
	return 1;
}
 
int help(object me)
{
	write(@HELP
���O�榡�Rqcdir [<���|�W>]

�C�X�ؿ��U�Ҧ��ɮת��󪺤���W�١C

HELP
	);
	return 1;
}
