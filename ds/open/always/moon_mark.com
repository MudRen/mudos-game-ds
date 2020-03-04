// ���|�H��
// "level": ���a�b���|��������(1~?)
// 1: �@������ 
// 2: ��D 
// 3: �@�k 
// 4: ���� 
// 5: �����D (��1�W)
// 6: ���D (��1�W)
// "title": ���|�Y��
// "info1": �ƥΰ�1 (����W��)
// "info2": �ƥΰ�2
// "info3": �ƥΰ�3
// �j��� - /open/world1/acme/area/lea3
//�P�������R �i�H�b�o�өж���long �[�W�A�o�{�o�̪��ѪŦ��@�񥭱`�j����G?? :P
// �i����j�P����(Jawei)�R�ڪ� �Ʊڪ� ���� �X�D �ڤH
// �i����j�s��(Luky)�R���ѥH�W�άO�X�D�H�W
// �i����j�P����(Jawei)�R�F���ڧƱ�O���u���ڪ���ɭ�...
// �s�� ���� ��� �b��

#include <ansi.h>
#include <armor.h>
#define CLUB_NAME "���"
#define CLUB_ID "moon"
#define CLUB_CHANNEL "moon"
#define CLUB_MARK "ring of moon-soul"
#define CLUB_ENTER_FILE "/open/world1/acme/area/moon/room1"
#define CLUB_OUT_FILE "/open/world1/acme/area/lea3"
inherit FINGER;
private string *members_level = ({
	"�ګ�", //0
	"�ڤH", //1
	"�X�D", //2
	"����", //3
	"�Ʊڪ�", //4
	"�ڪ�", //5
});
void create()
{
	set_name(HIC"����"NOR,({"ring of moon-soul","ring","club_mark"}));
	set_weight(600);
	if( clonep() ) set_default_object(__FILE__);
	else
	{
		set("value",0);
		set("no_drop",1);
		set("no_sell",1);
		set("no_sac",1);
		set("unit","�u");
		set("long",@LONG
	
�۶Ǧb���ܮɥN�A���@�T��G���H���Y�J�F�Z���A�ɭP�F��ɦb
�Z���۷������s�ھD�췴���C�����ڪ��P����(Jawei) �b��~
���������򤧮ɡA�@�餣�g�N���o�{�F�H�����s�b�A��O�M�M��
�K���y�F�o�T���մ��������١A�ǥѥ��������O�q�i�H�Ϩ�
�a���H�Ө��ڪ��ھڦa--�s�H�c�C

[�����ڪ���L�����Х�<help moon>���O�d�ߡC]
LONG
		);
	}
	set("club_id",CLUB_ID);
	set("club",CLUB_NAME);
	set("sub_club",({"�s��X","����X","���X","�b��X"}));
	set("club_max_level",sizeof(members_level)-1);
	set("armor_prop/shield", 1);
	setup();
}

int query_autoload() { return 1; } //save_item

void init()
{
 mapping info;
 int level;
 if(environment(this_object())!=this_player()) return;
 level=CLUB_D->check_member(CLUB_ID,getuid(this_player()));
 if(level==0)
 {
 	if(wizardp(this_player()))
 	{
 		 info = ([
		 "level": wiz_level(this_player()),
		 "title": "��گS���U��  ",
		 "info1": "�L",
		 "info2": ctime(time()),
		 "info3": this_player()->name_id(1)
		 ]);
		 CLUB_D->add_member(CLUB_ID,getuid(this_player()),info);
	}
	else 
	{
 		tell_object(this_player(),this_object()->name()+"��M�q�A���W���X�A���������b����C\n");
 		this_player()->delete("club");
 		destruct(this_object());
 		return;
 	}
 }
 switch(level)
 {
  case 5:
		add_action("do_handover","handover");
		add_action("do_lockleave","lockleave");
		add_action("do_givepower","givepower");
		add_action("no_suicide","suicide"); //����۱�
		add_action("do_subleader","subleader");
		add_action("do_retire","retire");
  case 4:
  		add_action("do_listmember","listmember");
  case 3:
  		add_action("do_accept","accept");
		add_action("do_kickout","kickout");
  case 2:
		add_action("do_include","include");
		add_action("do_dismiss","dismiss");
  default:
   		add_action("do_help","help");
   		add_action("do_members","members");
   		add_action("do_leaveclub","leaveclub");
   		add_action("do_enter_club","lift");
 }
}

int do_enter_club(string arg)
{
	object env,me;
	if(arg!="ring") return 0;
	me=this_player();
	env=environment(me);
	if(!env) return 0;
	if(env->query("moon_club_enter"))
	{
		if(me->query_temp("killer")) return notify_fail("�ѤW�ǨӤ@�ӫիժ��n��: �A, �]���A�����F�H�ҥH�Ȯɤ���i�J���|�C\n");;
	if(me->query_temp("invader")) return notify_fail("�ѤW�ǨӤ@�ӫիժ��n��: �]���A���ˤF�H, �ҥH�Ȯɤ���i�J���|�C\n");
		message_vision("$N�N$n�|�V�Ť��A��M$N�Q�@�}���~�]��F�C\n",me,this_object());
		if(!me->can_move(CLUB_ENTER_FILE))
		{
			message_vision("���~���������F�A�u��$N�����ұ����b���b��a�C\n",me);
			return 1;
		}
		else
		{
			tell_room(env,me->name()+"��M�H�ۥ��~�����F�C\n",({ me }));
			me->move(CLUB_ENTER_FILE);
			tell_room(environment(me),me->name()+"��M�X�{�b�@�}���~�����C\n",({ me }));
			write("�b���~���h����A�A�o�{�ۤv�w�g�Ө�F�s�H�c�����f�C\n");
			me->add_busy(1);
			return 1;
		}
	}
	else if(env->query("moon_club_out"))
	{
		message_vision("$N�N$n�|�V�Ť��A��M$N�Q�@�}���~�]��F�C\n",me,this_object());
		if(!me->can_move(CLUB_OUT_FILE))
		{
			message_vision("���~���������F�A�u��$N�����ұ����b���b��a�C\n",me);
			return 1;
		}
		else
		{
			tell_room(env,me->name()+"��M�H�ۥ��~�����F�C\n",({ me }));
			me->move(CLUB_OUT_FILE);
			tell_room(environment(me),me->name()+"��M�X�{�b�@�}���~�����C\n",({ me }));
			write("�b���~���h����A�A�o�{�ۤv�S�^��F"+environment(me)->query("short")+"�C\n");
			me->add_busy(1);
			return 1;
		}
	}
	else return notify_fail("�A�N"+this_object()->name()+"�����|�_�A���O����Ʊ����S�o�͡C\n");
}


int filter_members(object ppl,string *list)
{
        if( !environment(ppl) ) return 0;
        if( member_array(getuid(ppl),list)!=-1 ) return 1;
        return 0;
}

string show_level(object user)
{
 int level,rank;
 mapping info;
 string str;
 if(wizardp(user)) return "�i�a�A�|���j��گS���U��    ";
 level=user->query("level");
 if(level>100) 	str = "�i????????�j";
 else if(level<11)	str = "�i�� "+chinese_number(level)+" �šj";
 else if(level<21) 	str = "�i��"+chinese_number(level)+"�šj";
 else if(level%10==0)   str = "�i��"+chinese_number(level)+"�šj";
 else str = "�i"+chinese_number(level)+"�šj";
 info=CLUB_D->query_member_info(CLUB_ID,getuid(user));
 rank=info["level"];
 switch(rank)
 {
 	case 5: str+="�뤧�@�ڤj�ڪ�  "; break;
 	case 4: str+="�뤧�@�ڰƱڪ�  "; break;
 	case 3: str+="�뤧�@�ڪ���    "; break;
  	case 2: str+=info["info1"]+"�X�D      "; break;
 	default: 
 		if(info["info1"]!="�L")
 		{
 			str+="���"+info["info1"]+"����  "; break;
 		} else str+="�뤧�@�ڱڤH    ";
 }
 return str;
}

int sort_member(object ob1, object ob2)
{
	int lv1,lv2;
	lv1=CLUB_D->check_member(CLUB_ID,getuid(ob1));
	lv2=CLUB_D->check_member(CLUB_ID,getuid(ob2));
	if(lv1 == lv2) return (int)ob1->query("level") - (int)ob2->query("level");
	else return (lv1 - lv2);
}

int do_members(string arg)
{
	object *users,me;
	string str,*list;
	int i,ppl_cnt,idle;
	me=this_player();
//	list=CLUB_D->club_members(CLUB_ID);
//	users = filter_array( users(), "filter_members", this_object() ,list);
	users = CLUB_D->find_online_members(CLUB_ID);
	str = "�� "+CLUB_NAME+": \n";
	str += "�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w\n";

	users = sort_array(users, "sort_member", this_object());

	ppl_cnt = 0;
	i = sizeof(users);
	while( i-- )
	{
			// Skip those users in login limbo.
			if(!me->visible(users[i]) && wizardp(users[i])) continue;
			str = sprintf("%s%12s%-16s %s(%s)",
				str,
				show_level(users[i]),
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
	return 1;
}

int do_include(string arg)
{
	string sub;
	object ob,me;
	mapping me_info,ob_info;
	me=this_player();
	
        if(!arg) return notify_fail("include <�H�W>\n");
        else
        {
                ob = present(arg, environment(me));
	        if(!ob) return notify_fail("�o�̦��o�ӤH�ܡS\n");
		if(!userp(ob) || ob==me ) return notify_fail("�o�̦��o�ӤH�ܡS\n");
		me_info=CLUB_D->query_member_info(CLUB_ID,getuid(me));
		ob_info=CLUB_D->query_member_info(CLUB_ID,getuid(ob));
		if(sizeof(ob_info))
		{
			if(me_info["level"] != 2 ) return notify_fail("�u���X�D��N�ڤH���J���X�C\n");
			if(!stringp(sub=me_info["info1"])) return notify_fail("�u���X�D��N�ڤH���J���X�C\n");
			if(ob_info["level"] != 1 || ob_info["info1"]!="�L")
				return notify_fail("�u���@��ڤH�i�H���J�A������C\n");
			ob_info["info1"]=sub;
			CLUB_D->set_member(CLUB_ID,getuid(ob),ob_info);
		 	message_vision("$N�N$n���J"+sub+", �é��$n���ӻH��: ����N�ݧA����{�F�C\n",me,ob);
		 	ob->save();
		 	return 1;
		}
		 else return notify_fail("���èS���[�J"+CLUB_NAME+"�C\n");
	}
	return 1;
}

int do_dismiss(string arg)
{
	string sub;
	object ob,me;
	mapping me_info,ob_info;
	me=this_player();
	
        if(!arg) return notify_fail("dismiss <�H�W>\n");
        else
        {
                ob = present(arg, environment(me));
	        if(!ob) return notify_fail("�o�̦��o�ӤH�ܡS\n");
		if(!userp(ob) || ob==me ) return notify_fail("�o�̦��o�ӤH�ܡS\n");
		me_info=CLUB_D->query_member_info(CLUB_ID,getuid(me));
		ob_info=CLUB_D->query_member_info(CLUB_ID,getuid(ob));		
		if(sizeof(ob_info))
		{
			if(!sub=me_info["info1"] || me_info["level"]!=2 ) return notify_fail("�u���X�D��K���X�U����¾�ȡC\n");
			if(ob_info["level"] != 1 ) return notify_fail("���ä��ݩ�A���X�U�C\n");
			if(ob_info["info1"] != sub) return notify_fail("���ä��ݩ�A���X�U�C\n");
			ob_info["info1"]="�L";
			CLUB_D->set_member(CLUB_ID,getuid(ob),ob_info);
		 	message_vision("$N�Ѱ��F$n�b"+sub+"��¾��, �n�n�Y��: �S�֤F�@�ӤH�~...�u�O�i���ڡC\n",me,ob);
		 	ob->save();
		 	return 1;
		}
		 else return notify_fail("���èS���[�J"+CLUB_NAME+"�C\n");
	}
	return 1;
}
//���H
int do_accept(string arg)
{
	string *clubs;
	object ob,mark,me;
	mapping info;
	me=this_player();
        if(!arg) return notify_fail("�A�n���֥[�J"+CLUB_NAME+"�S\n");
        else
        {
                ob = present(arg, environment(me));
	        if (!ob) return notify_fail("�o�̦��o�ӤH�ܡS\n");
	        if(!userp(ob) || ob==me ) return notify_fail("�o�̦��o�ӤH�ܡS\n");
		if(ob->query_temp("joinclub") != me->query("id") )
		{
			return notify_fail("���èS���V�A�ӽФJ��(joinclub).\n");
		}
		clubs=CLUB_D->find_player_club(getuid(ob));
		if(sizeof(clubs)>0)
		{
			if(clubs[0]==CLUB_ID) return notify_fail("���w�g�O"+CLUB_NAME+"���@���l�F�C\n");
			else return notify_fail("���w�g�[�J�F�O�������C\n");
		}
		 else
		{
		 mark=new(base_name(this_object()));
		 if(!mark) return notify_fail("���|�H�����o���ѡC\n");
		 if( !mark->can_move(ob) ) return notify_fail(ob->name(1)+"������"+mark->query("name")+"�C\n");
		 message_vision("$N���F$n�@"+mark->query("unit")+mark->query("name")+", �ö������ﱵ$n����"+CLUB_NAME+"���@���l�C\n",me,ob);
		 info = ([
		 "level": 1,
		 "title": "�g�s���@������",
		 "info1": "�L",
		 "info2": ctime(time()),
		 "info3": me->name_id(1)
		 ]);
		 CLUB_D->add_member(CLUB_ID,getuid(ob),info);
		 mark->move(ob);
		 ob->add("channels", ({"moon"}));
		 ob->save();
		}
	}
	return 1;
}

int do_kickout(string arg)
{
	string *tuned_ch;
	object ob,mark,me;
	mapping me_info,ob_info;
	me=this_player();
	
        if(!arg) return notify_fail("�A�n�N�ֽ�X"+CLUB_NAME+"�S\n");
        else
        {
               ob = present(arg, environment(me));
	        if (!ob)
	        {
	        	if(!CLUB_D->is_club_leader(me))	return notify_fail("�o�̦��o�ӤH�ܡS\n");
	        	else {
	        		write("[���u�}��]:");
	        		if(ob=find_player(arg)) return notify_fail("����٦b�u�W�C\n");
	        		if( CLUB_D->remove_member(CLUB_ID,arg) )
	        		{
	        			write("���\\�}���F"+arg+"�C\n");
	        			return 1;
	        		}
	        		else return 0;
	        	}
	        }
	        if(!userp(ob) || ob==me ) return notify_fail("�o�̦��o�ӤH�ܡS\n");
		
		me_info=CLUB_D->query_member_info(CLUB_ID,getuid(me));
		ob_info=CLUB_D->query_member_info(CLUB_ID,getuid(ob));	
		
		if(sizeof(ob_info))
		{
			if(ob_info["level"] >= me_info["level"])
				return notify_fail("�A�������N����X"+CLUB_NAME+"�C\n");
			if( wiz_level(ob) > wiz_level(me) && wizardp(ob))
				return notify_fail("�A�������N����X"+CLUB_NAME+"�C\n");
 			tuned_ch = ob->query("channels");
 			if( pointerp(tuned_ch) && member_array(CLUB_CHANNEL, tuned_ch)!=-1 )
 			{
 				tuned_ch -= ({ CLUB_CHANNEL });
				ob->set("channels", tuned_ch);
 			}
			//ob->delete("club");
			if(!mark=present(CLUB_MARK,ob))
			{
				write("���|�H�����o���ѡC\n");
			}
			else
			{
 				message_vision("$N�S���F$n��"+mark->query("name")+", �ñj��$n�h�X"+CLUB_NAME+"�C\n",me,ob);
 				destruct(mark);
 			}
 			CLUB_D->remove_member(CLUB_ID,getuid(ob));
 			ob->save();
 			return 1;
		}
		 else return notify_fail("���èS���[�J"+CLUB_NAME+"�C\n");
	}
	return 1;
}

int do_subleader(string arg)
{
	string id,sub;
	object ob,me,mark;
	mapping me_info,ob_info;
	me=this_player();
	
        if(!arg) return notify_fail("subleader <�H�W> to <���X�W>\n");
        else
        {
        	if( sscanf(arg, "%s to %s", id, sub)!=2 ) return notify_fail("subleader <�H�W> to <���X�W>\n");
                ob = present(id, environment(me));
	        if(!ob) return notify_fail("�o�̦��o�ӤH�ܡS\n");
		if(!userp(ob) || ob==me ) return notify_fail("�o�̦��o�ӤH�ܡS\n");

		me_info=CLUB_D->query_member_info(CLUB_ID,getuid(me));
		ob_info=CLUB_D->query_member_info(CLUB_ID,getuid(ob));	
		
		if(sizeof(ob_info))
		{
			if(ob_info["level"] != 1)
				return notify_fail("�u���@��ڤH�i�H�����X�D�C\n");
			if( (int) member_array(sub, query("sub_club"))<0 )
				return notify_fail("�ثe�i�Ϊ����X���i�s��X�j�B�i����X�j�B�i���X�j�B�i�b��X�j�C\n");
			ob_info["level"]=2;
			ob_info["info1"]=sub;
			CLUB_D->set_member(CLUB_ID,getuid(ob),ob_info);
			if(!mark=present(CLUB_MARK,ob))
			{
				write("���|�H�����o���ѡC\n");
			}
			else
			{
	 			message_vision("$N�N$n���@��"+sub+"�X�D, �éM$n����j�y�@�f�C\n",me,ob);
	 			mark->move(ob);
	 		}
	 		ob->save();
	 		return 1;
		}
		 else return notify_fail("���èS���[�J"+CLUB_NAME+"�C\n");
	}
	return 1;
}

int do_retire(string arg)
{
	string sub;
	object ob,me,mark;
	mapping me_info,ob_info;
	me=this_player();
	
        if(!arg) return notify_fail("retire <�H�W> \n");
        else
        {
                ob = present(arg, environment(me));
	        if(!ob) return notify_fail("�o�̦��o�ӤH�ܡS\n");
		if(!userp(ob) || ob==me) return notify_fail("�o�̦��o�ӤH�ܡS\n");

		me_info=CLUB_D->query_member_info(CLUB_ID,getuid(me));
		ob_info=CLUB_D->query_member_info(CLUB_ID,getuid(ob));

		if(sizeof(ob_info))
		{
			if(ob_info["level"] != 2) return notify_fail("��H�ä��O�X�D�C\n");
			sub=ob_info["info1"];

			ob_info["level"]=1;
			ob_info["info1"]="�L";
			CLUB_D->set_member(CLUB_ID,getuid(ob),ob_info);

			if(!mark=present(CLUB_MARK,ob))
			{
				write("���|�H�����o���ѡC\n");
			}
			else
			{
	 			message_vision("$N�K���F$n��"+sub+"�X�D¾�ȡC\n",me,ob);
	 			mark->move(ob);
	 		}
	 		ob->save();
	 		return 1;
		}
		 else return notify_fail("���èS���[�J"+CLUB_NAME+"�C\n");
	}
	return 1;
}

int do_givepower(string arg)
{
	string id,type,res;
	int level;
	object ob,me,mark;
	mapping me_info,ob_info;
	me=this_player();
	
        if(!arg) return notify_fail("givepower <�H�W> to <����>\n");
        else
        {
        	if( sscanf(arg, "%s to %d", id, level)!=2 ) return notify_fail("givepower <�H�W> to <����>\n");
                ob = present(id, environment(me));
	        if(!ob) return notify_fail("�o�̦��o�ӤH�ܡS\n");
		if(!userp(ob) || ob==me) return notify_fail("�o�̦��o�ӤH�ܡS\n");
		
		me_info=CLUB_D->query_member_info(CLUB_ID,getuid(me));
		ob_info=CLUB_D->query_member_info(CLUB_ID,getuid(ob));
		
		if(sizeof(ob_info))
		{
			if(ob_info["level"] >= me_info["level"]) return notify_fail("�A�S�������ܹ�誺¾�ȵ��šC\n");
			if( wiz_level(ob) > wiz_level(me) && wizardp(ob))
					return notify_fail("�A�S�������ܹ�誺¾�ȵ��šC\n");
			if(level >= me_info["level"])
				return notify_fail("�A�S����洣�@��誺¾�ȵ��Ũ�o�ӵ��šC\n");
			if(level == ob_info["level"])
				return notify_fail("���w�g�O"+(string)members_level[level]+"�F�C\n");
			if(level > 5 || level < 1 )
				return notify_fail("�ثe���Ť��� <1:�ڤH> <2:�X�D> <3:����> <4:�Ʊڪ�> <5:�ڪ�> \n");
			if( level > ob_info["level"] )
			{
				type="���@";
				res ="�éM$n����j�y�@�f";
			}
			else
			{
				type = "��";
				res ="�é��$n���ӻH���j$n��N�\\��o";
			}
			switch(level)
			{
				case 1:
					ob_info["level"]=1;
					ob_info["info1"]="�L";
		 			ob_info["info2"]=ctime(time());
		 			ob_info["info3"]=me->name_id(1);
					break;
				case 2:
					return notify_fail("�Х�subleader���O�ӫ��w�@�Ӥ��X�C\n");
					break;
				case 3:
					ob_info["level"]=3;
					ob_info["info1"]="�L";
		 			ob_info["info2"]=ctime(time());
		 			ob_info["info3"]=me->name_id(1);
					break;
				case 4:
					ob_info["level"]=4;
					ob_info["info1"]="�L";
		 			ob_info["info2"]=ctime(time());
		 			ob_info["info3"]=me->name_id(1);
					break;
				case 5:
					return notify_fail("�Х�handover���O�������v����C\n");
					break;
				default: return notify_fail("�Ѽƿ��~�C\n");
				
			}
			CLUB_D->set_member(CLUB_ID,getuid(ob),ob_info);
			if(!mark=present(CLUB_MARK,ob))
			{
				write("���|�H�����o���ѡC\n");
			}
			else
			{
				message_vision("$N�N$n��¾�쵥��"+type+"��"+(string)members_level[level]+"(����"+(string)level+"), "+res+"�C\n",me,ob);
				mark->move(ob);
			}
			ob->save();
			return 1;
		}
		 else return notify_fail("���èS���[�J"+CLUB_NAME+"�C\n");
	}
	return 1;
}

int do_handover(string arg)
{
	object ob,mark,me;
	mapping me_info,ob_info;
	me=this_player();
        if(!arg) return notify_fail("�A�n�N�j�v���浹�֡S\n");
        else
        {
                ob = present(arg, environment(me));
	        if (!ob) return notify_fail("�o�̦��o�ӤH�ܡS\n");
		if(!userp(ob) || ob==me) return notify_fail("�o�̦��o�ӤH�ܡS\n");
		
		if(CLUB_D->query_club_leader(CLUB_ID)!=getuid(me)) return notify_fail("�A���O�u�������|��ɤH�C\n");
		
		me_info=CLUB_D->query_member_info(CLUB_ID,getuid(me));
		ob_info=CLUB_D->query_member_info(CLUB_ID,getuid(ob));
		if(sizeof(ob_info))
		{
		 	CLUB_D->set_club_leader(CLUB_ID,getuid(ob));
		 	
		 	ob_info["level"]=5;
		 	ob_info["info1"]="�L";
		 	ob_info["info2"]=ctime(time());
		 	ob_info["info3"]=me->name_id(1);
		 	CLUB_D->set_member(CLUB_ID,getuid(ob),ob_info);
			
			me_info["level"]=3;
		 	me_info["info1"]="�L";
		 	me_info["info2"]=ctime(time());
		 	me_info["info3"]=me->name_id(1);
			CLUB_D->set_member(CLUB_ID,getuid(me),me_info);
		 	
		 	mark=present(CLUB_MARK, me);
		 	if(!mark)
		 	{
		 		write("���|�H�����o���ѡC\n");
			}
			else
			{
				mark->move(me);
			}
			mark=present(CLUB_MARK, ob);
		 	if(!mark)
		 	{
		 		write("���|�H�����o���ѡC\n");
			}
			else
			{
				mark->move(ob);
			}
			message_vision("$N�N"+CLUB_NAME+"���`�����v���浹$n�C\n",me,ob);
			message( "channel:moon",CYN"�i"+CLUB_NAME+"�j"+me->name(1)+"("+capitalize(me->query("id"))+")�N"+CLUB_NAME+"�����v���浹"+ob->name(1)+"("+capitalize(ob->query("id"))+")�C\n"NOR, users() );
			ob->save();
			me->save();
			return 1;
		}
		 else return notify_fail("���ä��O"+CLUB_NAME+"���@���l�C\n");
	}
	return 1;
}

int do_leaveclub(string arg)
{
	string *tuned_ch;
	object mark,me;
	me=this_player();
	
	if(CLUB_D->query_club_leader(CLUB_ID)==getuid(me))
		return notify_fail("�A�������N�j�v�ಾ�~�����}"+CLUB_NAME+"�C\n");
	CLUB_D->remove_member(CLUB_ID,getuid(me));
	message_vision("$N�D�ʰh�X�F"+CLUB_NAME+"�C\n",me);
	message( "channel:moon",CYN"�i"+CLUB_NAME+"�j"+me->name(1)+"("+capitalize(me->query("id"))+")�D�ʰh�X�F"+CLUB_NAME+"�C\n"NOR, users() );
	tuned_ch = me->query("channels");
	if( pointerp(tuned_ch) && member_array(CLUB_CHANNEL, tuned_ch)!=-1 )
	{
			tuned_ch -= ({ CLUB_CHANNEL });
			me->set("channels", tuned_ch);
	}
	me->delete("club");
	if(!mark=present(CLUB_MARK,me))
	{
		write("���|�H�����o���ѡC\n");
	} else destruct(mark);
	me->save();
	return 1;
}
int do_lockleave(string arg)
{
	if(CLUB_D->query_club_leader(CLUB_ID)!=getuid(this_player())) return notify_fail("�A���O�u�������|��ɤH�C\n");
	if(arg=="on")
	{
		if(CLUB_D->query_lockleave(CLUB_ID)==1) return notify_fail("�h������w�g�}�ҡC\n");
		CLUB_D->set_lockleave(CLUB_ID,1);
		write("�A�N"+CLUB_NAME+"�]�w�����i�h���C\n");
		return 1;
	}
	if(arg=="off")
	{
		if(CLUB_D->query_lockleave(CLUB_ID)==0) return notify_fail("�h������w�g�����C\n");
		CLUB_D->set_lockleave(CLUB_ID,0);
		write("�A�N"+CLUB_NAME+"�]�w���i�H�h���C\n");
		return 1;
	}
	return notify_fail("lockleave <on/off> \n");
}
int no_suicide(string arg)
{
	if(CLUB_D->query_club_leader(CLUB_ID)==getuid(this_player()))
	{
		write("����"+CLUB_NAME+"���Ū��x, ��X�����v���e���i����, �H�K���~�L�H�C\n");
		return 1;
	}
	return 0;
}

int do_listmember(string arg)
{
	string *list,*members,temp,output;
	int i,j;
	mapping club;
	list=CLUB_D->club_members(CLUB_ID);
	club=CLUB_D->query_club_record(CLUB_ID);
	members=keys(club);
	output="\n�ثe"+CLUB_NAME+"�n�O���ת�������:\n";
	if(arg=="long")
	{
		for(i=this_object()->query("club_max_level");i>0;i--)
		{
			for(j=0;j<sizeof(members);j++)
			{
				if(club[members[j]]["level"]==i) output=sprintf("%s %12s ���|����: %d\n",output,members[j],i);
			}
		}
		output=sprintf("%s \n�ثe%s�@�p��: %d �W�����C\n",output,CLUB_NAME,sizeof(members));
		write(output);
		return 1;
	}
	temp=CLUB_D->query_club_leader(CLUB_ID);
	output=sprintf("%s ��ɤH: %12s\n",output,temp);
	list-=({temp});
	output=sprintf("%s ��L:\n",output,temp);
	output+=CLUB_D->show_club_members(CLUB_ID);
	output=sprintf("%s�ثe%s�@�p��: %d �W�����C\n",output,CLUB_NAME,sizeof(members));
	write(output);
	return 1;
}

int do_help(string arg)
{
 if(arg=="moon")
 {
  write(@HELP

       ��������������������������������������������������������������������
       �x                      ���|�H�������U����                        �x
       �u�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�s�w�w�w�w�w�w�w�w�w�s�w�w�w�w�w�w�t
       �x  ���O�榡                    �x����              �x�v��        �x
       �u�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�q�w�w�w�w�w�w�w�w�w�q�w�w�w�w�w�w�t
       �x  help moon                   �x�����U�T��        �x�ڤH        �x
       �x  moon <�A���T��>             �x���|�M���W�D      �x�ڤH        �x
       �x  members                     �x�C�X�u�W���|����  �x�ڤH        �x
       �x  leaveclub                   �x�D�ʰh�X���|      �x�ڤH        �x
       �x  include <�H�W>              �x�N�Y�H���J���X    �x�X�D�M��    �x
       �x  dismiss <�H�W>              �x�����Y�H���X¾��  �x�X�D�M��    �x
       �x  accept <�H�W>               �x���Y�H�[�J���|    �x���ѥH�W    �x
       �x  kickout <�H�W>              �x�N�Y�H�v�X���|    �x���ѥH�W    �x
       �x  lockleave <on> <off>        �x����ۦ�h��      �x�ڪ�        �x
       �x  subleader <�H�W> to <����W>�x�ɯŬY�H���X�D    �x�ڪ�        �x
       �x  retire <�H�W>               �x�M���Y�H�X�D¾��  �x�ڪ�        �x
       �x  givepower <�H�W> to <����>  �x���ܬY�H��¾��    �x�ڪ�        �x
       �x  handover <�H�W>             �x�x��¾�ȥ汵      �x�ڪ�        �x
       �x  listmember                  �x���|�W�U          �x���ѥH�W    �x
       �|�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�r�w�w�w�w�w�w�w�w�w�r�w�w�w�w�w�w�}
	 �� �ϥ� accept ���O���������� joinclub ���O�ӽФ~��ͮġC
         �� ��ڥثe���|�Ӥ��X:�i�s��X�j�B�i����X�j�B�i���X�j�B�i�b��X�j�C
         �� ���Ť���: <1:�ڤH> <2:�X�D> <3:����> <4:�Ʊڪ�> <5:�ڪ�> �C
         �� ��L��ڪ��ư�: <help moon_rule> , <help moon_group> �C
     	
HELP
  );
  return 1;
  }
  if(arg=="moon_rule")
  {
   this_player()->start_more(@RULE
 ����ڤT�j�٫�                           

�@�B  �Y��T�����

      ���ڱڤH�Ҿ֦���CHAR���y�����j��������[�J���ڡA���O�Y��T
      �CHAR�[�J��L�����C
      �P�ɤ]�T��N��ڪ�CHAR�ɵ��L�H�ϥΡC�n��CHAR�e���L�H�ɡA����
      POST�bMOON BOARD���i���A�Ѫ��ѥH�W�v�X���ڤ���l�i�e���L�H�C
      �Y���ت̬����ڱڤH�A�h�u��POST���i���Y�i�C
      �t�~�T����N������ڡA�n�����ɥ���POST�bMOON BOARD�g�F���|ĳ
      �q�L��\�A�l�i���ڡC
      �H�ϤW�z�W�w�̡A�N�v�X�ڡA�õ����p�M�w�O�_�[�H�q�r�C

�G�B  �Y��T��D��PK��L���a
 
      ���ڱڤH�T��PK��L���a�A���D���ڳq�r�̥H��PK�ڱڤH���{��Ǥ�
      �b�T��C�C
      �ҿ�PK�ڱڤ��{��Ǭ��ڱڤH�D��PK�ɡA�u�W���F�����ҤH�A�N���p
      POST�bMOON BOARD�APOST���e�����]�APKER ID�B�QPK�� ID�A�h�Y��
      �NPKER�C�J�q�r�W��A�ڱڤH�ҥi�����C�Y�QPK�ɡA�L�F���i�����@
      �ҡA�h�ѳQPK�̦ۦ�POST�L�{�A�ƫ�g���ѥH�W�d�ҡA��NPKER�C�J
      �q�r�W��C

      ���D��PK�H�~�A���ڱڤH�P�L�H����L�ȯɡA����POST�bCHAT BOARD
      �ѷF���|ĳ�M�w�B�z��k�A���i�ۦ�PK���C
      �H�ϤW�z�W�w�̡A�N�v�X���ڡA�õ����p�M�w�O�_�[�H�q�r�C 
      
�T�B  �T��s�楻�ڸ˳�

      ��m�����|�����˳Ƭ����ڤH�Ҧ@���A���o�p�ۥ[�H�ܽ�C�ڤH�i���N
      �[�H���ΡA�����������u�e��^���C
      ���bWIZ�ŧGREBOOT TIME����A�h���T���ܽ�˳ơC
      �p���ܽ�˳ƪ̡A�N�v�X���ڨä��H�q�r�C      
      ��m�˳ƮɡA�����̷����O���T��m�C�Y�����Ʊ��ݰ��W���u�A�h��
      ���U�@�ڤH�N����z�C�H�ϥ����W�w�̡A�N�@��z�˳Ƥ@�ӬP���A�֥�
      ���U��ť�̫h�ѷF���|ĳ�t��M�w�B���C


      �H�W���ڤ�ڤ��T�j�٫ߡA����ڱڤH�Y���u�C


  ���J�ڤ�ڤ��H�A�ݦV��ڪ��ѥH�W���X�ӽСC
  ���������ѥH�W�@�W�A�X�D��W�P�N�Ϊ��ѥH�W��W�P�N�C
  �ûݴM�o�ڱڤH�@�W����O�ҤH�A�l�o�H�J����ڡC
  �J���ڤ@�Ӥ뤺�Y���ǿ��A�h�O�ҤH�s�a�D���B���C
  �P�@�ڤH�b�P�@�ɶ����u�i���@�H����O�ҤH�C
  �Q�O�ҤH�b�@�Ӥ뤺���o���L�H���O�ҤH�A�ä��o�ӽХ[�J��LID�C

  �[�J����ݦ�MOON BOARD POST�@�g�[�J�n���]�A�G
  �[�J��ID
  �P�N���F��ID
  ���A�J�ڪ̤��F��ID
  �O�ҤHID
  �Φۧڤ���

  �ûݾ\Ū�ڤ�����POST�A���x���ڳW�w�C


                              	��ڱڪ� �P����(jawei)(Fri Oct 15)
   
RULE
);
return 1;
  }
  if(arg=="moon_group")
  {
  this_player()->start_more(@MOON_PART

����ڥ|�X�����u                         
 
�@�B  �s��X�G
      �D�n�t�d�ڤ����ưȡC�]�A��z�ڤH�W��B��ڤH�ǿ��B�����ʷ�����B
      �оɷs�H�����C

�G�B  ���X�G
      �D�n�t�d��~���ƪ��C�]�A��z�q�r�W��B����q�r���ȡB���ڤH�ѨM��
      �~�ȯɵ����C

�T�B  ����X�G
      �D�n�t�d��ƪ������C�]�A��s���ȸѪk�Bø�s�a�ϡB��z�ڤ����n����
      �i�B��s�U���|�S�ʻP�m�\��k�����C 

�|�B  �b��X
      �D�n�t�d�ڤ����˳ơC�]�A�����U�ظ˳ơB��s�˳ƪ��S�ʻP����B��s
      MOB ���S�ʡB��z�ڤ��˳Ƶ����C


  ���ڪ��Ҧ��ڤH�A���F���H�~�����q�H�W�|�X��ܤ@�X�[�J�C
  �бڤH�V���Ҽ{����A�[�J�A�]���N�өҦ��J�ڤ�ID�����[�J�P�@�ӺX�C
  �]�N�O�P�@�ӤH���Ҧ�CHAR�����[�J�P�@�X�A�o�O���F���u���ت��C
  �p�G��ӷQ���X�A�����x�o��X�D�P�Q�[�J�����X�X�D���P�N�A
  �åB�n�@����Ҧ�CHAR�����X�~��C
  �X�D�b���H�J�X��A�����bMOON BOARD���i�A�æۦ��z�U�X�W��A
  �w����W�浹�s��X���ξ�C
  �t�~�A�N�ӤU�@�����U�X�D�A�N�W�w�ѦU�X�������O�D��C


                                                           ��ڱڪ�  �P����

MOON_PART
);
  return 1;	
 }
 return 0;
}
