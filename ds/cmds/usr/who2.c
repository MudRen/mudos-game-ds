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
						write("�����T���w�e�X�M�еy�ԡC\n");
						return 1;
					}
					return notify_fail("���O�榡�Rwho [-l|-i|-w|-c]\n");
			}
	}

	str = "�� " HIC+ MUD_NAME +NOR "\t\t\t�i�w�g����F"+query_time()+"�j\n";
	str += "�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w\n";
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
//				list[j]->query("nickname")==0? " ":" �u"+list[j]->query("nickname")+"�v"
			);
			if(opt_long && temp=list[j]->query("nickname")) str+="  ��"+temp; //�Ȯɴ���
			if( in_edit(list[j]) ) str += HIY " <�s���ɮ�>" NOR;
			if( in_input(list[j]) ) str += HIY " <��J�Ҧ�>" NOR;
			if(list[j]->query("putjail_position")) str+=HIY" [���c��]"NOR;
			if(list[j]->query_temp("killer")) str+=HIR" [���H��]"NOR;
			idle=query_idle(list[j]);
			if(list[j]->query_temp("invis")) str+=HIB"(����)"NOR;
			if(list[j]->query_temp("hide")) str+=HBK"(����)"NOR;
			if(list[j]->query_temp("netdead")) str+=HIG"<�_�u��>"NOR;
			if(list[j]->is_inactive()) str+=HIW"[���m]"NOR;
			if(idle>60) str +=sprintf(HIY" (�o�b%d����)"NOR,idle/60);
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
		
	str += "�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w\n";
	str = sprintf("%s�@�� %d ��ϥΪ̳s�u���M�t�έt��R%s\n", str, ppl_cnt,
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
		 case 1: ok=HIY"�j�N "NOR; break;
		 case 2: ok=HIG"�{�N "NOR; break;
		 case 3: ok=HIC"���� "NOR; break;
		 default: ok=HBK"�ڤ� "NOR;
		}
		
		if(stringp(nick=user->query("nickname")))
		ok += "�y "+nick+" �z";
		else ok += "�y "+BLU+"�L�W�p��"+NOR+" �z";
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
 	return "�i????????�j";
 if(level<11)
 	return "�i�� "+chinese_number(level)+" �šj";
 if(level<21)
 	return "�i��"+chinese_number(level)+"�šj";
 if(level%10==0)
 	return "�i��"+chinese_number(level)+"�šj";
  return "�i"+chinese_number(level)+"�šj";
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

	if(d) time = chinese_number(d) + "��";
	else time = "";

	if(h) time += chinese_number(h) + "�p��";
	if(m) time += chinese_number(m) + "��";
	time += chinese_number(s) + "��";
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
	str += "\n���w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w��\n";
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

	str += "���w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w��\n";
	str += sprintf("  �ثe�@�� %d �H���b�_�u���C\n",ppl_cnt);
	return str;

}

int help(object me)
{
write(@HELP
���O�榡 : who [-l|-i|-w|-c|-t]

�o�ӫ��O�i�H�C�X�Ҧ��b�u�W�����a�Ψ䵥�šC

-l �ﶵ�C�X�������T���C
-c �P -l ���H�u�C�X�P¾�~�̡C
-t �P -l �H¾�~�����N�����šC
-i �u�C�X���a���^��N���C
-w �u�C�X�u�W�Ҧ����Ův�C
-nd �C�X�u�W���b�_�u�����a�C(�u���Ův�i�H�ϥ�)
�������O�R finger
HELP
    );
    return 1;
}
