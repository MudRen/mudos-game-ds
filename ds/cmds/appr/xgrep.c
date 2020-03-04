// xgrep.c 
// write by JackyBoy@CuteRabbit Studio for SDXL & CCTX 1999/6/1
// ���F�קK���k�Ӳ`�A�Ф��n�]�m�i�J�ŧO�W�L16��. JackyBoy
inherit F_CLEAN_UP;
int help();
int do_grep(string,string,int);
string resolvePath(string,int);

static string pattern;
static string result;

int main(object me, string arg)
{
	string  path,wild;
	int level;
	level=1;
	result="�ǰt��󦳡G\n";
	seteuid(geteuid(me));
	write("X grep �R�O v0.1  \nWrite By JackyBoy@CuteRabbit for CCTX & SDXL 1999/6/1\n"+
		"�D���Ghttp://mud.yn.cninfo.net/jackyboy\n�l��Gjackyboy@126.com\n");
    if (!arg) return help();
    if (sscanf(arg,"-d %s %s",path,pattern)!=2)
    {
    	if(sscanf(arg,"-d%d %s %s",level,path,pattern)!=3)
    		if(sscanf(arg,"%s %s",path,pattern)!=2)
    		{
    			write ("\n�ѼƸѪR���~�C\n\n");
    			return help();
    		}
    }
    else
    	level=15;//�a-d�Ѽ��q�{�ŧO���Ҧ���
    if(level<0) level=1;
    if(level>15) level=15;
    //�B�zpath���ѥXwild
    path=resolve_path(me->query("cwd"),path);
    write("���ѪR���|�G\t"+path+"\n");
    //write("���j���r�Ŧ�G\t"+pattern+"\n");
    write("�j���ؿ��ŧO�G\t"+level+"\n");
    wild=resolvePath(path,0);
    path=resolvePath(path,1);
    write("�ѪR�Z���|�G\t"+path+"\n");
    write("�ѪR�Z�q�t�šG\t"+wild+"\n\n");
    do_grep(path,wild,level);
    write("\n�j�������C\n");
    write(result+"\n");
	return 1;
}

string resolvePath(string path,int op)
{
	string *dn,tmp;
	int i;
	if(path=="/")//��o�ӱ��p�S��B�z
		return (op)?"/":"*";
	dn=explode(path,"/");
	if(op)//op���D0��ܻݭn��^���|
	{
		//dn=dn-({dn[sizeof(dn)-1]});
		//tmp=implode(dn,"/")+"/";
		//�W�����{�Ǥ��n�A�����P�W���|���T�B�z�A��p����b/log/log��󨽷j��
		tmp="/";
		for(i=0;i<sizeof(dn)-1;i++)
		{
			//write("�X�}"+dn[i]+"\n");
			tmp+=dn[i]+"/";
		}
		return tmp;
	}
	else
		return dn[sizeof(dn)-1];
}
int do_grep(string path,string wild,int level)
{
	//int i;string *fs;
	string sbuffer,file;
	reset_eval_cost();//���s�]�m�ѧE����ɶ��A�����]�m�I
	if(this_player()->query("env/debug"))
		write("�}�l�j��"+path+wild+"\n");
	if(level<0)
	{
		//write("�ŧO����A����A�i�J�j���C\n");
		return 0;
	}
	//for(i=0;i<(sizeof(fs=get_dir(path+wild))-1);i++)
	//	write(fs[i]+"\n");
	
	foreach(file in get_dir(path+wild))
	{
		//write("�ˬd�G"+path+file+"\n");
		//write("file_size��^�G"+file_size(path+file)+"\n");
		if(file=="."||file=="..")
			continue;
		
		switch(file_size(path+file))
		{
			case -1:
				//�L�kŪ���ӥؿ��A���L
				break;
			case -2:
				if(file!="."&&file!="..")
					do_grep(path+file+"/","*",level-1);
				break;
			default:
				//write("�ˬd���G"+path+file+"\n");
				if(!sbuffer=read_file(path+file))
				//��Ӥj�����Ū���i��n���ѡI�ӥB����չ�Ū���G�i����A�]���t��\0!
				{
					write("Ū���"+path+file+"�X���I\n");
					return 0;
				}
				if(strsrch(sbuffer,pattern)!=-1)
					result=result+"�b"+path+file+"�����"+pattern+"\n";//���ӬO�O���U�ӡA�̦Z�A��X
			/*
				if(strsrch(read_file(path+file),pattern)!=-1)
					write(path+file+"\n");
				break;
			*/
		}
		
	}
	return 1;
}

int help()
{
  write(@HELP

X grep �R�O v0.1  Write By JackyBoy@CuteRabbit for CCTX & SDXL 1999/6/1
�D���Ghttp://mud.yn.cninfo.net/jackyboy
�l��Gjackyboy@126.com


���O�榡 : xgrep [-d[0-15]] ���| �Q�n�j�����r�Ŧ�
�����O�i���A�b���w(���F�ؿ��A�i�H�γq�t�Ũӫ��w)�ɮשΥؿ����M��t���n
�j�����r�Ŧꪺ���A�}�N���m��ܥX�ӡC
�`�N�A�q�{�ȷj����e�ؿ��I
�w��BUG�G
��G�i����i��j���N�|�X���A�]���T��N'\0'�]�m��@��string���I
HELP
    );
    return 1;
}
