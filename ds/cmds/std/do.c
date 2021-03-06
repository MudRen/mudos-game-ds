#include <ansi.h>
#define MAX_DO_DEEPTH 40
inherit F_CLEAN_UP;
void create() { seteuid( ROOT_UID ); }

int main(object me, string cmds)
{
	string cmd="",check="",process_cmd="",new_cmds="";
	int count=0;
	if(!cmds) return 0;
	if( sscanf(cmds,"!,%s",check)==1 ) return notify_fail("第一個指令不可用\"!\".\n");
	if( strsrch(cmds,"do ",0)!=-1 ) return notify_fail("do裡面不可再用\"do\".\n");
	//seteuid( geteuid(me) );
	while(sizeof(cmds))
	{
		count++;
		if(count>MAX_DO_DEEPTH)
		{
			write("[連續指令過多或是造成迴圈, 系統強迫中斷。]\n");
			return 1;
			//return notify_fail("[連續指令過多或是造成迴圈, 系統強迫中斷。]\n");
		}
		if(sscanf(cmds,"%s,%s",cmd, cmds)==2) process_cmd=me->process_input(cmd,1);
		else
		{
			process_cmd=me->process_input(cmds,1);
			cmds="";
		}
		if(process_cmd && sscanf(process_cmd,"do %s",new_cmds)==1)
		{
			if(new_cmds[sizeof(new_cmds)-1..sizeof(new_cmds)-1]!=",") cmds=new_cmds+","+cmds;
			else cmds=new_cmds+cmds;

		} else if(stringp(process_cmd)) me->force_me(process_cmd);
	}

	return 1;

}

int help(object me)
{
	write(@HELP
指令格式﹕do
指令說明﹕這個指令可以讓你一次下多個指令。
 
    (1). 你可以用 do 來一次下多個命命。
 
	 如﹕在走路時可用 [範例]: do e,s,s,e,s,s,e,w
 
    (2). 可用 " ! " 符號來執行上一命令。
 
	 [範例]: do train sword,!,!,!,!,!
 
    本指令亦可配合alias使用。
 
HELP);
    return 1;
}
