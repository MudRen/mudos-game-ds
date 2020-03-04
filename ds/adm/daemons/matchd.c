/*	File		: "/adm/daemons/matchd.c"	*
 *	Author		: "alickyuen@ds"		*
 *	Desc		: "�C��@����Z�j�|�D�t��"	*
 *	Last Modify	: "2002�~5��30��"		*/

#include <ansi2.h>

/*�@���Ӱϰ쪺�_�l�I�@*/
#define AREA_A "/open/world1/alickyuen/match/area-a/map_7_14.c"	// map_1_1
#define AREA_B "/open/world1/alickyuen/match/area-b/map_8_1.c"	// map_8_11
#define AREA_C "/open/world1/alickyuen/match/area-c/map_8_14.c"	// map_1_1
#define AREA_D "/open/world1/alickyuen/match/area-d/map_5_3.c"	// map_1_1
/*�@�J�f�ΥX�f�@*/
#define ENTER_ROOM "/open/world1/alickyuen/match/entrance.c"
#define EXIT_ROOM "/open/world1/alickyuen/match/exit.c"

#define DOLL "/open/world1/alickyuen/match/obj/doll.c"

inherit F_SAVE;
inherit F_DBASE;

mapping game_record;	// �O���ӧQ��
mapping game_list;	// �O�����W�W��
mapping play_list;	// �O����Z�����W��
int num1 = 0;		// �ʹ�S��TEAM A���H�i����Z
int num2 = 0;		// �ʹ�S��TEAM B���H�i����Z
int num3 = 0;		// �ʹ�S��TEAM C���H�i����Z
int num4 = 0;		// �ʹ�S��TEAM D���H�i����Z
int count1 = 0;		// �O�����WTEAM A���H��
int count2 = 0;		// �O�����WTEAM B���H��
int count3 = 0;		// �O�����WTEAM C���H��
int count4 = 0;		// �O�����WTEAM D���H��
int fail = 0;		// �@�o�O��
int show = 0;		// �O�����i����
int okay = 1;		// �аO���W���A
int reset_record();	// ���]���W�W��
string do_list();	// ���W�W��
void announce();	// ���i
int record(object me);	// �O���ӧQ
int enter(object me);	// �i�J��Z�ϰ�
int check(object me);	// �d����Z�i�檺�O��
int start();		// ��Z�}�l

void create()
{
	seteuid(getuid());
	set("name", "���ɺ��F");
	set("id", "matchd");

	if( !restore() )
	{
		if( !game_record )
			game_record = ([]);
		if( !game_list )
			game_list = ([]);
		if( !play_list )
		{
			play_list = ([]);
			play_list["A"] = ({});
			play_list["B"] = ({});
			play_list["C"] = ({});
			play_list["D"] = ({});
		}
	}
}

string query_save_file() 
{
	return DATA_DIR + "game/monthly_pk";
}

int sign_list(string team)
{
	object me;
	string id;
	int group, no = 0;

	me = this_player();

//	if( wiz_level(me) < wiz_level("(admin)") ) 
//		return notify_fail("�Ův����ѥ[�O�����ɡC\n");

	if( okay != 1 )
                return notify_fail(HIR"�{�b�w�g��������W�A���W�ɶ��O�C�餧���W�Q�G�ɥ��ܱߤW�C�ɥ��C\n"NOR);

	if( team !="A" && team !="B" && team !="C" && team !="D" )
		return notify_fail("�A�n�[�J���@�հ��ɡH�]A�BB�BC�BD�H�^\n");

	if( !restore() )
	{
		if( !game_record )
			game_record = ([]);
		if( !game_list )
			game_list = ([]);
		if( !play_list )
		{
			play_list = ([]);
			play_list["A"] = ({});
			play_list["B"] = ({});
			play_list["C"] = ({});
			play_list["D"] = ({});
		}
	}

	switch(team)
	{
		case "A":
			if( count1 >= 10 ) 
				return notify_fail(team+"�դw�g���B�F�A�г��@�L�էO�a�C\n");
			else count1 += 1;
		break;
		case "B":
			if( count2 >= 10 ) 
				return notify_fail(team+"�դw�g���B�F�A�г��@�L�էO�a�C\n");
			else count2 += 1;
		break;
		case "C":
			if( count3 >= 10 ) 
				return notify_fail(team+"�դw�g���B�F�A�г��@�L�էO�a�C\n");
			else count3 += 1;
		break;
		case "D":
			if( count4 >= 10 ) 
				return notify_fail(team+"�դw�g���B�F�A�г��@�L�էO�a�C\n");
			else count4 += 1;
		break;
		default:
			return notify_fail("�o�Ϳ��~�I�лP�ŮvAlickyuen�p����Report�C\n");
		break;	
	}

	id = me->query("id");

	if( game_list[id] ) 
		return notify_fail("�A�w�g���W�F�C\n");

	game_list[id] = team;

	this_object()->save();

	message_vision(HIW"$N�g�F�y"+id+"�z�b�O�W�����W��W�C\n"NOR, me);

	return 1;
}

int reset_record()
{
/*
	if( wiz_level(this_player()) < wiz_level("(admin)") )
		return notify_fail("�A���Ův���Ť����C\n");
*/

	game_list = ([]);
	play_list = ([]);
	play_list["A"] = ({});
	play_list["B"] = ({});
	play_list["C"] = ({});
	play_list["D"] = ({});
	num1 = 0;
	num2 = 0;
	num3 = 0;
	num4 = 0;
	count1 = 0;
	count2 = 0;
	count3 = 0;
	count4 = 0;	
	fail = 0;

	this_object()->save();

	write(HIW"���ɪ̦W��M�������I\n"NOR);

	return 1;
}

string do_list()
{
	float *team;
	string *ppl, msg;
	string team1, team2, team3, team4;
	int i;

	if( !restore() )
	{
		if( !game_record )
			game_record = ([]);
		if( !game_list )
			game_list = ([]);
		if( !play_list )
		{
			play_list = ([]);
			play_list["A"] = ({});
			play_list["B"] = ({});
			play_list["C"] = ({});
			play_list["D"] = ({});
		}
	}

	msg = HIW"--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--\n"NOR;
	msg += HIG"\t\t\t���y�ڤۤ�Z�j�|�z���ɪ̻P�βէO�W�桸\n";
	msg +=HIW"--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--\n"NOR;

	if( !game_list )		
	{
		msg += HIY"��ثe�٨S�����󪱮a���W�A�бq�t�Ρysign�z���O�ѥ[��\n"NOR;
	} else if( !mapp(game_list) ) {
		msg += "�S����������A�ЦV�����Ův�^���C\n";
	} else {
		ppl = keys(game_list);
		team = values(game_list);
		team1 = HIC"�ϲզW��G"NOR;
		team2 = HIC"�вզW��G"NOR;
		team3 = HIC"�ѲզW��G"NOR;
		team4 = HIC"�ҲզW��G"NOR;

		for(i=0;i<sizeof(ppl);i++)
		{
			switch(team[i])
			{
				case "A":
					team1 += CYN""+ppl[i]+"�A";
				break;
				case "B":
					team2 += CYN""+ppl[i]+"�A";
				break;
				case "C":
					team3 += CYN""+ppl[i]+"�A";
				break;
				case "D":
					team4 += CYN""+ppl[i]+"�A";
				break;
				default:
				break;
			}
		}
		msg += team1+"\n"NOR+team2+"\n"NOR+team3+"\n"NOR+team4+"\n"NOR;
	}       
	msg += HIW"--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--\n"NOR;

	return msg;
}

void announce()
{
        string msg, time, date, hour;

	time = ctime(time());
	date = time[8..9];
	hour = time[11..12];
      return; // �Ȯ����� add by tmr 2006/11/07

//        if( to_int(date) == 5 )
/*
        if( to_int(hour) == 20 )
	{
		msg = HIW"\n�i�ڤۤC���Z�j�|�j�ЦU���ɪ̷Ǯɦb���ѤU�Ȣ����ɥ��b��Z���J�f���X�C\n\n"NOR;
		okay = 0;
	} else
*/
	if( to_int(hour) < 24 && to_int(hour) >= 20 )
	{
		okay = 2;
		return;
	}
//        if( to_int(date) < 5 && to_int(date) > 2 ) 
        if( to_int(hour) > 18 )
	{
                msg = BEEP+HIW"\n�i�ڤۤC���Z�j�|�j�N��U�ȤK���|��A�ЦU���ɪ̩�K�ɫe��F��Z���J�f�A�j�|�N�|�ھ�date�ɶ��Ǯɩ�K�ɶ}�l�C\n\n"NOR;
//                msg = HIW"\n�i�ڤۤC���Z�j�|�j�{�w��������W�A���ɱN��C�뤧�Ĥ����|��C\n\n"NOR;
		okay = 2;
	} else 	{
		msg = HIW"\n�i�ڤۤC���Z�j�|�j�{�w�������W�A�бq�t���Z���n�O�C\n\n"NOR;
		okay = 1;
	}

	message("system", msg, users());

	this_object()->save();

	return;
}

int enter(object me)
{
	string id, *area, *list;
	object room;

	id = me->query("id");

	if( !restore() )
	{
		if( !game_record )
			game_record = ([]);
		if( !game_list )
			game_list = ([]);
		if( !play_list )
		{
			play_list = ([]);
			play_list["A"] = ({});
			play_list["B"] = ({});
			play_list["C"] = ({});
			play_list["D"] = ({});
		}
	}

	if( !game_list[id] )
		return notify_fail("�A�ä��O�o����Z�j�|�����ɪ̡C\n");

	if( sizeof(play_list[(game_list[id])]) < 1 )
	{
		play_list[(game_list[id])] = ({ id });
	} else {
		play_list[(game_list[id])] += ({ id });
	}

	area = game_list[id];

	switch(area)
	{
		case "A":
			room = load_object(AREA_A);
			num1 = 1;
		break;
		case "B":
			room = load_object(AREA_B);
			num2 = 1;
		break;
		case "C":
			room = load_object(AREA_C);
			num3 = 1;
		break;
		case "D":
			room = load_object(AREA_D);
			num4 = 1;
		break;
		default:
		break;
	}
/*
	tell_object(me, HIC"�u�@�H���o�t�F�@�������������A�C\n"NOR);

	new(DOLL)->move(me);
*/
	me->move(room);

	me->set_temp("match_player", 1);

	this_object()->save();

	return 1;
}

int check(object me)
{
	string id, win;
	int noa, nob, noc, nod;

	if( !restore() )
	{
		if( !game_record )
			game_record = ([]);
		if( !game_list )
			game_list = ([]);
		if( !play_list )
		{
			play_list = ([]);
			play_list["A"] = ({});
			play_list["B"] = ({});
			play_list["C"] = ({});
			play_list["D"] = ({});
		}
	}

	id = me->query("id");

//	map_delete(play_list, id);

	play_list["A"] -= ({ id });
	play_list["B"] -= ({ id });
	play_list["C"] -= ({ id });
	play_list["D"] -= ({ id });

	me->delete_temp("match_player");

	if( sizeof(play_list["A"]) ) 
	{	
		noa = 1;
		win = "A";
	}
	else noa = 0;

	if( sizeof(play_list["B"]) ) 
	{
		nob = 1;
		win = "B";
	}
	else nob = 0;

	if( sizeof(play_list["C"]) )
	{
		noc = 1;
		win = "C";
	}
	else noc = 0;

	if( sizeof(play_list["D"]) )
	{
		nod = 1;
		win = "D";
	}
	else nod = 0;

	if( (noa+nob+noc+nod) == 1 )
	{
		foreach(string ppl in play_list[win])
		{
			if( !fail )	find_player(ppl)->set_temp("match_winner", 1);
			if( file_name(environment(find_player(ppl))) != EXIT_ROOM )
			{
				find_player(ppl)->move(EXIT_ROOM);
			}
		}
		if( !fail && !show )
		{
			message("system", HIW"\n�i�ڤۤC���Z�j�|�j��Z�{�w�����A�h�¦U����ɪ̿��D����C\n\n"NOR, users());
			show = 1;
		}
		this_object()->reset_record();
	}

	this_object()->save();

	return 1;
}

int record(object me)
{
	string time, date;

	if( !restore() )
	{
		if( !game_record )
			game_record = ([]);
		if( !game_list )
			game_list = ([]);
		if( !play_list )
		{
			play_list = ([]);
			play_list["A"] = ({});
			play_list["B"] = ({});
			play_list["C"] = ({});
			play_list["D"] = ({});
		}
	}

	time = ctime(time());

	date = time[4..6]+"-"+time[8..9]+"-"+time[20..23];
	
	if( !game_record[date] ) game_record[date] = ({ });
	game_record[date] += ({ me->query("id") });	

	me->delete_temp("match_winner");

	message("system", HIW"�i"HIG"��Z�q�i"HIW"�j"HIG""+me->query("name")+NOR HIG"("+me->query("id")+HIG")�b�o����Z���ӥX�F�I\n\n"NOR, users());


	this_object()->save();

	return 1;
}

int start()
{
	load_object(ENTER_ROOM)->start_game();

	message("system", HIW"\n�i�ڤۤC���Z�j�|�j�{�b�}�l�I�I�I\n\n"NOR, users());

	show = 0;
	fail = 0;

	if( (num1+num2+num3+num4) == 1 )
	{
		string *list;

		list = play_list["A"]+play_list["B"]+play_list["C"]+play_list["D"];

		fail = 1;

		foreach(string ppl in list)
		{
			if( file_name(environment(find_player(ppl))) != EXIT_ROOM )
			{
				find_player(ppl)->move(EXIT_ROOM);
			}
		}
                this_object()->reset_record();
		message("system", HIW"\n�i�ڤۤC���Z�j�|�j�ѩ�H�Ƥ����A������Z�j�|�@�o�C\n\n"NOR, users());
	}
	this_object()->save();
}
