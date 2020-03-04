// xcp.c 
// write by JackyBoy@CuteRabbit Studio for SDXL & CCTX 1999/6/1
// ���F�קK���k�Ӳ`�A�Ф��n�]�m�i�J�ŧO�W�L16��. JackyBoy
// Tips:���F���v�T�i�H�s��o�R�O�AX�t�C�R�O�i�H�N���k�i��call_out�եΡI
//      ���o�u�O�Q�k�ڦۤv�}���h��{��!

inherit F_CLEAN_UP;
int help();
int do_cp(string,string,string,int);
string resolvePath(string,int);
int main(object me, string arg)
{
	string  path,wild,dest;
	int level;
	level=15;
	seteuid(geteuid(me));
	write("X c �R�O v0.1  \nWrite By JackyBoy@CuteRabbit for CCTX & SDXL 1999/6/1\n"+
		"�D���Ghttp://mud.yn.cninfo.net/jackyboy\n�l��Gjackyboy@126.com\n");
    if (!arg) return help();
    if (sscanf(arg,"-d %s %s",path,dest)!=2)
    {
    	if(sscanf(arg,"-d%d %s %s",level,path,dest)!=3)
    		if(sscanf(arg,"%s %s",path,dest)!=2)
    		{
    			write ("\n�ѼƸѪR���~�C\n\n");
    			return help();
    		}
    }
    else
    	level=15;//�a-d�Ѽ��q�{�ŧO���Ҧ���
    if(level<0) level=1;
    if(level>15) level=15;
    dest=resolve_path(me->query("cwd"),dest);
    //�B�zpath���ѥXwild
    path=resolve_path(me->query("cwd"),path);
    write("���ѪR���|�G\t"+path+"\n");
    //write("���_��ت����|�G\t"+dest+"\n");
    write("�j���ؿ��ŧO�G\t"+level+"\n");
    wild=resolvePath(path,0);
    path=resolvePath(path,1);
    write("�ѪR�Z���|�G\t"+path+"\n");
    write("�ѪR�Z�q�t�šG\t"+wild+"\n");
    write("�ѪR�Z�ؼи��|�G\t"+dest+"\n\n");
    do_cp(path,wild,dest,level);
    write("\n�_����C\n");
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
int do_cp(string path,string wild,string dest,int level)
{
	//int i;string *fs;
	string file;
	reset_eval_cost();//���s�]�m�ѧE����ɶ��A�����]�m�I
	if(dest[sizeof(dest)-1]!='/')//�o�y�����i�֡A���M�N���ॿ�T�ͦ��ؼи��|
    	dest=dest+"/";
	if(this_player()->query("env/debug"))
		write("�}�l�_��"+path+wild+"��"+dest+"\n");
	if(level<0)
	{
		//write("�ŧO����A����A�i�J�C\n");
		return 0;
	}
	
	foreach(file in get_dir(path+wild))
	{

		if(file=="."||file=="..")
			continue;
		
		switch(file_size(path+file))
		{
			case -1:
				//�L�kŪ���ӥؿ��A���L
				break;
			case -2:
				if(file!="."&&file!="..")
					do_cp(path+file+"/","*",dest+file+"/",level-1);
				break;
			default:
				assure_file(dest+file);
				//write("�_����G"+path+file+"��"+dest+file+"\n");
				cp(path+file,dest+file);
		}
		
	}
	return 1;
}

int help()
{
  write(@HELP

X cp �R�O v0.1  Write By JackyBoy@CuteRabbit for CCTX & SDXL 1999/6/2
�D���Ghttp://mud.yn.cninfo.net/jackyboy
�l��Gjackyboy@126.com


���O�榡 : xcp [-d[0-15]] �����|�Τ�� �ؼи��|
�����O�i���A����w���ؿ��Τ��_�����w���ؿ��h�C
����q�t�šA�i�H���w�_��@�w���ؿ��`�סC
HELP
    );
    return 1;
}
