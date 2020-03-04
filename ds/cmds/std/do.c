#include <ansi.h>
#define MAX_DO_DEEPTH 40
inherit F_CLEAN_UP;
void create() { seteuid( ROOT_UID ); }

int main(object me, string cmds)
{
	string cmd="",check="",process_cmd="",new_cmds="";
	int count=0;
	if(!cmds) return 0;
	if( sscanf(cmds,"!,%s",check)==1 ) return notify_fail("�Ĥ@�ӫ��O���i��\"!\".\n");
	if( strsrch(cmds,"do ",0)!=-1 ) return notify_fail("do�̭����i�A��\"do\".\n");
	//seteuid( geteuid(me) );
	while(sizeof(cmds))
	{
		count++;
		if(count>MAX_DO_DEEPTH)
		{
			write("[�s����O�L�h�άO�y���j��, �t�αj�����_�C]\n");
			return 1;
			//return notify_fail("[�s����O�L�h�άO�y���j��, �t�αj�����_�C]\n");
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
���O�榡�Rdo
���O�����R�o�ӫ��O�i�H���A�@���U�h�ӫ��O�C
 
    (1). �A�i�H�� do �Ӥ@���U�h�өR�R�C
 
	 �p�R�b�����ɥi�� [�d��]: do e,s,s,e,s,s,e,w
 
    (2). �i�� " ! " �Ÿ��Ӱ���W�@�R�O�C
 
	 [�d��]: do train sword,!,!,!,!,!
 
    �����O��i�t�Xalias�ϥΡC
 
HELP);
    return 1;
}
