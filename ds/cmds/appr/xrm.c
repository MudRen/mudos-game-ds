// xrm.c 
//write by JackyBoy@CuteRabbit Studio for SDXL & CCTX 1999/6/2
inherit F_CLEAN_UP;
int help();
int rmDir(string );
static int flag; //�P�_�O�_�פ�k�եΡA�}����k�h��(�u���\�C�_16�h���ե�)

int main(object me, string file)
{
	seteuid(geteuid(me));
	write("X rm �R�O v0.1  \nWrite By JackyBoy@CuteRabbit for CCTX & SDXL 1999/6/1\n"+
		"�D���Ghttp://mud.yn.cninfo.net/jackyboy\n�l��Gjackyboy@126.com\n");
    if (!file) return notify_fail("�A�n�R�������ɮ�?\n");
	file=resolve_path(me->query("cwd"),file);
	log_file("xrm.log",
	sprintf("%s(%s) �R�� %s on %s\n",
	me->name(1),   //�O���ϥΩR�O���H�W
	geteuid(me),   //�O���ϥΩR�O��ID
	file,          //�O���R���������|
	ctime(time()) ) ); //�O���ϥΩR�O���ɶ�
	flag=0;
	switch(file_size(file))
	{
		case -1:
			write("�藍�_�A�A�L�v�R���o�ӥؿ�(�Τ��)�C\n");
			break;
		case -2:
			write("�R���ؿ�(���)��...\n");
			if(rmDir(file)==0)
				write("�R�����ѡC\n");
			else
				write("�R�����\\�C\n");
			break;
		default:
			if(rm(file) )
				write("�R�������C\n");
			else
				write("�A�S���R���o���ɮת��v�Q�C\n");
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
			flag=16;//�]�m�X�����_
			write("�������L�v�R���A���~�I\n");
			return 0;
			break;
		case -2 :
			//�R�����ؿ��U�����M�ؿ�
			if(file[sizeof(file)]!='/')
				file=file+"/";
			foreach(tmp in get_dir(file))
			{
				if(!rmDir(file+tmp))
				{
					flag=16;//���_�A�]���R���X��
					return 0;
				}
			}
			if(!rmdir(file))
			{
				flag=16;//���_�A�]���R���X��
				return 0;
			}
			break;
		default :
			if(!rm(file))
			{
				flag=16;//���_�A�]���R���X��
				return 0;
			}
			break;
	}
	return 1;
}

int help()
{
  write(@HELP

X rm �R�O v0.1
Write By JackyBoy@CuteRabbit for CCTX & SDXL 1999/6/1
�D���Ghttp://mud.yn.cninfo.net/jackyboy
�l��Gjackyboy@126.com


���O�榡 : xrm <�ɦW>
�����O�i���A�R�����v�ק諸�ɮסA�i�H�R���a�ؿ����ɮסC
�`�N�G���R�O����M�I�A�Фp�ߨϥΡC
HELP
    );
    return 1;
}
