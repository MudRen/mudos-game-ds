#include <mudlib.h>
#include <ansi.h>
string which_club;

int sort_member(object ob1, object ob2)
{
	int lv1,lv2;
	lv1=CLUB_D->check_member(which_club,getuid(ob1));
	lv2=CLUB_D->check_member(which_club,getuid(ob2));
	if(lv1 == lv2) return (int)ob1->query("level") - (int)ob2->query("level");
	else return (lv1 - lv2);
}
string show_level(object user,int flag)
{
 int level;
 mapping info;
 string str,output;

		 level=user->query("level");
		 if(level>100) 	str = "【????????】";
		 else if(level<11)	str = "【第 "+chinese_number(level)+" 級】";
		 else if(level<21) 	str = "【第"+chinese_number(level)+"級】";
		 else if(level%10==0)   str = "【第"+chinese_number(level)+"級】";
		 else str = "【"+chinese_number(level)+"級】";

		 info=CLUB_D->query_member_info(which_club,getuid(user));
		if(flag)
		{
		 output=sprintf("升降時間:%-6s 升降者:%s\n%10s %-24s 幫會等級: %-2d 分屬:%-6s ",
		 	(stringp(info["info2"]) && strlen(info["info2"])>10)? info["info2"][4..9]:"無",
		 	stringp(info["info3"])? info["info3"]:"無",
		 	str,
		 	user->name_id(1),
		 	info["level"],
		 	stringp(info["info1"])? info["info1"]:"無",
		 	);
		 }
		 else 
		 {
		 output=sprintf("%10s %-24s 幫會等級: %-2d 分屬:%-8s ",
		 	str,
		 	user->name_id(1),
		 	info["level"],
		 	stringp(info["info1"])? info["info1"]:"無",
		 	);
		 }
	
 return output;
}

string list_club_member(string clubid,string clubname,int flag)
{
	int i,ppl_cnt,idle;
	string str;
	object *users;
	which_club=clubid;
	users = CLUB_D->find_online_members(clubid);
	str=sprintf("\n◎ %s: \n",clubname);
	str += "─────────────────────────────────────\n";
	if(sizeof(users)<1)
	{
		str+="目前線上並無幫會成員。\n";
		return str;
	}
	users = sort_array(users, "sort_member", this_object());
	ppl_cnt = 0;
	i = sizeof(users);
	while( i-- )
	{
			// Skip those users in login limbo.
			if(wizardp(users[i])) continue;
			str = sprintf("%s%s",
				str,
				show_level(users[i],flag),
			);
			if(users[i]->query_temp("killer")) str+=HIR" [殺人犯]"NOR;
			idle=query_idle(users[i]);
			if(users[i]->query_temp("invis")) str+=HIB"(隱形)"NOR;
			if(users[i]->query_temp("netdead")) str+=HIG"<斷線中>"NOR;
			if(idle>60) str +=sprintf(HIY" (發呆%d分鐘)"NOR,idle/60);
			str +=sprintf("\n"NOR);
			ppl_cnt++;
	}
	str += "─────────────────────────────────────\n";
	str = sprintf("%s目前共有 %d 位成員在線上.\n", str, ppl_cnt);
	return str;

}

int main(object me,string arg)
{
	string str="";
	int flag;
	if(arg=="-l") flag=1;
		else flag=0;
	str+=list_club_member("dragon","狂龍幫",flag);
	str+=list_club_member("moon","月族",flag);
	str+=list_club_member("sky","天地會",flag);
        str+=list_club_member("god","神族",flag);
	this_player()->start_more(str);
	return 1;
}


int help(object me)
{
   write( @HELP
指令格式: clubinfo <-l>

這個指令可以列出目前線上的幫會成員資料。

HELP
   );
   return 1;
}
