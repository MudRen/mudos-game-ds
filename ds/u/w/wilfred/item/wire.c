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

void create()
{
  set_name(CYN"�ƽu"NOR, ({"wire"}));
  set("long",HIC"�@�����q���ƽu�A�q�`�O�ΨӶǿ�w�Ъ���ơA�@�륫���W������C\n"NOR""WHT"���i�Ϋ��O��"HIW"Where  members  invis"NOR);
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
  add_action("do_where","where");
  add_action("do_amembers","members");
  add_action("do_invis","invis");
  do_invis();
}

int do_invis()
{
  object me = this_player();
  if(!me->query_temp("invis"))
  {
    write(WHT"�A�����F�A���p���ϯ��ƴ�.....\n");
    me->set_temp("invis",(int)SECURITY_D->get_wiz_level(me));
    return 1;
  }
  if(me->query_temp("invis"))
  {
    write(HIC"�A�����κ����B�{�X��....\n"NOR);
    me->delete_temp("invis");
    return 1;
  }
}       

int do_where()
{
  int i, j = 0, user_amount, idle, dead_ppl=0;
  object *user_list, user_location;
  string status1, status2, status3, status4;
  string temp_lv, msg = "";

  user_list = children("/obj/user");
  user_list = sort_array(user_list, "sort_user", this_object());

  user_amount = sizeof(user_list) - 1;

  for(i=0;i<user_amount;i++)
  {
    j++;
    if(user_list[i]->query_temp("netdead") == 1)
    {
      user_location = find_object("/obj/void.c");
      idle = 0;
      status4 = HIG"(�_�u��)"NOR;
      dead_ppl++;
    }
    if(!user_list[i]->query_temp("netdead"))
    {
      user_location = environment(user_list[i]);
      if(userp(user_list[i]))
        idle = query_idle(user_list[i]);
      else
        idle = 0;
      status4 = "";
    }

    if(wizardp(user_list[i])) temp_lv = HIW+SECURITY_D->get_status(user_list[i])+NOR;
      else temp_lv = SECURITY_D->get_status(user_list[i]);

    if (in_input(user_list[i]))  status1 = NOR""WHT"(��J��r��)"NOR;
      else  status1="";
    if ((in_edit(user_list[i]))) status2 = NOR""YEL"(�s���ɮפ�)"NOR;
      else status2="";
    if (idle>60)                 status3 = sprintf(NOR""CYN"(�o�b�F %d ����)"NOR,idle/60);
      else status3="";

    msg += sprintf("%2d %12s %s(%s) ��� %s(%s)\n",
    j,
    temp_lv,
    user_list[i]->query("name"),
    user_list[i]->query("id"),
//    (string)user_location->query("short"),
//    (string)file_name(user_location) );
    " ",
    " " );

    if ((status1!="")||(status2!="")||(status3!="")||(status4!=""))
      msg += sprintf("       ���A  : %s%s%s%s\n",status1,status2,status3,status4);

    msg += sprintf("       �q %s �s�u���C\n",query_ips(user_list,user_list[i]));
  }
  msg += sprintf("�ثe�u�W�@�� "HIC"%d"NOR" �W�ϥΪ̡A�䤤�� "HIR"%d"NOR" �W�_�u���C\n",user_amount,dead_ppl);
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

