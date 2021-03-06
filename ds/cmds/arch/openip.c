// force.c
#define BANNED_IP_LIST "/adm/etc/bannedip"
inherit F_CLEAN_UP;
int sort_ip_list(string id1, string id2);
void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	int i,flag,a,b,c,d,line=1;
	string *list,str,file;
	object ob;
	if( file_size(BANNED_IP_LIST) > 0 )
	{
		list = explode(read_file(BANNED_IP_LIST), "\n");
		flag=1;
	}
	list = sort_array(list, "sort_ip_list", this_object());
	if(!arg)
	{
		if(flag)
		{
			str="\n  目前列入黑名單的IP如下: \n\n";
			for(i=0;i<sizeof(list);i++)
			{
				if(line>=3)
				{
					str+=sprintf("%-22s\n",list[i]);
					line=0;
				}
				else str+=sprintf("%-22s",list[i]);
				line++;
			}
			str+="\n";
			write(str);
			return 1;
		}
		return notify_fail(" 目前並沒有任何IP被列入黑名單。\n");
	}
	
	if(sscanf(arg, "%d.%d.%d.%d",a,b,c,d) != 4 ) return notify_fail(" IP格式錯誤。\n");
	if(a>255||a<1||b>255||b<0||c>255||c<0||d>255||d<0) return notify_fail(" IP格式錯誤。\n");
	
 	if( member_array(arg, list) ==-1 ) return notify_fail(" IP: "+arg+" 並沒有列入黑名單。\n");
	list-=({arg});
	list-=({""});
	list-=({"\n"});
	file="";
	for(i=0;i<sizeof(list);i++)
	{
		if(list[i]=="") continue;
		file+=list[i]+"\n";
	}
	rm(BANNED_IP_LIST);
	write_file(BANNED_IP_LIST, file);
	write("\n  IP: "+arg+" 已由黑名單中刪除!\n");
		log_file( "bannedip", capitalize(getuid(me))+" Reopen an IP:[ " + arg + "] on " + ctime(time()) + "\n" );
	return 1;
}
int sort_ip_list(string id1, string id2)
{
	return strcmp(id1,id2);
}
int help(object me)
{
	write(@Help
指令格式﹕openip <ip> 

刪除黑名單中某一個IP, 開放玩家由此IP進入遊戲。

參考指令: banip
Help
	);
	return 1;
}
