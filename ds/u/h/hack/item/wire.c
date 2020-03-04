// �ƽu.c added by comingin@DS 2000.7.2
// �֥X��F, �� wilfred ��@�Ǫ�� ( ps. �n���٬O�����n�� ).
// �� where �令 qwhere, �קK�P�� where.c ����.
// �ƽu.c by wilfred@DS 2000.6.19
// �\�γ���W�R��
// �ثe�\�ά� Where: �d�ݽu�W���a�����A members: �u�W�����|�H�� invis: �W�u�۰�����

#include <ansi2.h>
#include <mudlib.h>
#include <command.h>

#define CLUB_ID_DRAGON "dragon"
#define CLUB_NAME_DRAGON "�g�s��"
#define CLUB_ID_SKY "sky"
#define CLUB_NAME_SKY "�Ѧa�|"
#define CLUB_ID_MOON "moon"
#define CLUB_NAME_MOON "���"

inherit ITEM;

int do_invis();
string show_level(object user,string temp_club_name1,string temp_club_id1);
string query_ips(object *all_ppl, object current_ppl);
string query_status(object user);
void reply(object me, string msg);

static int dead_ppl = 0, j = 0;

void create()
{
	set_name(CYN"�ƽu"NOR, ({"wire"}));
	set("long",HIC"�@�����q���ƽu�A�q�`�O�ΨӶǿ�w�Ъ���ơA�@�륫���W������C\n"NOR""WHT"���i�Ϋ��O��"HIW"Qwhere  members  invis xset"NOR);
	set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit","��");
		set("value",1);
	}
	setup();
}

int query_autoload() { return 1; }

void init()
{
	add_action("do_where","qwhere");
	add_action("do_amembers","members");
	add_action("do_invis","invis");
	add_action("do_xset", "xset"); // �Ψӳ]�w�ﶵ��
	if( !this_player()->query_temp("invis") ) do_invis();
}

int do_xset(string arg)
{
	object me = this_player();

	if( !arg ) return notify_fail("���~�I�i�H�� xset ? �Ӭd�ߥi�]�w���ﶵ.\n");
	switch(arg)
	{
		case "no_ip": // �b qwhere ������� ip
			if( !query("qno_ip") ) // �p�G�� qno_ip
			{ set("qno_ip", 1); reply(me, "����� ip"); }
			else
			{ delete("qno_ip"); reply(me, "��� ip"); }
			break;
		case "no_wizard": // �b qwhere ������� wizard
			if( !query("qno_wiz") )
			{ set("qno_wiz", 1); reply(me, "����ܧŮv"); }
			else
			{ delete("qno_wiz"); reply(me, "��ܧŮv"); }
			break;
		case "?":
			reply(me, "�ثe�i�Ϊ��� no_ip, no_wiz");
			break;
		default:
			reply(me, "���~�I�i�H�� xset ? �Ӭd�ߥi�]�w���ﶵ");
	}
	return 1;
}

void reply(object me, string msg)
{
	tell_object(me, name()+"�^���G"+ msg + "�C\n");
}

int do_invis()
{
	object me = this_player();
	if( !me->query_temp("invis") )
	{
		write(WHT"�A�����F�A���p���ϯ��ƴ�.....\n");
		me->set_temp("invis",(int)SECURITY_D->get_wiz_level(me));
		return 1;
	}
	if( me->query_temp("invis") )
	{
		write(HIC"�A�����κ����B�{�X��....\n"NOR);
		me->delete_temp("invis");
		return 1;
	}
}

int do_where()
{
	int i, user_amount, idle, wiz;
	object *user_list, user_location;
	string status1, status2, status3, status4;
	string temp_lv, msg = "";

	j = 0;
	dead_ppl = 0;

//	user_list = children("/obj/user");
//	user_list = sort_array(user_list, "sort_user", this_object());

//	user_amount = sizeof(user_list) - 1;
	user_list = users();
	user_amount = sizeof(user_list);

	if( !query("qno_wiz") )  // ���C�X wizard
		for(i=0;i<user_amount;i++)
		{
			if( wizardp(user_list[i]) )
			{
				j++;
				msg += query_status(user_list[i]);
			}
		}

	for(i=0;i<user_amount;i++) // �A�C�X player
	{
		if( !wizardp(user_list[i]) )
		{
			j++;
			msg += query_status(user_list[i]);
		}
	}

	msg += sprintf("\n�ثe�u�W�@�� "HIC"%d"NOR" �W�ϥΪ̡A�䤤�� "HIR"%d"NOR" �W�_�u���C\n",user_amount,dead_ppl);
	this_player()->start_more(msg);
	return 1;
}

string query_ips(object *all_ppl, object current_ppl)
{
	string ip,temp_ip;
	int i;

	if(! ip = query_ip_number(current_ppl)) return "�L";
	for(i=0;i<sizeof(all_ppl);i++)
	{
		if(all_ppl[i] == current_ppl) continue;
		temp_ip = query_ip_number(all_ppl[i]);
		if( ip == temp_ip ) return HIC+ip+HIR" [�� Multi-Login ������]"NOR;
	}
	return ip;
}

string query_status(object user)
{
	object user_location;
	string msg = "", status1, status2, status3, status4 , status5 = "", ran;
	int idle;

	// �P�_���A.

	if( user->query_temp("netdead") == 1 )
	{
		user_location = find_object("/obj/void.c");
		idle = 0;
		status4 = HIG"(�_�u��)"NOR;
		dead_ppl++;
	}

	if( !user->query_temp("netdead") )
	{
		user_location = environment(user);
		if( userp(user) )
			idle = query_idle(user);
		else idle = 0;
		status4 = "";
	}

	if( in_input(user) )  status1 = NOR""WHT"[��J]"NOR;
		else  status1 = "";
	if( in_edit(user) ) status2 = NOR""YEL"[�s��]"NOR;
		else status2 = "";
	if( idle > 60 )
		status3 = sprintf( NOR""CYN"(�o�b�F %d ����)"NOR, idle/60);
	else status3 = "";
	if( user->query_temp("invis") > 0 )
		status4 = NOR""BLU"[����]"NOR;
	if( user->query_temp("hide") > 0 )
		status4 += HBK"(����)"NOR;
	if( user->is_inactive() )
		status4 += NOR""HIW"[���m]"NOR;
	if( user->query("putjail_position") )
		status4 += HIY" [���c��]"NOR;
	if( user->query_temp("killer") )
		status4 += HIR" [���H��]"NOR;

	// end.

	msg += sprintf("(%2d) %-12s"NOR" %s(%s) "NOR" %s(%s)\n"NOR,
		j,
		((wizardp(user)) ? HIW : "") + SECURITY_D->get_status(user),
		user->query("name"),
		user->query("id"),
		(string)user_location->query("short"),
		(string)file_name(user_location));

	switch(random(2)) // �[�J random ���ť�, �Ӿ�����C���n��..:Q
	{
		case 1:
			ran = " ";
			break;
		case 0:
			ran = "";
			break;
	}

	if( !query("qno_ip") ) 
		msg += sprintf("       " + ran + MAG"-> %15s �s�u�C"NOR, query_ips(users(),user));

	if ( (status1!="") || (status2!="") || (status3!="") || (status4!="") || (status5!="") )
		msg += sprintf(GRN"%s�@���A"NOR"�G%s%s%s%s%s\n", 
			((query("qno_ip")) ? ("       " + ran) : ""), status1, status2, status3, status4, status5);
//	else if( status1 == "" && status2 == "" && status3 == "" && status4 == "" )
//		msg += sprintf(HIG" ���A"NOR"�G�L�C\n");
	else if( !query("qno_ip") ) msg += "\n"NOR;
	return msg;
}

int do_amembers()
{
  object *users,me;
  string str,*list,temp_club_name,temp_club_id;
  int i,ppl_cnt,idle,loop;
  me=this_player();

  for(loop=0;loop<3;loop++)
  {
    switch(loop)
    {
      case 0 : temp_club_id = CLUB_ID_DRAGON;
               temp_club_name = CLUB_NAME_DRAGON;
               break;
      case 1 : temp_club_id = CLUB_ID_SKY;
               temp_club_name = CLUB_NAME_SKY;
               break;
      case 2 : temp_club_id = CLUB_ID_MOON;
               temp_club_name = CLUB_NAME_MOON;
               break;
    }
    users = CLUB_D->find_online_members(temp_club_id);

    str = "�� "+temp_club_name+": \n";
    str += "�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w\n";

    users = sort_array(users, "sort_member", this_object());

    ppl_cnt = 0;
    i = sizeof(users);
    while( i-- )
    {
      // Skip those users in login limbo.
      if(!me->visible(users[i]) && wizardp(users[i]) ) continue;
      str = sprintf("%s%12s%-16s %s(%s)",
        str,
        show_level(users[i],temp_club_name,temp_club_id),
        RANK_D->query_level(users[i]),
        users[i]->name(1),
        users[i]->query("id"),
      );
      if(users[i]->query_temp("killer")) str+=HIR" [���H��]"NOR;
      idle=query_idle(users[i]);
      if(users[i]->query_temp("invis")) str+=HIB"(����)"NOR;
      if(users[i]->query_temp("hide")) str+=HBK"(����)"NOR;
      if(users[i]->query_temp("netdead")) str+=HIG"<�_�u��>"NOR;
      if(idle>60) str +=sprintf(HIY" (�o�b%d����)"NOR,idle/60);
      str +=sprintf("\n"NOR);
      ppl_cnt++;
    }
    str += "�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w\n";
    str = sprintf("%s�ثe�@�� %d �즨���b�u�W.\n", str, ppl_cnt);
    this_player()->start_more(str);
  }
  return 1;
}

string show_level(object user,string temp_club_name1,string temp_club_id1)
{
  int level,rank;
  mapping info;
  string str;
  if(wizardp(user)) return "�i�a�A�|���j"+temp_club_name1+"�S���U��  ";
  level=user->query("level");
  if(level>100)  str = "�i????????�j";
  else if(level<11)      str = "�i�� "+chinese_number(level)+" �šj";
  else if(level<21)      str = "�i��"+chinese_number(level)+"�šj";
  else if(level%10==0)   str = "�i��"+chinese_number(level)+"�šj";
  else str = "�i"+chinese_number(level)+"�šj";

  info=CLUB_D->query_member_info(temp_club_id1,getuid(user));

  rank=info["level"];
  if(temp_club_id1 == "dragon")
  {
    switch(rank)
    {
      case 6 : str+= temp_club_name1+"�s�Y�Ѥj  "; break;
      case 5 : str+= temp_club_name1+"�����D    "; break;
      case 4 : str+= temp_club_name1+"����      "; break;
      case 3 : str+= temp_club_name1+"�W���@�k  "; break;
      case 2 : str+= info["info1"]+"����D    "; break;
      default :  if(info["info1"]!="�L")
                 {
                   str+=info["info1"]+"���      "; break;
                 } 
                 else str+= temp_club_name1+"�@������  ";
    }
  }
  else
  {
    switch(rank)
    {
      case 5 : str+= temp_club_name1+"���D      "; break;
      case 4 : str+= temp_club_name1+"�����D    "; break;
      case 3 : str+= temp_club_name1+"�@�k      "; break;
      case 2 : str+= info["info1"]+ "����D    "; break;
      default :  if(info["info1"]!="�L")
                 {
                   str+=info["info1"]+"���      "; break;
                 } 
                 else str+= temp_club_name1+"�@������  ";
    }
  }
  return str;
}

