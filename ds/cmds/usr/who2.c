// who.c
#include <ansi.h>
#include <net/i3.h>

inherit F_CLEAN_UP;
string show_level(object user,int flag);
string show_rank(object user,int flag);
string query_time();
string show_netdead_user();
void create() { seteuid(getuid()); }

mixed main(object me, string arg, int remote)
{
	string str, *option ,temp;
	object *list;
	int i, j, ppl_cnt,idle;
	int opt_long, opt_id, opt_wiz,opt_class,opt_type, opt_netdead;

	if( arg ) {
		option = explode(arg, " ");
		i = sizeof(option);
		while( i-- )
			switch(option[i]) {
				case "-l": opt_long = 1;	break;
				case "-c": opt_class = 1;	break;
				case "-i": opt_id = 1;		break;
				case "-w": opt_wiz = 1;		break;
				case "-t": opt_type = 1;	break;
				case "-nd": opt_netdead = 1;	break;
				default:
					if( wizardp(me)
					&&	option[i][0]=='@' )
					{
						str = replace_string(option[i][1..sizeof(option[i])],"."," ");
						I3_WHO->send_who_req(geteuid(me),str);
						write("網路訊息已送出﹐請稍候。\n");
						return 1;
					}
					return notify_fail("指令格式﹕who [-l|-i|-w|-c]\n");
			}
	}

	str = "◎ " HIC+ MUD_NAME +NOR "\t\t\t【已經執行了"+query_time()+"】\n";
	str += "─────────────────────────────────────\n";
//	list = users();
//	list = children("/obj/user");
	list = sort_array(users(), "sort_user", this_object());

	if( opt_long || opt_wiz || opt_class || opt_type) {
		ppl_cnt = 0;
		j = sizeof(list);
		while( j-- )
		{
			// Skip those users in login limbo.
			if( !environment(list[j]) ) continue;
			if( objectp(me) && !me->visible(list[j]) )
			{
				if(wizardp(list[j]) && list[j]->query_temp("invis")) continue;
			}
			if( opt_wiz && !wizardp(list[j]) ) continue;
			if( opt_class && list[j]->query("class1")!=me->query("class1")) continue;
			str = sprintf("%s%12s%-16s %s(%s)",
				str,
				//RANK_D->query_rank(list[j]),
				show_level(list[j],opt_type),
				show_rank(list[j],opt_type),
				//list[j]->short(1),
				//list[j]->query("title"),
				list[j]->name(1),
				list[j]->query("id"),
//				list[j]->query("nickname")==0? " ":" 「"+list[j]->query("nickname")+"」"
			);
			if(opt_long && temp=list[j]->query("nickname")) str+="  ☉"+temp; //暫時測試
			if( in_edit(list[j]) ) str += HIY " <編輯檔案>" NOR;
			if( in_input(list[j]) ) str += HIY " <輸入模式>" NOR;
			if(list[j]->query("putjail_position")) str+=HIY" [坐牢中]"NOR;
			if(list[j]->query_temp("killer")) str+=HIR" [殺人犯]"NOR;
			idle=query_idle(list[j]);
			if(list[j]->query_temp("invis")) str+=HIB"(隱形)"NOR;
			if(list[j]->query_temp("hide")) str+=HBK"(躲藏)"NOR;
			if(list[j]->query_temp("netdead")) str+=HIG"<斷線中>"NOR;
			if(list[j]->is_inactive()) str+=HIW"[閒置]"NOR;
			if(idle>60) str +=sprintf(HIY" (發呆%d分鐘)"NOR,idle/60);
			str +=sprintf("\n"NOR);
			ppl_cnt++;
		}
	} else 
	if(objectp(me) && wizardp(me) && opt_netdead==1 )
	{
		string strq;
		strq = show_netdead_user();
		me->start_more(strq);
		return 1;
	} else
	{
		ppl_cnt = 0;
		j = sizeof(list);
		while( j-- ) {
			// Skip those users in login limbo.
			if( !environment(list[j]) ) continue;
			if( me && !me->visible(list[j]) ) continue;
			str = sprintf("%s%-15s%s",
				str,
				opt_id ? capitalize(list[j]->query("id")): list[j]->name(1),
				(ppl_cnt%5==4? "\n": "")
			);
			ppl_cnt++;
		}
		if( ppl_cnt%5 ) str += "\n";
	}
		
	str += "─────────────────────────────────────\n";
	str = sprintf("%s共有 %d 位使用者連線中﹐系統負擔﹕%s\n", str, ppl_cnt,
		query_load_average() + "\n");

	if( remote ) return str;

	me->start_more(str);
	return 1;
}

int sort_user(object ob1, object ob2)
{
	if( wizardp(ob1) && !wizardp(ob2) ) return 1;
	
	if( wizardp(ob2) && !wizardp(ob1) ) return -1;

	if( wizardp(ob1) && wizardp(ob2) )
		return  (int)SECURITY_D->get_wiz_level(ob1)
			- (int)SECURITY_D->get_wiz_level(ob2);
	
	return  (int)ob1->query("level") - (int)ob2->query("level");
}

string show_rank(object user,int flag)
{
	string nick,ok;
	if(flag)
	{
		switch(user->money_type())
		{
		 case 1: ok=HIY"古代 "NOR; break;
		 case 2: ok=HIG"現代 "NOR; break;
		 case 3: ok=HIC"未來 "NOR; break;
		 default: ok=HBK"夢幻 "NOR;
		}
		
		if(stringp(nick=user->query("nickname")))
		ok += "『 "+nick+" 』";
		else ok += "『 "+BLU+"無名小卒"+NOR+" 』";
		return ok;
	}
		else return RANK_D->query_level(user);
}

string show_level(object user,int flag)
{
 int level;
 if(wizardp(user) || flag) return RANK_D->query_rank(user);
 level=user->query("level");
 if(level>100)
 	return "【????????】";
 if(level<11)
 	return "【第 "+chinese_number(level)+" 級】";
 if(level<21)
 	return "【第"+chinese_number(level)+"級】";
 if(level%10==0)
 	return "【第"+chinese_number(level)+"級】";
  return "【"+chinese_number(level)+"級】";
}

string query_time()
{
	int t, d, h, m, s;
	string time;

	t = uptime();
	s = t % 60;		t /= 60;
	m = t % 60;		t /= 60;
	h = t % 24;		t /= 24;
	d = t;

	if(d) time = chinese_number(d) + "天";
	else time = "";

	if(h) time += chinese_number(h) + "小時";
	if(m) time += chinese_number(m) + "分";
	time += chinese_number(s) + "秒";
	return time;
}

string show_netdead_user()
{
	object *list;
	int i, ppl_cnt;
	string str;
	list = children("/obj/user");
	list = sort_array(list, "sort_user", this_object());

	ppl_cnt = 0;
	str = "";
	str += "\n☆────────────────────────────────────☆\n";
	for(i=0;i<sizeof(list);i++)
	{
		if(list[i]->query_temp("netdead") == 1)
		{
			str += sprintf("  %s(%s)[%s]",list[i]->query("name"),
				list[i]->query("id"),
				file_name(environment(list[i])));
			ppl_cnt++;
			str += "\n";
		}
	}
	if( ppl_cnt == 0 ) str += "  None\n";

	str += "☆────────────────────────────────────☆\n";
	str += sprintf("  目前共有 %d 人正在斷線中。\n",ppl_cnt);
	return str;

}

int help(object me)
{
write(@HELP
指令格式 : who [-l|-i|-w|-c|-t]

這個指令可以列出所有在線上的玩家及其等級。

-l 選項列出較長的訊息。
-c 同 -l 但以只列出同職業者。
-t 同 -l 以職業種類代替等級。
-i 只列出玩家的英文代號。
-w 只列出線上所有的巫師。
-nd 列出線上正在斷線的玩家。(只有巫師可以使用)
相關指令﹕ finger
HELP
    );
    return 1;
}
