// ���|�H��
// "club/name": ���|�W��
// "club/level": ���a�b���|��������(1~?)
// 1: �@������ (����)
// 2: ��D (������)
// 3: �@�k (�j����)
// 4: ���� (�ѿѪ�)
// 5: ���D (�����x) ��1�W
// "club/title": ���|�Y��
// "club/info1": �ƥΰ�1 (�����W��)
// "club/info2": �ƥΰ�2
// "club/info3": �ƥΰ�3
// "club/info4": �ƥΰ�4
// "club/info5": �ƥΰ�5
#include <ansi.h>
#define CLUB_NAME "�ڤ۾Զ�"
#define CLUB_CHANNEL "dream"
inherit ITEM;
void create()
{
	set_name(HIC"�ڤ۾Զ�����"NOR,({"dream team badge","badge","club_mark"}));
	set_weight(750);
	set("value",0);
	set("no_drop",1);
	set("unit","��");
	set("long",@LONG
�o�O�@�ӹڤ۾Զ��������M�ݫH��, �A�i�H��(help badge)�Ӭd�ݦ��������|���O�C

LONG
);
	set("club",CLUB_NAME);
	set("sub_club",({"��������","���ڤ���","�H������",}));
	setup();
}

int query_autoload() { return 1; } //save_item

void init()
{
 if(environment(this_object())!=this_player()) return;
 if(this_player()->query("club/name")!=query("club")) return;
 switch(this_player()->query("club/level"))
 {
  case 5:
		add_action("do_handover","handover");
		add_action("no_suicide","suicide"); //�������D�۱�
  case 4:
		add_action("do_givepower","givepower");
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
   		add_action("do_members","members");
   		add_action("do_leaveclub","leaveclub");
 }
}

int do_help(string arg)
{
 if(arg=="badge")
 {
  write(@HELP

       ��������������������������������������������������������������������
       �x                      ���|�H�������U����                        �x
       �u�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�s�w�w�w�w�w�w�w�w�w�s�w�w�w�w�w�w�t
       �x  ���O�榡                    �x����              �x�v��        �x
       �u�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�q�w�w�w�w�w�w�w�w�w�q�w�w�w�w�w�w�t
       �x  help badge                  �x�����U�T��        �x����        �x
       �x  dream <�A���T��>            �x�ڤۤ����M���W�D  �x����        �x
       �x  members                     �x�C�X�u�W��������  �x����        �x
       �x  leaveclub                   �x�D�ʰh�X�ڤ۾Զ�  �x����        �x
       �x  include <�H�W>              �x�N�Y�H���J����    �x�������M��  �x
       �x  dismiss <�H�W>              �x�����Y�H����¾��  �x�������M��  �x
       �x  accept <�H�W>               �x���Y�H�[�J�ڤۤ����x�j�����H�W  �x
       �x  kickout <�H�W>              �x�N�Y�H�v�X�ڤۤ����x�j�����H�W  �x
       �x  subleader <�H�W> to <�����W>�x�ɯŬY�H��������  �x�j�����H�W  �x
       �x  retire <�H�W>               �x�M���Y�H������¾��x�j�����H�W  �x
       �x  givepower <�H�W> to <����>  �x���ܬY�H��¾��    �x�ѿѪ��H�W  �x
       �x  handover <�H�W>             �x�����v�汵        �x�����x      �x
       �|�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�r�w�w�w�w�w�w�w�w�w�r�w�w�w�w�w�w�}

         �� �ڤ۾Զ��ثe���T�Ӥ���: �i���������j�B�i���ڤ����j�B�i�H�������j
         �� ���Ť���: <1:����> <2:������> <3:�j����> <4:�ѿѪ�> <5:�����x>

HELP
  );
  return 1;
 }
 return 0;
}

int filter_members(object ppl)
{
        if( !environment(ppl) ) return 0;
        if( ppl->query("club/name")==CLUB_NAME ) return 1;
        return 0;
}

string show_level(object user)
{
 int level,rank;
 string str;
 level=user->query("level");
 if(level>100) 	str = "�i????????�j";
 else if(level<11)	str = "�i�� "+chinese_number(level)+" �šj";
 else if(level<21) 	str = "�i��"+chinese_number(level)+"�šj";
 else if(level%10==0)   str = "�i��"+chinese_number(level)+"�šj";
 else str = "�i"+chinese_number(level)+"�šj";
 rank=user->query("club/level");
 switch(rank)
 {
 	case 5: str+=" �ڤ۾Զ������x "; break;
 	case 4: str+=" �ڤ۾Զ��ѿѪ� "; break;
 	case 3: str+=" �ڤ۾Զ��j���� "; break;
 	case 2: str+=" "+user->query("club/info1")+"������ "; break;
 	default: 
 		if(user->query("club/info1"))
 		{
 			str+=" "+user->query("club/info1")+"����   "; break;
 		} else str+=" �ڤ۾Զ��԰��� ";
 }
 return str;
}

int sort_member(object ob1, object ob2)
{
	if(ob1->query("club/level") == ob2->query("club/level"))
		return  (int)ob1->query("level") - (int)ob2->query("level");
	else return (int)ob1->query("club/level") - (int)ob2->query("club/level");
}

int do_members(string arg)
{
	object *users;
	string str;
	int i,ppl_cnt,idle;
	
	users = filter_array( users(), "filter_members", this_object() );
	str = "�� �ڤ۾Զ�: \n";
	str += "�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w\n";

	users = sort_array(users, "sort_member", this_object());

	ppl_cnt = 0;
	i = sizeof(users);
	while( i-- )
	{
			// Skip those users in login limbo.
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
			if(users[i]->query_temp("netdead")) str+=HIG"<�_�u��>"NOR;
			if(idle>60) str +=sprintf(HIY" (�o�b%d����)"NOR,idle/60);
			str +=sprintf("\n"NOR);
			ppl_cnt++;
	}
	str += "�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w\n";
	str = sprintf("%s�ثe�@�� %d �춤���b�u�W.\n", str, ppl_cnt);
	this_player()->start_more(str);
	return 1;
}

int do_include(string arg)
{
	string sub,club;
	object ob,me;
	me=this_player();
	
        if(!arg) return notify_fail("include <�H�W>\n");
        else
        {
                ob = present(arg, environment(me));
	        if(!ob) return notify_fail("�o�̦��o�ӤH�ܡS\n");
		if(!userp(ob)) return notify_fail("�o�̦��o�ӤH�ܡS\n");
		if(club=ob->query("club/name"))
		{
			if(club!=CLUB_NAME) return notify_fail("���èS���[�J"+CLUB_NAME+"�C\n");
			if(!sub=me->query("club/info1") || me->query("club/level")!=2) return notify_fail("�u����������N�������J����\n");
			if(ob->query("club/level") != 1 || ob->query("club/info1"))
				return notify_fail("�u���򥻶����i�H���J�A�������C\n");
			ob->set("club/info1",sub);
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
	string sub,club;
	object ob,me;
	me=this_player();
	
        if(!arg) return notify_fail("dismiss <�H�W>\n");
        else
        {
                ob = present(arg, environment(me));
	        if(!ob) return notify_fail("�o�̦��o�ӤH�ܡS\n");
		if(!userp(ob)) return notify_fail("�o�̦��o�ӤH�ܡS\n");
		if(club=ob->query("club/name"))
		{
			if(club!=CLUB_NAME) return notify_fail("���èS���[�J"+CLUB_NAME+"�C\n");
			if(!sub=me->query("club/info1") || me->query("club/level")!=2) return notify_fail("�u����������K����������¾��\n");
			if(ob->query("club/level") != 1 ) return notify_fail("�A�������Ѱ���誺¾�ȡC\n");
			if(ob->query("club/info1") != sub) return notify_fail("���ä��ݩ�A�������C\n");
			ob->delete("club/info1");
		 	message_vision("$N�Ѱ��F$n"+sub+"��¾��, �n�n�Y��: �S�֤F�@�ӤH�~...�u�O�i���ڡC\n",me,ob);
		 	ob->save();
		 	return 1;
		}
		 else return notify_fail("���èS���[�J"+CLUB_NAME+"�C\n");
	}
	return 1;
}

int do_accept(string arg)
{
	string club;
	object ob,mark,me;
	me=this_player();
        if(!arg) return notify_fail("�A�n���֥[�J�Զ��S\n");
        else
        {
                ob = present(arg, environment(me));
	        if (!ob) return notify_fail("�o�̦��o�ӤH�ܡS\n");
	        if(!userp(ob)) return notify_fail("�o�̦��o�ӤH�ܡS\n");
		if(club=ob->query("club/name"))
		{
			if(club==CLUB_NAME) return notify_fail("���w�g�O"+CLUB_NAME+"���@���l�F�C\n");
			else return notify_fail("���w�g�[�J�F�O�������C\n");
		}
		 else
		{
		 mark=new(base_name(this_object()));
		 if(!mark) return notify_fail("���|�H�����o���ѡC\n");
		 if( (mark->query_weight()+ob->query_encumbrance())>ob->query_max_encumbrance() )
 		 return notify_fail(ob->name(1)+"������"+mark->query("name")+"�C\n");
		 message_vision("$N���F$n�@��"+mark->query("name")+", �ö������ﱵ$n����"+CLUB_NAME+"���@���l�C\n",me,ob);
		 ob->set("club/name",CLUB_NAME);
		 ob->set("club/level",1);
		 mark->move(ob);
		 ob->save();
		}
	}
	return 1;
}

int do_kickout(string arg)
{
	string club,*tuned_ch;
	object ob,mark,me;
	me=this_player();
	
        if(!arg) return notify_fail("�A�n�N�ֽ�X�Զ��S\n");
        else
        {
                ob = present(arg, environment(me));
	        if (!ob) return notify_fail("�o�̦��o�ӤH�ܡS\n");
	        if(!userp(ob)) return notify_fail("�o�̦��o�ӤH�ܡS\n");
		if(club=ob->query("club/name"))
		{
			if(club!=CLUB_NAME) return notify_fail("���èS���[�J"+CLUB_NAME+"�C\n");
			else 
			{
				if(ob->query("club/level") >= me->query("club/level"))
					return notify_fail("�A�������N����X�Զ��C\n");
				else
				{
		 			tuned_ch = ob->query("channels");
		 			if( pointerp(tuned_ch) && member_array(CLUB_CHANNEL, tuned_ch)!=-1 )
		 			{
		 					tuned_ch -= ({ CLUB_CHANNEL });
							ob->set("channels", tuned_ch);
		 			}
					ob->delete("club");
					if(!mark=present("badge",ob)) return notify_fail("���|�H�����o���ѡC\n");
		 			message_vision("$N�S���F$n��"+mark->query("name")+", �ñj��$n�h�X"+CLUB_NAME+"�C\n",me,ob);
		 			destruct(mark);
		 			ob->save();
		 			return 1;
				}
			}
		}
		 else return notify_fail("���èS���[�J"+CLUB_NAME+"�C\n");
	}
	return 1;
}

int do_subleader(string arg)
{
	string id,sub,club;
	object ob,me,mark;
	me=this_player();
	
        if(!arg) return notify_fail("subleader <�H�W> to <�����W>\n");
        else
        {
        	if( sscanf(arg, "%s to %s", id, sub)!=2 ) return notify_fail("subleader <�H�W> to <�����W>\n");
                ob = present(id, environment(me));
	        if(!ob) return notify_fail("�o�̦��o�ӤH�ܡS\n");
		if(!userp(ob)) return notify_fail("�o�̦��o�ӤH�ܡS\n");
		if(club=ob->query("club/name"))
		{
			if(club!=CLUB_NAME) return notify_fail("���èS���[�J"+CLUB_NAME+"�C\n");
			else 
			{
				if(ob->query("club/level") != 1)
					return notify_fail("�u���򥻶����i�H�����������C\n");
				if( (int) member_array(sub, query("sub_club"))<0 )
					return notify_fail("�ثe�i�Ϊ������� <��������> <���ڤ���> <�H������> \n");
				ob->set("club/level",2);
				ob->set("club/info1",sub);
				if(!mark=present("badge",ob)) return notify_fail("���|�H�����o���ѡC\n");
		 		message_vision("$N�N$n���@��"+sub+"������, �éM$n����j�y�@�f�C\n",me,ob);
		 		mark->move(ob);
		 		ob->save();
		 		return 1;
			
			}
		}
		 else return notify_fail("���èS���[�J"+CLUB_NAME+"�C\n");
	}
	return 1;
}

int do_retire(string arg)
{
	string sub,club;
	object ob,me,mark;
	me=this_player();
	
        if(!arg) return notify_fail("retire <�H�W> \n");
        else
        {
                ob = present(arg, environment(me));
	        if(!ob) return notify_fail("�o�̦��o�ӤH�ܡS\n");
		if(!userp(ob)) return notify_fail("�o�̦��o�ӤH�ܡS\n");
		if(club=ob->query("club/name"))
		{
			if(club!=CLUB_NAME) return notify_fail("���èS���[�J"+CLUB_NAME+"�C\n");
			else 
			{
				if(ob->query("club/level") != 2)
					return notify_fail("��H�ä��O�������C\n");
				sub=ob->query("club/info1");
				ob->set("club/level",1);
				ob->delete("club/info1");
				if(!mark=present("badge",ob)) return notify_fail("���|�H�����o���ѡC\n");
		 		message_vision("$N�K���F$n��"+sub+"������¾�ȡC\n",me,ob);
		 		mark->move(ob);
		 		ob->save();
		 		return 1;
			
			}
		}
		 else return notify_fail("���èS���[�J"+CLUB_NAME+"�C\n");
	}
	return 1;
}

int do_givepower(string arg)
{
	string id,club;
	int level;
	object ob,me,mark;
	me=this_player();
	
        if(!arg) return notify_fail("givepower <�H�W> to <����>\n");
        else
        {
        	if( sscanf(arg, "%s to %d", id, level)!=2 ) return notify_fail("givepower <�H�W> to <����>\n");
                ob = present(id, environment(me));
	        if(!ob) return notify_fail("�o�̦��o�ӤH�ܡS\n");
		if(!userp(ob)) return notify_fail("�o�̦��o�ӤH�ܡS\n");
		if(club=ob->query("club/name"))
		{
			if(club!=CLUB_NAME) return notify_fail("���èS���[�J"+CLUB_NAME+"�C\n");

			if(ob->query("club/level") >= me->query("club/level"))
				return notify_fail("�A�S�������ܹ�誺�Զ����šC\n");
			if(level > 4 || level < 1 )
				return notify_fail("�ثe���Ť��� <1:����> <2:������> <3:�j����> <4:�ѿѪ�> <5:�����x> \n");
			switch(level)
			{
				case 1:
					ob->delete("club");
					ob->set("club/name",CLUB_NAME);
					ob->set("club/level",1);
					break;
				case 2:
					return notify_fail("�Х�subleader���O�ӫ��w�@�Ӥ����C\n");
					break;
				case 3:
					ob->delete("club");
					ob->set("club/name",CLUB_NAME);
					ob->set("club/level",3);
					break;
				case 4:
					ob->delete("club");
					ob->set("club/name",CLUB_NAME);
					ob->set("club/level",4);
					break;
				case 5:
					return notify_fail("�Х�handover���O�������v����C\n");
					break;
				default: return notify_fail("�Ѽƿ��~�C\n");
				
			}

			if(!mark=present("badge",ob)) return notify_fail("���|�H�����o���ѡC\n");
			message_vision("$N�N$n���Զ�¾�쵥�Ŵ��@��"+(string)level+", �éM$n����j�y�@�f�C\n",me,ob);
			mark->move(ob);
			ob->save();
			return 1;
			

		}
		 else return notify_fail("���èS���[�J"+CLUB_NAME+"�C\n");
	}
	return 1;
}

int do_handover(string arg)
{
	string club;
	object ob,mark,me;
	me=this_player();
        if(!arg) return notify_fail("�A�n�N�����v���浹�֡S\n");
        else
        {
                ob = present(arg, environment(me));
	        if (!ob) return notify_fail("�o�̦��o�ӤH�ܡS\n");
	        if(!userp(ob)) return notify_fail("�o�̦��o�ӤH�ܡS\n");
		if(club=ob->query("club/name"))
		{
			if(club!=CLUB_NAME) return notify_fail("���ä��O"+CLUB_NAME+"���@���l�C\n");
		 	
		 	ob->set("club/level",5);
		 	me->set("club/level",4);
		 	ob->delete("club/info1");
		 	me->delete("club/info1");
		 
		 	mark=present("badge", environment(me));
		 	if(!mark) return notify_fail("���|�H�����o���ѡC\n");
			mark->move(me);
			mark=present("badge", environment(ob));
		 	if(!mark) return notify_fail("���|�H�����o���ѡC\n");
			mark->move(ob);
			message_vision("$N�N"+CLUB_NAME+"���`�����v���浹$n�C\n",me,ob);
			message( "channel:dream",CYN"�i�ڤ۾Զ��j"+me->name(1)+"("+capitalize(me->query("id"))+")�N"+CLUB_NAME+"�����v���浹"+ob->name(1)+"("+capitalize(ob->query("id"))+")�C"NOR, users() );
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
	string club,*tuned_ch;
	object mark,me;
	me=this_player();
	
	if(me->query("club/level") == 5)
		return notify_fail("�A�������N�����v�ಾ�~�����}�Զ��C\n");

	if(!mark=present("badge",me)) return notify_fail("���|�H�����o���ѡC\n");
	message_vision("$N�D�ʰh�X�F"+CLUB_NAME+"�C\n",me);
	message( "channel:dream",CYN"�i�ڤ۾Զ��j"+me->name(1)+"("+capitalize(me->query("id"))+")�D�ʰh�X�F�ڤ۾Զ��C"NOR, users() );
	tuned_ch = me->query("channels");
	if( pointerp(tuned_ch) && member_array(CLUB_CHANNEL, tuned_ch)!=-1 )
	{
			tuned_ch -= ({ CLUB_CHANNEL });
			me->set("channels", tuned_ch);
	}
	me->delete("club");
	destruct(mark);
	me->save();
	return 1;
}

int no_suicide(string arg)
{
	write("�����Զ��̰������x, ��X�����v���e���i����, �H�K���~�L�H�C\n");
	return 1;
}