#include <idcheck.h>

protected mapping mob_status;
string *legal_files = ({
	"/open/always/thief_mark", "/open/always/dragon_mark", "/open/always/moon_mark",
	 "/open/always/sky_mark", "/obj/roommaker","/obj/npcmaker","/obj/mailbox",
	 "/obj/cch",
});
void create() 
{
	string *moblist, mob_id, mob_name;
	int i;
	seteuid(getuid());
	if(read_file(MOBLIST))
	moblist = explode(read_file(MOBLIST), "\n");
	mob_status = allocate_mapping(sizeof(moblist));
	for(i=0; i<sizeof(moblist); i++)
	{
		if( moblist[i][0]=='#' 
		|| sscanf(moblist[i], "%s %s", mob_id, mob_name)!=2 ) continue;
		mob_status[mob_id] = mob_name;
	}

}

varargs void check_file(string file,object movetoenv)
{
	string str;
	if( member_array(file, legal_files)!=-1 ) return;
	str=read_file(file+".c");
	if(sizeof(str)<1) return;
	if(strsrch(str,"add_action",1) >0 )
	{
		if(!movetoenv)
		{
			log_file( "static/add_action", sprintf("[%s] File: %s.c have found add_action !!\n",
				ctime(time()),file) );
			return;
		}
		
		if(userp(movetoenv))
		{
			log_file( "static/add_action", sprintf("[%s] File: %s.c have found add_action! \n ..and Move to Player %s..\n",
				ctime(time()),file,movetoenv->name_id(1) ) );
			return;
		}
		log_file( "static/add_action", sprintf("[%s] File: %s.c have found add_action! \n ..and Move to %s..\n",
				ctime(time()),file,base_name(movetoenv) ) );
	}
	return;
}

string check_mob_id(mixed ob)
{
	string euid;			//�ˬdid �O�w�n�Jmoblist
					//���n�J�Ǧ^mob name �Ϥ��Ǧ^"no"

	if( objectp(ob) )
	{
		euid = ob->query("id");
		if( !euid ) euid = geteuid(ob);
		if( !euid ) euid = getuid(ob);
	}
	else if( stringp(ob) ) euid = ob;

	if( !undefinedp(mob_status[euid]) ) return mob_status[euid];
	else return 0;

}

string *query_moblist() { return keys(mob_status); }

int set_mob_id(object me,object ob,int flag)
{
	string uid, *mob, moblist, status,logflag;
	int i;

	if( geteuid(previous_object())!= ROOT_UID ) return notify_fail("�[�J����!!\n");
	if( userp(ob) )	return notify_fail("�o�O���a���O�Ǫ�!\n");	//�ˬd�O�_�����a
	if( living(ob) ) uid = ob->query("id");				//�ˬd�O�_���ͪ�
	else return notify_fail("�o���O�ͪ���!!\n");
	if(!uid) return notify_fail("��id�L��!!\n");
	if(!stringp(uid)) return notify_fail("��id�L��!!\n");
/*	i = strlen(uid);
		while(i--)
		if( uid[i]<'a' || uid[i]>'z' )
		{
		 return notify_fail("��id�L��!!\n");
		}
*/
	uid = replace_string( uid, " ", "_");
	if(stringp(read_file("/data/user/" + uid[0..0] + "/" + uid + ".o"))) //�ˬd�O�_�����a����id
		return notify_fail("�w�g����id�����a�F!!\n");
	if(!undefinedp(mob_status[uid]) && !flag )		 //�ˬd�O�_�����a����id
		return notify_fail("�w�g����id��mob�F!!\n");
	if(undefinedp(mob_status[uid]) && flag ) 		//�ˬd�O�_��mob����id
		return notify_fail("�o��mob��id�|���w�q!!\n");
	status = ob->query("name");
	if( !stringp(status) ) return notify_fail("�Ǫ��� name �����~!!\n");
	if(flag)						//flag == 1 �h���R��
	{
			map_delete(mob_status, uid);
			logflag = " �R�� ";
	}
	else
	{
			mob_status[uid] = status;
			logflag = " �[�J ";
	}
	mob = keys(mob_status);
	for(moblist = "", i=0; i<sizeof(mob); i++)
		moblist += mob[i] + " " + mob_status[mob[i]] + "\n";
	rm(MOBLIST);
	write_file(MOBLIST,moblist);
	
	log_file( "setmob", "[" + geteuid(me) + "] " + logflag
	 + uid + "(" + status + ") on " + ctime(time()) + "\n" );
	if(flag) tell_object(me,uid+"�R��ok!!\n");
	else tell_object(me,uid+"�[�Jok!!\n");
	return 1;
}
