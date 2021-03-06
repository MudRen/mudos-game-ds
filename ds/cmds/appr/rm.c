// rm.c

#include "/doc/help.h"

inherit F_CLEAN_UP;
int help(object me);

int main(object me, string file)
{
	seteuid(geteuid(me));
    if (!file) return notify_fail("你要刪除那個檔案?\n");
    file=resolve_path(me->query("cwd"),file);
	if( rm(file) )
	{
		log_file("rm.log",
			sprintf("%s(%s) 刪除 %s on %s\n",
			me->name(1),   //記錄使用命令的人名
			geteuid(me),   //記錄使用命令的ID
			file,          //記錄刪除的文件路徑
			ctime(time()) ) ); //記錄使用命令的時間
		write("Ok.\n");
	}
	else
		write("你沒有刪除這個檔案的權利。\n");
	return 1;
}

int help(object me)
{
  write(@HELP
指令格式 : rm <檔名>

此指令可讓你(妳)刪除有權修改的檔案。
HELP
    );
    return 1;
}
