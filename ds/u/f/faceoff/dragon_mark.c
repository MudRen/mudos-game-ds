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
// info:
// ([
//    level:
//    title:
//    info1:
//    info2:
// ])
#include <ansi.h>
#include <armor.h>
#define CLUB_NAME "�g�s��"
#define CLUB_ID "dragon"
#define CLUB_CHANNEL "dragon"
#define CLUB_MARK "dragon necklace"
inherit NECK;
private string *members_level = ({
	"����", //0
	"����", //1
	"��D", //2
	"�@�k", //3
	"����", //4
	"�����D", //5
	"���D", //6
});
void create()
{
	set_name(HIR"�s�ζ���"NOR,({"dragon necklace","necklace","club_mark"}));
	set_weight(600);
	if( clonep() ) set_default_object(__FILE__);
	else
	{
		set("value",0);
		set("material","iron");
		set("no_drop",1);
		set("no_sell",1);
		set("no_sac",1);
		set("unit","��");
	set("long",@LONG
�o�O�@������⪺����, �Ψ��ҩ��ۤv�O�g�s�����@���l�C
�A�i�H��(help dragon)�Ӭd�ݦ��������|���O�C�Y�Q�F�Ѩg�s��
�����v�i�H��(about dragon)�Ө��o�i�@�B����ơC

LONG
);
	}
	set("club_id",CLUB_ID);
	set("club",CLUB_NAME);
	set("sub_club",({"���s��","�g�s��","�r�s��","���s��"}));
	set("club_max_level",6);
	set("armor_prop/shield", 1);
	setup();
	set("volume",1);
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
		 "title": "�g�s���S���U��",
		 "info1": "�L",
		 "info2": ctime(time()),
		 "info3": ""
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
  case 6:
		add_action("do_handover","handover");
		add_action("do_lockleave","lockleave");
  case 5:
		add_action("no_suicide","suicide"); //����۱�
  case 4:
		add_action("do_givepower","givepower");
		add_action("do_listmember","listmember");
  case 3:
  		add_action("do_accept","accept");
		add_action("do_kickout","kickout");
		add_action("do_subleader","subleader");
		add_action("do_retire","retire");
  case 2:
		add_action("do_include","include");
		add_action("do_dismiss","dismiss");
  default:
   		add_action("do_help","help");
   		add_action("do_about","about");
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
 if(wizardp(user)) return "�i�a�A�|���j�g�s���S���U��  ";
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
 	case 6: str+="�g�s���s�Y�Ѥj  "; break;
 	case 5: str+="�g�s�������D    "; break;
 	case 4: str+="�g�s������      "; break;
 	case 3: str+="�g�s���W���@�k  "; break;
 	case 2: str+=info["info1"]+"����D    "; break;
 	default: 
 		if(info["info1"]!="�L")
 		{
 			str+=info["info1"]+"���      "; break;
 		} else str+="�g�s���@������  ";
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
//	users = filter_array( users(), "filter_members", this_object(),list );
	users = CLUB_D->find_online_members(CLUB_ID);
	str = "�� "+CLUB_NAME+": \n";
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
			if(me_info["level"] != 2 ) return notify_fail("�u������D��N�������J����C\n");
			if(!stringp(sub=me_info["info1"])) return notify_fail("�u������D��N�������J����C\n");
			if(ob_info["level"] != 1 || ob_info["info1"]!="�L")
				return notify_fail("�u���@�������i�H���J�A������C\n");
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
			if(!sub=me_info["info1"] || me_info["level"]!=2 ) return notify_fail("�u������D��K�����¾��\n");
			if(ob_info["level"] != 1 ) return notify_fail("�A�������Ѱ���誺¾�ȡC\n");
			if(ob_info["info1"] != sub) return notify_fail("���ä��ݩ�A������C\n");
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
		 ob->add("channels", ({"dragon"}));
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
			if(ob_info["level"] != 1)
				return notify_fail("�u���@�������i�H��������D�C\n");
			if( (int) member_array(sub, query("sub_club"))<0 )
				return notify_fail("�ثe�i�Ϊ������� <���s��> <�g�s��> <�r�s��> <���s��> \n");
			ob_info["level"]=2;
			ob_info["info1"]=sub;
			CLUB_D->set_member(CLUB_ID,getuid(ob),ob_info);
			if(!mark=present(CLUB_MARK,ob))
			{
				write("���|�H�����o���ѡC\n");
			}
			else
			{
	 			message_vision("$N�N$n���@��"+sub+"����D, �éM$n����j�y�@�f�C\n",me,ob);
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
			if(ob_info["level"] != 2) return notify_fail("��H�ä��O����D�C\n");
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
	 			message_vision("$N�K���F$n��"+sub+"����D¾�ȡC\n",me,ob);
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
				return notify_fail("�ثe���Ť��� <1:����> <2:��D> <3:�@�k> <4:����> <5:�����D> <6:���D> \n");
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
					ob_info["level"]=5;
					ob_info["info1"]="�L";
		 			ob_info["info2"]=ctime(time());
		 			ob_info["info3"]=me->name_id(1);
					break;
				case 6:
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
		 	
		 	ob_info["level"]=6;
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
			message( "channel:dragon",CYN"�i"+CLUB_NAME+"�j"+me->name(1)+"("+capitalize(me->query("id"))+")�N"+CLUB_NAME+"�����v���浹"+ob->name(1)+"("+capitalize(ob->query("id"))+")�C\n"NOR, users() );
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
	message( "channel:dragon",CYN"�i"+CLUB_NAME+"�j"+me->name(1)+"("+capitalize(me->query("id"))+")�D�ʰh�X�F"+CLUB_NAME+"�C\n"NOR, users() );
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
 if(arg=="dragon")
 {
  write(@HELP

       ��������������������������������������������������������������������
       �x                      ���|�H�������U����                        �x
       �u�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�s�w�w�w�w�w�w�w�w�w�s�w�w�w�w�w�w�t
       �x  ���O�榡                    �x����              �x�v��        �x
       �u�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�q�w�w�w�w�w�w�w�w�w�q�w�w�w�w�w�w�t
       �x  help plate                  �x�����U�T��        �x����        �x
       �x  dragon <�A���T��>           �x���|�M���W�D      �x����        �x
       �x  members                     �x�C�X�u�W���|����  �x����        �x
       �x  leaveclub                   �x�D�ʰh�X���|      �x����        �x
       �x  include <�H�W>              �x�N�Y�H���J����    �x��D�M��    �x
       �x  dismiss <�H�W>              �x�����Y�H����¾��  �x��D�M��    �x
       �x  accept <�H�W>               �x���Y�H�[�J���|    �x�@�k�H�W    �x
       �x  kickout <�H�W>              �x�N�Y�H�v�X���|    �x�@�k�H�W    �x
       �x  subleader <�H�W> to <����W>�x�ɯŬY�H������D  �x�@�k�H�W    �x
       �x  retire <�H�W>               �x�M���Y�H����D¾��x�@�k�H�W    �x
       �x  givepower <�H�W> to <����>  �x���ܬY�H��¾��    �x���ѥH�W    �x
       �x  lockleave <on> <off>        �x����ۦ�h��      �x���D        �x
       �x  handover <�H�W>             �x�x��¾�ȥ汵      �x���D        �x
       �x  listmember                  �x���|�W�U          �x���ѥH�W    �x
       �|�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�r�w�w�w�w�w�w�w�w�w�r�w�w�w�w�w�w�}
	 �� �ϥ� accept ���O���������� joinclub ���O�ӽФ~��ͮġC
         �� �g�s���ثe���|�Ӥ���: �i���s��j�B�i�g�s��j�B�i�r�s��j�B�i���s��j�C
         �� ���Ť���: <1:����> <2:��D> <3:�@�k> <4:����> <5:�����D> <6:���D>�C

HELP
  );
  return 1;
 }
 return 0;
}
int do_about(string arg)
{
 if(arg=="dragon")
 {
  write(@ABOUT
���g�s���H���Шg�s�O

    �ܻ����ܮɥN�A�E�Ѥ��~���@�뤧�ۼY�J�F�Z���A�ɭP��ɦb�Z
  ���D�`�������s�ھD�췴���C

    �������b�A���p��....

    �Ӧb���a������A�g�L�ɶ����i�m....�H���̵ۤѽ᪺����C�C
  �a�����D�ӯ��ܮɥN���G�ơA�ٶ����y�Ǧb�o�ӥ@�ɡD

    �䤤�@�ӳ̥O���G�H�h�D���߰ʪ��A�N�O���ܮɥN�������@�ɡA
  �s�ڱڤH���m�s���n�ӳo�_���۶Ǥ��O���q�s�ڱڤH�����A�ӬO�L
  �̬Ӫ̤����D�ǻD���A�s�����㦳�ܤj���F�a�A�ӳ̤�����������
  ���ӥj���O�A��O�H�\�O�j�W���Ϊk�N���o�Ӫ��F...

    �۶Ƿ��s�ڷ����ɡA�뤧�۩ұa�Ӫ��R���A�ް_�j�q����A�O�j
  �����s�ڤH���e���ǭ��Ϸ��A���䤤���@�p�����s�ڱڤH�A�]�w��
  �F�뤧�۱N�|�Y���A�ҥH�b�Y���e��F�a���A�Q�׶}�o���a��..��
  ���a�A�뤧�۪��O�q�ӼF�`�F�A�P�O�L�̤]�Q�뤧�۩ұa�Ӫ��R��
  �����A�Ҥ��P���O�A�a�����a������O�Ǥ���a���A�O���e���o�H
  �O�s�ӶǻD��ɳo���s�ڪ��a�U�����ҡA�N�O�{����誺�a�U�j��
  ��F�D�ҥH�A����W���\�h�_�ಧ�h���Q�o��o�_���A����F�a�U
  �j�Ӷ骺�H�A���u���i�J�A�q�S���H����ٵۦ^��..
  
    �n�Ƥ��{�N�����䦳�ۺغ�����..�]���H���O�C�G..�ҥH�O�j��
  ��o�@�a�S�H������..�ӳo�Ӷǻ���@�N�A�@�N���y�ǤU�h....

    �������D�ӯT(ttoopp), �b�ĵ��ɥN�w�g�m�N�@���n�\�ҡD�L�b
  �p�ɴN�`ť�������G��, ��Lť��o�G�ƬO�A�N�Q���l�ޤF��ӯT
  ���j���H, �L�N�椣�Ϋݥh�a�U�j�Ӷ鱴�I..�L..���z�|��������
  ��..���M��i�L�H��������I�A���..����ǻD..���@�W�~�C�L�h
  �A���ۥѡm�s���n�^��������A��ɦU��_�ಧ�h�A�զ�����W��
  ���j�W�A�O����W�¹D�D�����x���i�g�s���j
  
    ���D�A�ӯT(ttoopp)�u�����\����m�s���n�H
    
    �L�p�󮳪���H���S�O�t�@�ӬG�ƤF...

ABOUT
  );
  return 1;
 }
 return 0;
}
