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
#define CLUB_NAME "�Ѧa�|"
#define CLUB_ID "sky"
#define CLUB_CHANNEL "sky"
#define CLUB_MARK "ring of heaven and earth"

inherit FINGER;
private string *members_level = ({
	"�ګ�", //0
	"����", //1
	"���", //2
	"�@�k", //3
	"��D", //4
	"�`��D", //5
});
void create()
{
	set_name(HIG"�Ѧa����"NOR,({"ring of heaven and earth","ring","club_mark"}));
	set_weight(600);
	if( clonep() ) set_default_object(__FILE__);
	else
	{
		set("material","steel");
		set("club_id",CLUB_ID);
		set("club",CLUB_NAME);
		set("sub_club",({"���\\��","�a�b��"}));
		set("value",0);
		set("no_drop",1);
		set("no_sell",1);
		set("no_sac",1);
		set("unit","�u");
		set("long",@LONG
	
�������D�O�ѤU�W�K���ѤU�|�����A�H�ѤU�|�������_
(�Ѧa����)���~�βհ������A�����z�g�X�Ѻ�⪺���A
�A�O�A�ٹĸӦW�K�Ҫ᪺�ߦ�C

[����Ѧa�|����L�����Х�<help sky>���O�d�ߡC]
LONG
		);
	}
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
		 "title": "�Ѧa�|�S���U��  ",
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
		add_action("do_givepower","givepower");
		add_action("no_suicide","suicide"); //����۱�
		add_action("do_subleader","subleader");
		add_action("do_retire","retire");
  case 4:
  		add_action("do_listmember","listmember");
  		add_action("do_accept","accept");
		add_action("do_kickout","kickout");
  case 3:
		add_action("do_include","include");
		add_action("do_dismiss","dismiss");
  case 2:
  default:
   		add_action("do_help","help");
   		add_action("do_members","members");
   		add_action("do_leaveclub","leaveclub");
 }
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
 if(wizardp(user)) return "�i�a�A�|���j�Ѧa�|�S���U��  ";
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
 	case 5: str+="�Ѧa�|�`��D    "; break;
 	case 4: str+="�Ѧa�|��D      "; break;
 	case 3: str+=info["info1"]+"�@�k      "; break;
  	case 2: str+=info["info1"]+"���      "; break;
 	default: str+="�Ѧa�|�@������  "; break;
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
			if(me_info["level"] != 3 ) return notify_fail("�u���@�k��N�������J����C\n");
			if(!stringp(sub=me_info["info1"])) return notify_fail("�u���@�k��N�������J����C\n");
			if(ob_info["level"] != 1) return notify_fail("�u���@��ڤH�i�H���J�A������C\n");
			ob_info["level"]=2;
			ob_info["info1"]=sub;
			CLUB_D->set_member(CLUB_ID,getuid(ob),ob_info);
		 	message_vision("$N�N$n���J"+sub+", �é��$n���ӻH��: ����N�ݧA�����{�F�C\n",me,ob);
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
			if(!sub=me_info["info1"] || me_info["level"]!=3 ) return notify_fail("�u���@�k��K�����󦨭�¾�ȡC\n");
			if(ob_info["level"] != 2 ) return notify_fail("���ä��ݩ�A������C\n");
			if(ob_info["info1"] != sub) return notify_fail("���ä��ݩ�A������C\n");
			ob_info["level"]=1;
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
		 "title": "�Ѧa�|�@������",
		 "info1": "�L",
		 "info2": ctime(time()),
		 "info3": me->name_id(1)
		 ]);
		 CLUB_D->add_member(CLUB_ID,getuid(ob),info);
		 mark->move(ob);
		 ob->add("channels", ({"sky"}));
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
	        if (!ob) return notify_fail("�o�̦��o�ӤH�ܡS\n");
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
	
        if(!arg) return notify_fail("subleader <�H�W> to <����W>\n");
        else
        {
        	if( sscanf(arg, "%s to %s", id, sub)!=2 ) return notify_fail("subleader <�H�W> to <����W>\n");
                ob = present(id, environment(me));
	        if(!ob) return notify_fail("�o�̦��o�ӤH�ܡS\n");
		if(!userp(ob) || ob==me ) return notify_fail("�o�̦��o�ӤH�ܡS\n");

		me_info=CLUB_D->query_member_info(CLUB_ID,getuid(me));
		ob_info=CLUB_D->query_member_info(CLUB_ID,getuid(ob));
		
		if(sizeof(ob_info))
		{
			if(ob_info["level"] > 2) return notify_fail("�u���@�������άO����i�H�����@�k�C\n");
			if( (int) member_array(sub, query("sub_club"))<0 ) return notify_fail("�ثe�i�Ϊ����󬰡i���\\��j�B�i�a�b��j�C\n");
			ob_info["level"]=3;
			ob_info["info1"]=sub;
			CLUB_D->set_member(CLUB_ID,getuid(ob),ob_info);
			if(!mark=present(CLUB_MARK,ob))
			{
				write("���|�H�����o���ѡC\n");
			}
			else
			{
	 			message_vision("$N�N$n���@��"+sub+"�@�k, �éM$n����j�y�@�f�C\n",me,ob);
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
			if(ob_info["level"] != 3) return notify_fail("��H�ä��O�@�k�C\n");
			
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
	 			message_vision("$N�K���F$n��"+sub+"�@�k¾�ȡC\n",me,ob);
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
				return notify_fail("�ثe���Ť��� <1:����> <2:���> <3:�@�k> <4:��D> <5:�`��D> \n");
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
					return notify_fail("���ʧ@�O�d���@�k�M�Ϋ��Oinclude�ϥΤ~����w����C\n");
					break;
				case 3:
					return notify_fail("�Х�subleader���O�ӫ��w�@�Ӥ���C\n");
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
			
			me_info["level"]=4;
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
			message( "channel:sky",CYN"�i"+CLUB_NAME+"�j"+me->name(1)+"("+capitalize(me->query("id"))+")�N"+CLUB_NAME+"�����v���浹"+ob->name(1)+"("+capitalize(ob->query("id"))+")�C\n"NOR, users() );
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
	message( "channel:sky",CYN"�i"+CLUB_NAME+"�j"+me->name(1)+"("+capitalize(me->query("id"))+")�D�ʰh�X�F"+CLUB_NAME+"�C\n"NOR, users() );
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
	output+="\n [��listmember long �i�H�ݨ�󧹾㪺��ơC]\n";
	write(output);
	return 1;
}

int do_help(string arg)
{
 if(arg=="sky")
 {
  write(@HELP

       ��������������������������������������������������������������������
       �x                      ���|�H�������U����                        �x
       �u�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�s�w�w�w�w�w�w�w�w�w�s�w�w�w�w�w�w�t
       �x  ���O�榡                    �x����              �x�v��        �x
       �u�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�q�w�w�w�w�w�w�w�w�w�q�w�w�w�w�w�w�t
       �x  help sky                    �x�����U�T��        �x�ڤH        �x
       �x  sky <�A���T��>              �x���|�M���W�D      �x�ڤH        �x
       �x  members                     �x�C�X�u�W���|����  �x�ڤH        �x
       �x  leaveclub                   �x�D�ʰh�X���|      �x�ڤH        �x
       �x  include <�H�W>              �x�N�Y�H���J����    �x�@�k�M��    �x
       �x  dismiss <�H�W>              �x�����Y�H����¾��  �x�@�k�M��    �x
       �x  accept <�H�W>               �x���Y�H�[�J���|    �x��D�H�W    �x
       �x  kickout <�H�W>              �x�N�Y�H�v�X���|    �x��D�H�W    �x
       �x  subleader <�H�W> to <����W>�x�ɯŬY�H���@�k    �x�`��D      �x
       �x  retire <�H�W>               �x�M���Y�H�@�k¾��  �x�`��D      �x
       �x  givepower <�H�W> to <����>  �x���ܬY�H��¾��    �x�`��D      �x
       �x  handover <�H�W>             �x�x��¾�ȥ汵      �x�`��D      �x
       �x  listmember                  �x���|�W�U          �x��D�H�W    �x
       �|�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�r�w�w�w�w�w�w�w�w�w�r�w�w�w�w�w�w�}
	 �� �ϥ� accept ���O���������� joinclub ���O�ӽФ~��ͮġC
         �� �Ѧa�|�ثe���G�Ӥ���:�i���\��j�B�i�a�b��j�C
         �� ���Ť���: <1:����> <2:���> <3:�@�k> <4:��D> <5:�`��D> �C
         �� ��L�Ѧa�|���ư�: <help sky_rule> , <help sky_story> �C
     	
HELP
  );
  return 1;
  }
  if(arg=="sky_rule")
  {
   this_player()->start_more(@RULE

	                           �i�Ѧa�|���W�j
	�@�B  �Y��T�����
	
	      ���������Ҿ֦����Ҧ�����(�N�O�����o)�A���i�H�[�J��L����
	      �o�ˬO�קK�U�����������L�װ����C
	      �P�ɤ]�U�줣�n�N�ۤv������ɵ��L�H�ϥΡC�ӭn�⨤��e���L
	      �H�ɡA����POST�b���|�� Terra Board���G�A�Ѫ��ѥH�W�P�N��
	      �N��Kickout��~�i�e���L�H�C
	      �p�e���P������,�i�HPOST�bTerra Board�A�Ѫ��ѦP�N�C
	      �t�~�T����N�������|�A�p�ۤv�������|�A���n�Ʊ楻�|���s��
	      �A�A�Ӧ����n�����ɡA����POST�b Terra Board�g���ѷ|ĳ�q�L
	      ��\�A�l�i���}���|�C
	      �H�ϤW�z�W�w�̡A�N�v�X�ڡA�÷|�����D�M�w�O�_�[�H�q�r���C
	
	�G�B  �Y�T�D��PK��L���a
	
	      ���������T��PK��L���a�A���ѥ����o�X����O���ҥ~�C
	      �өҦ�PK�������������a�A���ߧY�q���b�u�����ѤH���A�ñN��
	      �pPOST�bTerra Board�A���e���������]�APKER ID�M�QPK��ID�A
	      �Ӧb�u������,�����O�̤j��U�C
	      �ӥ����N�C�X�q�r�¦W��A���������ҥi�����C�Y�QPK�ɡA�u�W
	      �L���ѥH�W�i�����@�ҡA�h�гQPK�������ۦ�POST�L�{�A�ƫ�g
	      ���ѩΥH�W�H���d�ҡA��N���C�J�q�r�¦W��C
	
	      ���D��PK�H�~�A���������P�L�H����L�ȯɡA����POST�b
	      Terra Board�Ѫ��ѥH�W�M�w��ʡA���i�ۦ�PK���C
	      �H�ϤW�z�W�w�̡A�N�v�X���ڡA�å����D�����p�M�w�O�_�[�H�q
	      �r�C
	
	�T�B  �T��s�楻�|�˳�
	                    �i�s�楻�|�˳ƬO�Y���o��j
	      ��m�����|�����˳Ƭ������@���A���o�p���ܽ�C�������i���N
	      �[�H�����A�ߤ��i�������h�A�Ӧb���u�ɡA������^���C
	      �p�bWiz�ŧiReboot time�ɡA�i�ۦ殳�h�ܽ�C
	      �p���ܽ�˳ƪ̡A�N�v�X���ڨåB�i���D�L�D�j�j�C
	      �Y�����Ʊ��ݰ��W���u�A�h�����U�P�@�����H�N����z�C    
	     �ӷ|����EQ���i�ɵ��D�������H�A�к�O�C
   
RULE
);
return 1;
  }
  if(arg=="sky_story")
  {
  this_player()->start_more(@SKY_PART

	�i�Ѧa�|�ǰO�M�_�� �j
	  
	    �ܻ��ѤU�|�����`���D�P�B�q�b���X�j�C�F�Z�L�j�|�ɡA��
	�D�i�Q���j���g�F�Q�l�v�Lŧ���V�����A�Z�L�j�|�W�����⻰
	���V�����ϴ��C�b���}�j�C�F�ɡA�b�����@�ѫe���V�P�B�q����
	�A�ӥL�N�O�j�C�F���D�H �|�F�C�� �T���СA�T���ЦV�P�B�q��
	��]ı�o�P�B�q�P�䦳�t�A�h�J�L�b��Ǥ�l�A����M�t�A�@�C
	�C�өP�B�q���n�ͧ���(Coco)�]�դO��H�A���M�L�b���B�A����
	�Mť��@���_�_���򪺸ܡC�ڧ����b�Z�L�j�|��V�P�椧�H�һ�
	�A���ɥT���ЦV�P�B�q�z�S�A�b�j�C�F�F�n�G�ʨ��A���@�W����
	�M�t�A���a��A�Ʀ~�e�T���иg�L���B�A�oı���B�z�g�X�_����
	����A�Ӧ]�����ɥT���Эn���^�j�C�F�ӵL�v�z�|�A�ҥH�N����
	��b�ߤW�C�Ӧb�Z�L�j�|�W�A�T���еoı�P�B�q���W��������@
	�ǺѺ����A�A�ӥB�M�T���з��~�b���M�t�A���쪺�@�ˡA�ҥH
	���ɩP�B�q�e���M�t�A�A�����w�|���N�~����C
	
	��������o�B�A�N���]���ɤ�W�x�s�ۤT�⯫�Z�u���A�]�Ӻ믫
	�O�j��A���᪺��ʹNť���M�F�D�D�D
	    �Ӧb���ѯQ��겳�L��A�P�B�q�M����ı�o�~�ӵL�ơA�N
	�����M�t�A�ݬݧa�C�P�檺�O�P�B�q�~�֮ɵ��Ѫ��n�S�̩j�f�A
	�b�U�H�I���U�A�P�B�q�v�O���H�e�����M�t�A�d�Өs��....
	�b���M�t�A�Q���~�A�U�H�]����������M�t�A���ߩҵo�X�����
	�Ӳ��H�N�V������i�o�A�~�g���B���ҲM�աA�U�H���ۨ��ۡA��
	�M���Ѧa�ܦ�A���O�ѫ�@��....�Ѫť��U�F�ƭӧ�p�A���bĵ
	�i�U�H���n�~��e�i�C
	���H�O���~�b����W�樫������A���M���|�Q�o�p�n�~�h�C�N�b
	���ɡA�a�U�_�_�F�ƤQ�����~�A�U�H�H�Y�B�_�ۨ����ǡA�P�B�q
	�����B�_���������C�k�A�t�X���\�N���O���E��k�u���W�A�B�_
	���q�s�o�ޡA�Ө��Ǧn�ͧ���(Coco)�M�رT��(Ayumi)���O�V�F��
	���M�t�A���߱��h�C�����B�_��W���H�x�s�����Z�u���V���~�Y
	�h�A���رT���]����e�̡A�B�_�K���������񵷫l�V���~���h�C
	
	���M���H�]�O����A���b�W�Ԥ����O���ӱo�S�O�h�A�Ӳ��~����
	�O���u�F�`�A�N�b���ɡA���H�oı�P�椧���P��(Sevil)�����F
	�A�N�b�U�H�ôb�ɡAť��@���~�j�s�@�n..�A���q�F�@�a�C���
	�O�P���Ψ䯫�������ޭI�륿�����~�I�ߡA�O�Ӳ��~�~�o�X����
	�몺�ǥs...
	
	���H�䥴��i�A��F�F���������B�A�Ӳ��~�̤]�����a��A��
	�H�~�P�F�f��C�N�b���ɺ���j���A���H�V��������ߤ@��A��
	���䤤���@���A�Ӧ����N�O�o�X�������]�C
	�P�B�q�V�������h�A�U�H�ߧY�s�W�D���n���V����������A���P
	�B�q�N����A���i��O�T���Ыe���һ������A���ѥT���Ыe����
	�������ӬO�ѤE�Ѥ��~�Ө�A��O�@���_�C
	�Ӧb����T�~�A���H�N�b�ѫ��}���ߤ�A�b�Ѧ�����}�ФF�ѤU
	�㻮���W���i�Ѧa�|�j�A�Ӧb���M�t�A��o�����A�N�O�ѤU�|��
	�������_�� �Ѧa���� �C

SKY_PART
);
  return 1;	
 }
 return 0;
}