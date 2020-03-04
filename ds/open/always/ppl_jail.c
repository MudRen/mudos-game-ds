// File : "/open/always/ppl_jail.c"
// Backup : "/open/always/ppl_jail.bak"
// Rewrote By -Alickyuen@DS- On 2001-11-05
// ���D���覡���u���l
// Last Modify : 2002�~05��13��

#include <ansi2.h>
#include <room.h>

inherit ROOM;
inherit F_SAVE;

void jail_time(object me, int num);

void create()
{
	set("short",HIM"�T����"NOR);
	set("long",@LONG

  �o�̬O�P�ڶ����s���ʺ��C�|�Ө�o�����O-- ��MUD���u�W�w���H�C
  �p�G�A�Q���I�X���A�̦n�M�Ův�t�X�^���@��²�檺���D�A�p�G�ۭ�
  ���ܩγ\�A�i�H��o��D��!!�U�A���n�@�ǡA�o�̪��u�ƬO�D�`���Y
  ���C��~~~�r~~~�r~~~~  �n�n�Ϭ٧a!!! �@�ߪ����ԧŮv���P�M�a!!

       �p�G�A�ݭn�ϴ��i�q���u�W�Ův�D�U�Х�wiz_help�j
       ������D�@�d�ߡi�Х� help guideline�j
       �d�ߦD�������}�i�Цۦ�� checkout �o���O�j[��s��]
��������������������������������������������������������������������
����s�p�U�G�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@��
���]���^Jail�令�i�H�ϥ�get�Bdrop�Binactive�Bsave�Bquit���O�C �@�@��
���]���^�o�b��������N�|�۰����u�A�p���o�b�A�Х�inactive���O�C�@�@��
��������������������������������������������������������������������

LONG
);

	set("light",1);
	set("valid_startroom", 1);
	setup();
	call_other("/obj/board/ppl_jail_b" , "???");
	call_out("help_reborn",1);
}

void init()
{
	object me;

	me = this_player();

	if( !me ) return;
	
	if( me->query("out_of_power") )
	{
		add_action("do_action", "", 1);
		call_out("go_out", 1, me);
		return;
	}

          if(wiz_level(me) >= wiz_level("(wizard)"))
	//��]�Ԩ�help guideline ����,�εo�{��wiz�é�H
	{
		tell_object(me,BLINK+HIC"\n�S�j����}�ǽХ�free <id>.*�o�˷|�M���Ҧ��Ǹo����!*\n\n"NOR);
		add_action("do_free", "free");
	} 
}

int do_action()
{
	if ( (string)query_verb() == "post" )
	{ return 0; }
        if ( (string)query_verb() == "help" )
        { return 0; }
	if ( (string)query_verb() == "discard" )
	{ return 0; }
	if ( (string)query_verb() == "followup" )
	{ return 0; }
	if ( (string)query_verb() == "inventory" )
	{ return 0; }
	if ( (string)query_verb() == "look" )
	{ return 0; }
	if ( (string)query_verb() == "say" )
	{ return 0; }
	if ( (string)query_verb() == "score" )
	{ return 0; }
	if ( (string)query_verb() == "save" )
	{ return 0; }
	// �s�WSAVE���O�ϥ�-alickyuen@ds-
	if ( (string)query_verb() == "quit" )
	{ return 0; }
	if ( (string)query_verb() == "get" )
	{ return 0; }
	if ( (string)query_verb() == "drop" )
	{ return 0; }
	// �s�Wget,drop by alick
	//�s�Wquit by -alick@ds- jail�ت��O����char,���K�X�{�_�umulti���p,
	if ( (string)query_verb() == "inactive" )
	{ return 0; }

	if ( (string)query_verb() == "checkout" )
	{
		call_out("go_out", 1, this_player());
		return 1;
	}
	if ( (string)query_verb() == "wiz_help" )
	{
		call_out("help_me",1,this_player());
		return 1;
	}

        write("Sorry, �b�c���٬O�w���I�n�C"NOR""WHT"�`�N: �b�o�̯�Ϊ����O�u��:\n  i, l, say, sc, post, read, discard, followup, get(NEW), drop(NEW), inactive(NEW), save(NEW), quit(NEW), wiz_help, checkout\n"NOR);
	return 1;
}

int help_me(object me)
{
	object *obs = users();
	object ob = this_object();
	int i;

	if(!ob || !me) return 1;

	if(!ob->query_temp("help_ok"))
	{
		write(HIR"Sorry, �o�ӫ��O�٭n�A���ǮɭԤ~��A�ΡC\n"NOR);
		return 1;
	}

	for(i=0;i<sizeof(obs);i++)
		if( wiz_level(obs[i]) > 2 ) tell_object(obs[i],BEEP""HIW"\n"+
			me->query("name")+"("+me->query("id")+")[���c��] �V�A�o�X�D�U�T���I�A���Ū��ܴN�L�h�ݬݬO���^�Ƨa�I\n\n"NOR);

		write(HIC"�D�U�T���v�g�o�X�h�F�A�ܩ�Ův�|���|�ӡA�N�n�ݧA���y�ƤF�C\n"NOR);
		ob->delete_temp("help_ok");
	return 1;
}

int do_free(string str)
{
	object who;

	if( !str ) return notify_fail("�A�n�����?\n");
          if(wiz_level(this_player()) < wiz_level("(wizard)")) return notify_fail("�A�v�������C\n");
	if( !objectp(who=present(str, this_object())) ) 
		return notify_fail("�A�n����֡H\n");
	message_vision(HIR"$N��$n���D���M�P�F�I\n"NOR, this_player(), who);
	
	who->delete("free_time");
	who->delete("no_free");
	call_out("go_out", 1, who);

	return 1;
}

void help_reborn()
{
	this_object()->set_temp("help_ok",1);
	remove_call_out("help_reborn");
	if(this_object()) call_out("help_reborn",300);
}

void jail_time(object me, int num)
{
	string time, month, date, hour;
	int free_time, jail_time, hr, day, mon, dy, times;

	time = ctime(time());
	month = time[4..6];
	date = time[8..9];
	hour = time[11..12];

	switch(month)
	{
		case "Jan" :
			month = "01";
			day = 31;
		break;
		case "Feb" :
			month = "02";
			day = 28;
		break;
		case "Mar" :
			month = "03";
			day = 31;
		break;
		case "Apr" :
			month = "04";
			day = 30;
		break;
		case "May" :
			month = "05";
			day = 31;
		break;
		case "Jun" :
			month = "06";
			day = 30;
		break;
		case "Jul" :
			month = "07";
			day = 31;
		break;
		case "Aug" :
			month = "08";
			day = 31;
		break;
		case "Sep" :
			month = "09";
			day = 30;
		break;
		case "Oct" :
			month = "10";
			day = 31;
		break;
		case "Nov" :
			month = "11";
			day = 30;
		break;
		case "Dec" :
			month = "12";
			day = 31;
		break;
		default:
		break;
	}

	switch(date)
	{
		case " 1" :
			date = "01";
		break;
		case " 2" :
			date = "02";
		break;
		case " 3" :
			date = "03";
		break;
		case " 4" :
			date = "04";
		break;
		case " 5" :
			date = "05";
		break;
		case " 6" :
			date = "06";
		break;
		case " 7" :
			date = "07";
		break;
		case " 8" :
			date = "08";
		break;
		case " 9" :
			date = "09";
		break;
		default:
		break;
	}

	free_time = to_int(month+date+hour);

	jail_time = 0;

	times = me->query("putjail_time/"+num);
	if( times > 6 ) me->set("no_free", 1);
	else	switch(num)
		{
/*			�D�@�]�w�����A�Ԩ�help guideline			*/

			case 1:	// multi
				if( !times ) jail_time = 24;			// 24*1
					else if( times >= 5 ) me->set("no_free", 1);
						else jail_time = 120;	// 24*5
			break;
			case 2:	// robot
				if( !times ) jail_time = 120;			// 24*5
					else if( times >= 5 ) me->set("no_free", 1);
						else jail_time = 240;	// 24*10
			break;
			case 3:	// bug
				if( !times ) jail_time = 48;			// 24*2
					else if( times >= 5 ) me->set("no_free", 1);
						else jail_time = 96;		// 24*4
			break;
			case 4:	// flood
				if( !times ) jail_time = 5;			// 5
					else if( times == 6 ) jail_time = 72;	// 24*3
						else jail_time = 24;		// 24*1
			break;
			case 5:	// foul
				if( !times ) jail_time = 8;			// 8
					else if( times == 6 ) jail_time = 144;	// 24*6
						else jail_time = 48;		// 24*2
			break;
			case 6:	// quest
				if( !times ) jail_time = 5;			// 5
					else if( times == 6 ) jail_time = 120;	// 24*5
						else jail_time = 24;		// 24*1
			break;
			case 7:	// other
				jail_time = 1;				// 1
			break;
	}

/*	free_time �榡��->mmddhh		*/
	free_time += jail_time;

	hr = (atoi(hour)+jail_time);
	mon = atoi(month);
	dy = atoi(date);

	while( hr >= 24 )
	{
		free_time -= 24;
		free_time += 100;
		hr -= 24;
		dy += 1;

		while( dy > day )
		{
			free_time -= (day*100);
			free_time += 10000;
			dy -= day;
			mon += 1;

			while( mon > 12 )
			{
				free_time -= 120000;
				mon -= 12;
			}	
		}
	}

	me->set("free_time", free_time);
	me->add("putjail_time/"+num, 1);

	return;
}

//int valid_leave(object me, string dir)
int go_out(object me)
{
	string time, month, date, hour, where;
	int now_time, putjail_time;
	object env;

	time = ctime(time());
	month = time[4..6];
	date = time[8..9];
	hour = time[11..12];

	switch(month)
	{
		case "Jan" :
			month = "01";
		break;
		case "Feb" :
			month = "02";
		break;
		case "Mar" :
			month = "03";
		break;
		case "Apr" :
			month = "04";
		break;
		case "May" :
			month = "05";
		break;
		case "Jun" :
			month = "06";
		break;
		case "Jul" :
			month = "07";
		break;
		case "Aug" :
			month = "08";
		break;
		case "Sep" :
			month = "09";
		break;
		case "Oct" :
			month = "10";
		break;
		case "Nov" :
			month = "11";
		break;
		case "Dec" :
			month = "12";
		break;
		default:
		break;
	}

	switch(date)
	{
		case " 1" :
			date = "01";
		break;
		case " 2" :
			date = "02";
		break;
		case " 3" :
			date = "03";
		break;
		case " 4" :
			date = "04";
		break;
		case " 5" :
			date = "05";
		break;
		case " 6" :
			date = "06";
		break;
		case " 7" :
			date = "07";
		break;
		case " 8" :
			date = "08";
		break;
		case " 9" :
			date = "09";
		break;
		default:
		break;
	}

	now_time = to_int(month+date+hour);
	putjail_time = me->query("free_time");

	if( me->query("no_free") ) 
	{
		tell_object(me, HIW"�A�Q�P�B���O�ר��ʸT�I���Ԥj���S�j�a�I\n"NOR);
		return 1;
	}

	if( ( now_time >= putjail_time ) || !putjail_time || ( ( putjail_time-now_time ) > 100000 ) )
	{
		message("system","\n\n   "+me->name(1)+"�X���F, �Ʊ�L���L�۷s, �U�����n�A�Ǫk�F�C\n\n",users());
		where = me->query("putjail_position");
		if(where) env = load_object(where);
		if( env && env != this_object() )
		{
			me->move(env);
		} else {
			me->move("/open/world2/anfernee/start/login");
		}
		me->delete_temp("out_of_power");
		me->delete("out_of_power");
		me->delete("putjail_position");
//                if( !putjail_time && me->query("putjail_time") ) me->delete("putjail_time", 1); 
		me->delete("free_time");
		me->set("startroom", file_name(environment(me)));
		me->save();
		return 1;
	} else {
		string number;
		number = ""+putjail_time+"";
                if( strlen(number) < 6 ) number = "0"+number;
                tell_object(me, HIW"�A���D���n��"+number[0..1]+"��"+number[2..3]+"��"+number[4..5]+"�ɤ~���I\n"NOR);
		return 1;
	}
}
