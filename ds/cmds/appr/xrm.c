// xrm.c 
//write by JackyBoy@CuteRabbit Studio for SDXL & CCTX 1999/6/2
inherit F_CLEAN_UP;
int help();
int rmDir(string );
static int flag; //判斷是否終止遞歸調用，并限制遞歸層數(只允許低于16層的調用)

int main(object me, string file)
{
	seteuid(geteuid(me));
	write("X rm 命令 v0.1  \nWrite By JackyBoy@CuteRabbit for CCTX & SDXL 1999/6/1\n"+
		"主頁：http://mud.yn.cninfo.net/jackyboy\n郵件：jackyboy@126.com\n");
    if (!file) return notify_fail("你要刪除那個檔案?\n");
	file=resolve_path(me->query("cwd"),file);
	log_file("xrm.log",
	sprintf("%s(%s) 刪除 %s on %s\n",
	me->name(1),   //記錄使用命令的人名
	geteuid(me),   //記錄使用命令的ID
	file,          //記錄刪除的文件路徑
	ctime(time()) ) ); //記錄使用命令的時間
	flag=0;
	switch(file_size(file))
	{
		case -1:
			write("對不起，你無權刪除這個目錄(或文件)。\n");
			break;
		case -2:
			write("刪除目錄(文件)中...\n");
			if(rmDir(file)==0)
				write("刪除失敗。\n");
			else
				write("刪除成功\。\n");
			break;
		default:
			if(rm(file) )
				write("刪除完成。\n");
			else
				write("你沒有刪除這個檔案的權利。\n");
	}
	return 1;
}

int rmDir(string file)
{
	string tmp;
	if(flag>15)
		return 0;
	reset_eval_cost();
	switch(file_size(file))
	{
		case -1 : 
			flag=16;//設置出錯中斷
			write("部分文件無權刪除，錯誤！\n");
			return 0;
			break;
		case -2 :
			//刪除此目錄下的文件和目錄
			if(file[sizeof(file)]!='/')
				file=file+"/";
			foreach(tmp in get_dir(file))
			{
				if(!rmDir(file+tmp))
				{
					flag=16;//中斷，因為刪除出錯
					return 0;
				}
			}
			if(!rmdir(file))
			{
				flag=16;//中斷，因為刪除出錯
				return 0;
			}
			break;
		default :
			if(!rm(file))
			{
				flag=16;//中斷，因為刪除出錯
				return 0;
			}
			break;
	}
	return 1;
}

int help()
{
  write(@HELP

X rm 命令 v0.1
Write By JackyBoy@CuteRabbit for CCTX & SDXL 1999/6/1
主頁：http://mud.yn.cninfo.net/jackyboy
郵件：jackyboy@126.com


指令格式 : xrm <檔名>
此指令可讓你刪除有權修改的檔案，可以刪除帶目錄的檔案。
注意：此命令比較危險，請小心使用。
HELP
    );
    return 1;
}
