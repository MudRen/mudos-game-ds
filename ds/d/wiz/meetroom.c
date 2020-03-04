// This Program was Written by Luky (ds.muds.net 7000)
// Original: The Dream of Seven.
// All rights reserved.1999.11.23
#include <ansi.h>
inherit ROOM;
void greeting();

string TOPIC="none";
int do_say(string arg);

void create()
{
 set("short",HIW"�a�U�|ĳ��"NOR);
        set("long", @LONG
�o�̬O�Ův�}�|�Q�ת��a��C�A�ݨ�o�̦��@�i�ܤj�����A��
�Ǧ��\�h���Ū��F�o�ȡA�|ĳ�ǤW�����a�ۤ@�y�Q�����ت������ݿO
�A���䦳�Ӻ޲z�|ĳ�Ǫ����Ѥp�j�����b�@�Ǫ��U�z���C�A�ݨ��
��Ǧ��i�G�i��(note)�A�W���g�ۤ@�Ƕ}�|���`�N���ƶ��C

LONG
        );
        set("exits", ([ /* sizeof() == 2 */
//  "up" : __DIR__"hall1",
]));
	set("light",1);
        set("item_desc",([
        "note" : @NOTE
	
	�|ĳ�Ϋ��O:
	============     ===============================
        start [�W��]     �}�l�@��[�W��]�|ĳ (arch�H�W)
        silent           �N�|ĳ�ǳ]�w���R�����A (�D����)
        handover         �N�D���β��浹�L�H (�D����)
        kickout          �N�Y�ӤH��X�|ĳ�� (�D����)
        topic            �d�ߥثe�|ĳ���D�D
        over             �����|ĳ (�D����)
        beginvote [�r��] �}�l�벼 (�i�H�Q�� to beginvote)
        vote [�Ʀr]      �벼
        endvote          �����벼
        ============     ===============================
        
        �`�N�ƶ�: 

        1. �@���}�|����A����H���o�H�N���}�A���Dĳ���P�N�C
	2. �}�|�ɽХ� say (') �o���C
NOTE
,
]));
         set("no_clean_up", 0);
         set("no_recall",1);
         setup();
}

void init()
{
        greeting();
        add_action("do_say","say");
        add_action("do_start","start");
        add_action("do_kickout","kickout");
        add_action("do_handover","handover");
        add_action("do_over","over");
        add_action("do_topic","topic");
        add_action("do_silent","silent");
        add_action("do_nomove","goto");
        add_action("do_nomove","home");
        add_action("no_chat","chat");
        add_action("no_chat","tchat");
        add_action("no_chat","wiz");
        add_action("no_chat","shout");
        add_action("no_chat","rumor");
        add_action("no_chat","sys");
        add_action("do_beginvote","beginvote");
        add_action("do_vote","vote");
        add_action("do_endvote","endvote");
        add_action("noupdate","update");
}

int no_chat(string arg)
{
	if(!this_object()->query("silent")) return 0;
	tell_object(this_player(),"�{�b�|ĳ�ǬO�R���Ҧ��A�T��ϥΤ@���W�D��C\n");
	return 1;
}

int do_nomove(string arg)
{
	if(TOPIC!="none")
	{
		write("���b�}�|����!! �p�G�u���n���}�Х� up ���}�C\n");
		return 1;
	}
	return 0;
}
int noupdate(string arg)
{
	if(TOPIC!="none" && ( arg == "here" || arg == "/d/wiz/meetroom" || arg == "/d/wiz/meetroom.c"))
	{
		write("���b�}�|����!!�Ф��Z�÷|ĳ�C\n");
		return 1;
	}
	return 0;
}

int do_beginvote(string arg)
{
	object me;
	me=this_player();
	if(!wizardp(me)) return notify_fail("�A���O�Ův�C\n");
	if(stringp(this_object()->query("vote"))) return notify_fail("�ثe���b�|��벼!\n");
	if(TOPIC=="none" ) return notify_fail("�ثe�èS���}�|!\n");
	message_vision(HIC"\n$N���X�벼:\n"+arg+"\n"NOR,me);
	log_file("meeting/"+TOPIC,sprintf(HIW"%s(%s)���X�벼���ءC\n\n"NOR+arg+NOR+"\n\n",me->query("name"),me->query("id")));
	this_object()->set("vote",arg);
	this_object()->set("vote_leader",me->query("id"));
	this_object()->delete("vote_result");
	this_object()->delete("vote_member");
	return 1;
}

int do_vote(string arg)
{
	object me;
	string *members;
	me=this_player();
	if(!stringp(this_object()->query("vote"))) return notify_fail("�ثe�èS���|��벼!\n");
	if(TOPIC=="none" ) return notify_fail("�ثe�èS���}�|!\n");
	if(!arg) return notify_fail("�A�n�뤰��?!\n");
	members=this_object()->query("vote_member");
	if(sizeof(members))
	{
		if(member_array(({me->query("id")}),members)!=-1) return notify_fail("�A�w�g��L���F!\n");
	}
	this_object()->add("vote_result/"+arg,({me->query("id")}));
	this_object()->add("vote_member",({me->query("id")}));
	message_vision(HIG"\n$N�벼��: "+arg+"\n"NOR,me);
	log_file("meeting/"+TOPIC,sprintf(HIG"%s(%s)�벼�� "NOR+arg+NOR+"\n",me->query("name"),me->query("id")));
	return 1;
}

int do_endvote(string arg)
{
	object me;
	mapping vote;
	string *keys,*who,str;
	int i,j;
	me=this_player();
	if(!stringp(this_object()->query("vote"))) return notify_fail("�ثe�èS���|��벼!\n");
	if(TOPIC=="none" ) return notify_fail("�ثe�èS���}�|!\n");
	if(me->query("id")!=this_object()->query("vote_leader")) return notify_fail("�����O�o�_�H�~�൲���벼!\n");
	message_vision(HIC"\n$N�����F�o�����벼:\n"NOR,me);
	log_file("meeting/"+TOPIC,sprintf(HIW"%s(%s)�����벼�C\n"NOR,me->query("name"),me->query("id")));
	vote=this_object()->query("vote_result");
	if(!mapp(vote))
	{
		message_vision(HIW"���Ѥp�j��: �o���벼�S�����G�C\n"NOR,me);
	}
	else
	{
		keys=keys(vote);
		str=HIW"���Ѥp�j��: �o���벼���G�p�U:\n";
		for(i=0;i<sizeof(keys);i++)
		{
			str+="  �뵹: "+keys[i]+" ����"+sizeof(vote[keys[i]])+"��";
			for(j=0;j<sizeof(vote[keys[i]]);j++) str+="("+vote[keys[i]][j]+")";
			str+="\n"+NOR;
		}
		message_vision(str,me);
		log_file("meeting/"+TOPIC,str);
	}
	this_object()->delete("vote");
	this_object()->delete("vote_leader");
	this_object()->delete("vote_result");
	this_object()->delete("vote_member");
	return 1;
}

int do_silent(string arg)
{
	object me,*members;
	int i;
	string chief,*channels;
	me=this_player();
	if(TOPIC=="none" || !stringp(chief=this_object()->query("meeting_chief"))) return notify_fail("�ثe�èS���}�|!\n");
	if(me->query("id")!=chief) return notify_fail("�u���ثe�|ĳ���۶��H("+chief+")�~��]�w���R���Ҧ�!\n");
	message_vision("$N�N�|ĳ�ǳ]�w���R���Ҧ��C\n",me);
	members= all_inventory(this_object());
	for(i=0;i<sizeof(members);i++)
	{
		if(members[i]->query_temp("channels")) continue;
		if(channels=members[i]->query("channels"))
		{
			members[i]->set("channels", ({"sys"}));
			members[i]->set_temp("channels",channels);
		}
		members[i]->set("env/auto_reply","�Ův�{�b���b�}�|��!!\n");
	}
	set("silent",1);
	return 1;
}

int do_kickout(string arg)
{
	object me,who;
	int i;
	string chief;
	me=this_player();
	if( TOPIC=="none" || !stringp(chief=this_object()->query("meeting_chief")) ) return notify_fail("�ثe�èS���}�|!\n");
	if( me->query("id")!=chief ) return notify_fail("�u���ثe�|ĳ���۶��H("+chief+")�~���H!\n");
	if(!arg) return notify_fail("�A�n��֥X�h!?\n");
	who = present(arg, this_object());
	if(!who) return notify_fail("�o�̨S���o�ӤH�C\n");
	if( who == me ) return notify_fail("�A����N�ۤv��X�|ĳ�ǡC\n");
	message_vision(HIW"$N�N$n��X�|ĳ�ǡC\n"NOR,me,who);
	add("kickouts",({ who->query("id") }));
	who->move(__DIR__"hall1");
	log_file("meeting/"+TOPIC,sprintf(HIW"%s(%s)�N%s(%s)��X�|ĳ�ǡC\n"NOR,me->query("name"),me->query("id"),who->query("name"),who->query("id")));
	return 1;
}

int do_topic(string arg)
{
	string chief;
	if(TOPIC=="none") write("�ثe�èS���|ĳ�b�i��C\n");
	else
	{
		write(HIG"�ثe�|ĳ���D�D�O: [ "HIW+TOPIC+HIG" ] "NOR);
		if(chief=this_object()->query("meeting_chief")) write(HIG"�D���H�O: [ "HIW+chief+HIG" ] "NOR);
		write("\n");
	}
	return 1;
}

void greeting()
{
	object ob;
	string *kickouts;
	ob=this_player();
	kickouts=this_object()->query("kickouts");
        if(!arrayp(kickouts))
        {
        	     if(TOPIC=="none") message_vision(HIG"\n �|ĳ���ѹ�$N�L������: ��! "+ob->name()+"�{�b�٨S�}�l�}�|��I\n\n"NOR, ob);
        	     else
        	     {
        	     	message_vision(HIG"\n �|ĳ���ѹ�$N��: ��! �|ĳ�w�g�}�l�F���֧��m���U�a�I\n\n"NOR, ob);
        	        log_file("meeting/"+TOPIC,sprintf(HIW"%s(%s)�i�J�|ĳ�ǡC [%s]\n"NOR,
			this_player()->query("name"),this_player()->query("id"),ctime(time())));
        	     }
        }
        else
        {
        	if( member_array(ob->query("id"),kickouts) || !userp(ob))
        	{
    			message_vision(YEL"\n�|ĳ���Ѥ@�ݨ�$N�Q�i�ӴN��$N���F�X�h:"HIW" �{�b���b�}�|���A�����H���ФŶi�J�I\n\n"NOR, ob);
			ob->move(__DIR__"hall1");
        	}
        }
        return;
}

int do_say(string arg)
{
	if(!arg) return 0;
	remove_call_out("rush");
	arg = replace_string(arg, "$BLK$", BLK);
	arg = replace_string(arg, "$RED$", RED);
	arg = replace_string(arg, "$GRN$", GRN);
	arg = replace_string(arg, "$YEL$", YEL);
	arg = replace_string(arg, "$BLU$", BLU);
	arg = replace_string(arg, "$MAG$", MAG);
	arg = replace_string(arg, "$CYN$", CYN);
	arg = replace_string(arg, "$WHT$", WHT);
	arg = replace_string(arg, "$HIR$", HIR);
	arg = replace_string(arg, "$HIG$", HIG);
	arg = replace_string(arg, "$HIY$", HIY);
	arg = replace_string(arg, "$HIB$", HIB);
	arg = replace_string(arg, "$HIM$", HIM);
	arg = replace_string(arg, "$HIC$", HIC);
	arg = replace_string(arg, "$HIW$", HIW);
	arg = replace_string(arg, "$NOR$", NOR);
	arg = replace_string(arg, "$BEEP$", BEEP);
	message_vision(HIY+"$N��:"+arg+"\n"NOR,this_player());
        if(TOPIC !="none")
  	log_file("meeting/"+TOPIC,sprintf( "%s(%s)���D: "HIC+arg+NOR"\n",
	this_player()->query("name"),this_player()->query("id")));
        call_out("rush",300);
        return 1;
}

int do_start(string str)
{
	object me;
        me=this_player();
        if(!wizardp(me)) return notify_fail("�A���O�Ův�C\n");
  	if( wiz_level(me) < wiz_level("(arch)") )
  		return notify_fail(HIW"arch �H�W��¾�Ȥ~��D���|ĳ�C\n"NOR);
  	if(TOPIC !="none") return notify_fail("�ثe�w�g���@�ӷ|ĳ�F�C\n");
  	if(!str ) return notify_fail("�}�|�����n���w�@�ӥD�D�~�వ�O���C\n");
        if( str =="none") return notify_fail("�|ĳ�W�٤��i�H�� none �C\n");
        TOPIC =str;
 	message_vision("[�}�l�}�|]-�|ĳ�W��:"HIC+str+NOR" �D����: "HIG"$N "NOR"�C\n",this_player());
 	log_file("meeting/"+TOPIC, sprintf("�}�l�}�|-�|ĳ�W��:" HIC+str+NOR" �D����: "HIG"%s \n",this_player()->short(1)));
 	log_file("static/MEETING",
  	sprintf( "%s(%s)�D���|ĳ "HIC+TOPIC+NOR"�C[%s]\n",me->name(1), geteuid(me), ctime(time()) ) );
        this_object()->set("meeting_chief",me->query("id"));
        return 1;
}

int do_handover(string arg)
{
	object me,who;
	int i;
	string chief;
	me=this_player();
	if(TOPIC=="none" || !stringp(chief=this_object()->query("meeting_chief")) ) return notify_fail("�ثe�èS���}�|!\n");
	if(me->query("id")!=chief) return notify_fail("�u���ثe�|ĳ���۶��H("+chief+")�~���ಾ�D����!\n");
	if(!arg) return notify_fail("�A�n�N�D���Υ浹��!?\n");
	who = present(arg,this_object());
	if(!who) return notify_fail("�o�̨S���o�ӤH�C\n");
	if( who == me ) return notify_fail("�A�w�g�O�D���H�F�C\n");
	message_vision(HIW"$N�N�D���β��浹$n�C\n"NOR,me,who);
	this_object()->set("meeting_chief",who->query("id"));
	log_file("meeting/"+TOPIC,sprintf(HIW"%s(%s)�N�D���β��浹%s(%s)�C\n"NOR,
	me->query("name"),me->query("id"),who->query("name"),who->query("id")));
	return 1;
}

int do_over(string arg)
{
	object me,*members,leader;
	string chief,*channels;
	int i;
        me=this_player();
        if(!wizardp(me)) return notify_fail("�A���O�Ův�C\n");
	if(TOPIC=="none")
	{
		if(stringp(chief=this_object()->query("meeting_chief"))) this_object()->delete("meeting_chief");
		return notify_fail("�ثe�èS���|ĳ�C\n");
	}
 	if(stringp(chief=this_object()->query("meeting_chief")) && chief != me->query("id"))
 	{
 		if(leader=present(chief,this_object()) ) return notify_fail("�u���ثe�|ĳ���۶��H"+leader->name()+"("+chief+")�~�൲���|ĳ!\n");
 		else 
 		{
 			message_vision("���Ѥp�j�ŧG: �ѩ�D���� "+chief+" ���}�F, �ҥH�|ĳ�Q�������o!!\n",me);
 		}
 	}
 	message_vision(YEL"$N�ﯵ�ѻ�: �|ĳ�������U�ӤF��? �n�a�A���򤵤Ѫ��|ĳ�N�즹�����C\n"+HIW+"�|ĳ���Ѱ�������: "+TOPIC+"�|ĳ�����A���¤j�a���Ѥ�!\n"NOR,this_player());
        this_object()->delete("meeting_chief");
        log_file("meeting/"+TOPIC,sprintf(HIW"%s(%s)�ŧG�����|ĳ(%s)�C\n"NOR,
	me->query("name"),me->query("id"),TOPIC));
 	log_file("static/MEETING",
  	sprintf( "%s(%s)�����|ĳ "HIC+TOPIC+NOR"�C [%s]\n",me->name(1), geteuid(me), ctime(time()) ) );
        TOPIC ="none";
        members= all_inventory(this_object());
	for(i=0;i<sizeof(members);i++)
	{
		if(channels=members[i]->query_temp("channels"))
		{
			members[i]->set("channels", channels);
			members[i]->delete_temp("channels");
		}
		members[i]->delete("env/auto_reply");
	}
	this_object()->delete("kickouts");
	this_object()->delete("silent");
	this_object()->delete("vote");
	this_object()->delete("vote_leader");
	this_object()->delete("vote_result");
	this_object()->delete("vote_member");
        return 1;
 }

int valid_leave(object me, string dir)
{
	string *channels;
        if( dir=="up" )
        {
        	if(me->query("id")==this_object()->query("meeting_chief") && TOPIC != "none") return notify_fail("�Х������|ĳ(over)�A���}!\n");
        	if(channels=me->query_temp("channels"))
        	{
        		me->set("channels",channels);
        		me->delete_temp("channels");
        		me->delete("env/auto_reply");
        	}
        	if(TOPIC!="none")
        	{
        	
        		log_file("meeting/"+TOPIC,sprintf(HIW"%s(%s)���}�|ĳ�C [%s]\n"NOR,
			this_player()->query("name"),this_player()->query("id"),ctime(time())));
		}
        }
        return ::valid_leave(me, dir);
}

void rush()
{
	tell_room(this_object(),YEL"�|ĳ���Ѥp�n����: �Фj�a���D�o��N���C\n"NOR);
	call_out("rush",300);
}
