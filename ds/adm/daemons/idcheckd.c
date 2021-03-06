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
	string euid;			//檢查id 是已登入moblist
					//有登入傳回mob name 反之傳回"no"

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

	if( geteuid(previous_object())!= ROOT_UID ) return notify_fail("加入失敗!!\n");
	if( userp(ob) )	return notify_fail("這是玩家不是怪物!\n");	//檢查是否為玩家
	if( living(ob) ) uid = ob->query("id");				//檢查是否為生物
	else return notify_fail("這不是生物喔!!\n");
	if(!uid) return notify_fail("此id無效!!\n");
	if(!stringp(uid)) return notify_fail("此id無效!!\n");
/*	i = strlen(uid);
		while(i--)
		if( uid[i]<'a' || uid[i]>'z' )
		{
		 return notify_fail("此id無效!!\n");
		}
*/
	uid = replace_string( uid, " ", "_");
	if(stringp(read_file("/data/user/" + uid[0..0] + "/" + uid + ".o"))) //檢查是否有玩家為此id
		return notify_fail("已經有此id的玩家了!!\n");
	if(!undefinedp(mob_status[uid]) && !flag )		 //檢查是否有玩家為此id
		return notify_fail("已經有此id的mob了!!\n");
	if(undefinedp(mob_status[uid]) && flag ) 		//檢查是否有mob為此id
		return notify_fail("這個mob的id尚未定義!!\n");
	status = ob->query("name");
	if( !stringp(status) ) return notify_fail("怪物的 name 有錯誤!!\n");
	if(flag)						//flag == 1 則為刪除
	{
			map_delete(mob_status, uid);
			logflag = " 刪除 ";
	}
	else
	{
			mob_status[uid] = status;
			logflag = " 加入 ";
	}
	mob = keys(mob_status);
	for(moblist = "", i=0; i<sizeof(mob); i++)
		moblist += mob[i] + " " + mob_status[mob[i]] + "\n";
	rm(MOBLIST);
	write_file(MOBLIST,moblist);
	
	log_file( "setmob", "[" + geteuid(me) + "] " + logflag
	 + uid + "(" + status + ") on " + ctime(time()) + "\n" );
	if(flag) tell_object(me,uid+"刪除ok!!\n");
	else tell_object(me,uid+"加入ok!!\n");
	return 1;
}
