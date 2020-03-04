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
		 if(level>100) 	str = "�i????????�j";
		 else if(level<11)	str = "�i�� "+chinese_number(level)+" �šj";
		 else if(level<21) 	str = "�i��"+chinese_number(level)+"�šj";
		 else if(level%10==0)   str = "�i��"+chinese_number(level)+"�šj";
		 else str = "�i"+chinese_number(level)+"�šj";

		 info=CLUB_D->query_member_info(which_club,getuid(user));
		if(flag)
		{
		 output=sprintf("�ɭ��ɶ�:%-6s �ɭ���:%s\n%10s %-24s ���|����: %-2d ����:%-6s ",
		 	(stringp(info["info2"]) && strlen(info["info2"])>10)? info["info2"][4..9]:"�L",
		 	stringp(info["info3"])? info["info3"]:"�L",
		 	str,
		 	user->name_id(1),
		 	info["level"],
		 	stringp(info["info1"])? info["info1"]:"�L",
		 	);
		 }
		 else 
		 {
		 output=sprintf("%10s %-24s ���|����: %-2d ����:%-8s ",
		 	str,
		 	user->name_id(1),
		 	info["level"],
		 	stringp(info["info1"])? info["info1"]:"�L",
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
	str=sprintf("\n�� %s: \n",clubname);
	str += "�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w\n";
	if(sizeof(users)<1)
	{
		str+="�ثe�u�W�õL���|�����C\n";
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
			if(users[i]->query_temp("killer")) str+=HIR" [���H��]"NOR;
			idle=query_idle(users[i]);
			if(users[i]->query_temp("invis")) str+=HIB"(����)"NOR;
			if(users[i]->query_temp("netdead")) str+=HIG"<�_�u��>"NOR;
			if(idle>60) str +=sprintf(HIY" (�o�b%d����)"NOR,idle/60);
			str +=sprintf("\n"NOR);
			ppl_cnt++;
	}
	str += "�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w\n";
	str = sprintf("%s�ثe�@�� %d �즨���b�u�W.\n", str, ppl_cnt);
	return str;

}

int main(object me,string arg)
{
	string str="";
	int flag;
	if(arg=="-l") flag=1;
		else flag=0;
	str+=list_club_member("dragon","�g�s��",flag);
	str+=list_club_member("moon","���",flag);
	str+=list_club_member("sky","�Ѧa�|",flag);
        str+=list_club_member("god","����",flag);
	this_player()->start_more(str);
	return 1;
}


int help(object me)
{
   write( @HELP
���O�榡: clubinfo <-l>

�o�ӫ��O�i�H�C�X�ثe�u�W�����|������ơC

HELP
   );
   return 1;
}
