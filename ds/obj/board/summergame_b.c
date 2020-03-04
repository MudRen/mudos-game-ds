/*
  Name: /obj/board/summergame_b.c
  Copyright: DS
  Author: Alickyuen
  Date: 12/09/05 00:54
  Description: 2005�����C���`�� 
*/

#include <ansi2.h>
#define PATH "/open/world1/alickyuen/2005summer/"

inherit ITEM;
inherit F_UNIQUE;
inherit F_SAVE;

mapping game_record;
int popc, pearlc, dollc, moneyc, eqc, rubbishc;
static string *drawing = ({ });
int reset_record();
int clear_list();
int set_record(string arg);
varargs mixed query_gift(string type);
string do_list();
varargs string query_record(string arg);

void create()
{
	set_name(HIM"�y2005�L������z�C���Ʀ�]"NOR, ({ "the list of game record", "record", "list" }) );
	set("no_get", 1);
	set("no_sac", 1);
	set("value", 0);
//	set("long", ""+this_object()->do_list()+"");
	set("long", " ");

	setup();
	if( !restore() )	game_record=([]);
	call_out("clear_list", 1800);
}

string query_save_file() 
{
	return DATA_DIR + "game/summer_game";
}

int clear_list()
{
	remove_call_out("clear_list");

	drawing = ({ });

	call_out("clear_list", 1800);

	return sizeof(drawing);
}

void init()
{
	object me = this_player();

	if( !me ) return;
	if( !userp(me) ) return; // �Y�S me �S�P�_userp���ܷ|�Xbug -alickyuen@ds-
	
	add_action("do_look", "look");
	add_action("do_draw", "draw");
}
	 
varargs int do_record(object me, int score)
{
	string id;

	if( !me || !objectp(me) ) return 3;

	if( !score || !intp(score) ) return 4;

	id=getuid(me);

	if( !previous_object() || file_name(previous_object()) != COMBAT_D ) return 2;

	if( undefinedp(game_record) ) game_record=([]);

	if( undefinedp(game_record[id]) ) game_record[id]=score;
	else game_record[id] += score;
	
	this_object()->save();
	return 1;
}

int set_record(string arg)
{
	string id;
	int score;

	if( this_player() 
		&& wizardp(this_player())
		&& wiz_level(this_player()) < wiz_level("(admin)") )
		return notify_fail("for admin only.\n");

	if( !mapp(game_record) ) game_record=([]);

	if( sscanf(arg, "%s to %d", id, score) !=2 ) return notify_fail("syntax: player to score\n");
	game_record[id]=score;
	this_object()->save();
	return 1;
}

int test(string arg)
{
	if( !wizardp(this_player()) || wiz_level(this_player()) < wiz_level("(admin)") )
		return notify_fail("for wiz only.\n");

	moneyc= 0;
	this_object()->save();
	return 1;
}

int reset_record()
{
	if( !wizardp(this_player()) || wiz_level(this_player()) < wiz_level("(admin)") )
		return notify_fail("for wiz only.\n");

//	game_record=([]);
	popc = 0;
	pearlc = 0;
	dollc = 0;
	moneyc = 0;
	eqc = 0;
	rubbishc = 0;

	this_object()->save();

	write("�M�������I\n");

	return 1;
}

int do_look(string arg)
{
	if ( arg == "list" || arg == "record" )
	{
/*		return write(@HELP
2005 �~�׳��Ŵ����S�O�C���`�ءСy�L������z�N��o�Ӫ��������������n���I

���ɤ���G
�@�@ 7 �� 9 �� (�P����) 00:00 �� 8 �� 31 �� (�P���T) 24:00 
(�H ds �� ���O date ���ɶ����ǳ�~~~~!!)

�C�����k�G
�@�@���k²��A�� mob �N�����I�� ���I��k�p�U:
�@�@(1) �Y���a���Ťj�� mob ����, �h�|�H���[ 0 ~ 1 �I
�@�@(2) �Y���a���Ťp�� mob ����, �h�|�H mob �� level �ȭp�� .. 4 level = 1 �I ��!!

�C�����~�G
�@�@�Y���W������o save eq �����|�A���L�ѥ[�̷�M�]���w����...�N�O�A�ѻP�L�{��
�Ȩ��������M�g��Ȱ� XD  ~~~ 

�U��[�o�V�O~

Alickyuen @ The Dream of Seven 2005 

HELP
+do_list()
*/
		return write(@HELP
2005 �~�׳��Ŵ����S�O�C���`�ءСy�L������z�w���������A�h�¦U��ѻP�C

�U��S�o��j�������ɪ̥禳�ѥ[������|�A����ɶ����G
	2005 �~ 9 �� 13 �� - 2005 �~ 9 �� 30 ��

������~�״I�A������o[ ���O: draw ]�A�{���٥��Q��줧���~�]�A�G 

HELP
+query_gift()
+query_record()
		);
	}
}

int do_draw(string arg)
{
	int chance = random(1000); // almost 1000 drawing chances
	string id = geteuid(this_player());
	return notify_fail("[2005 �L�����] ������ʤw�g�����A���~�N��y��{�o�C\n");
	restore();

	if( member_array(this_player()->query("id"), drawing) != -1 )
		return notify_fail(HIR"[2005 �L�����]"NOR YEL"�K�A���n�߫�ա�C�b�p�ɤ~�����@����I\n"NOR);

	if( id == "ayumi"
	|| id == "watch" 
	|| id == "bamboo" 
	|| id == "lemonlin"
	|| id == "opek" )
		return notify_fail(HIR"[2005 �L�����]"NOR" ���ߧA�A�A�O Save EQ �j���o���̡I\n");

	if( to_int(query_record(this_player()->query("id"))) < 100 )
		return notify_fail(HIR"[2005 �L�����]"NOR"�A�w�g�Χ��Ҧ�������|�F~~! \n"NOR);

	set_record(this_player()->query("id")+" to "+
		(to_int(query_record(this_player()->query("id")))-100));

	drawing += ({ this_player()->query("id") });

//	popc, pearlc, dollc, moneyc, eqc, rubbishc;
	switch(chance)
	{
		case 333:
			if( query_gift("paper") )
			{
				if( eqc <= 0 ) eqc = 1;
				else eqc += 1;
				rm(PATH+"eq"+(eqc<10?"0"+eqc:""+eqc));
				log_file("area/2005summer", this_player()->short(1)+"�⤤ paper. \n");
				write(HIR"[2005 �L�����]"BLINK HIY"���ߧA! �A�⤤�F�կ�~~! \n"NOR); 
				this_object()->save();
				break;
			}
		case 222..223:
			if( query_gift("pearl") )
			{
				if( pearlc <= 0 ) pearlc = 1;
				else pearlc += 1;
				rm(PATH+"pearl"+(pearlc<10?"0"+pearlc:""+pearlc));
				log_file("area/2005summer", this_player()->short(1)+"�⤤ pearl. \n");
				write(HIR"[2005 �L�����]"BLINK HIY"���ߧA! �A�⤤�F�å���~~! \n"NOR); 
				this_object()->save();
				break;
			}
		case 111..113:
			if( query_gift("doll") )
			{
				if( dollc <= 0 ) dollc = 1;
				else dollc += 1;
				rm(PATH+"doll"+(dollc<10?"0"+dollc:""+dollc));
				log_file("area/2005summer", this_player()->short(1)+"�⤤ doll. \n");
				write(HIR"[2005 �L�����]"BLINK HIY"���ߧA! �A�⤤�F��������~~! \n"NOR); 
				this_object()->save();
				break;
			}
		case 101..110:
			if( query_gift("rubbish") )
			{
				if( rubbishc <= 0 ) rubbishc = 1;
				else rubbishc += 1;
				rm(PATH+"rubbish"+(rubbishc<10?"0"+rubbishc:""+rubbishc));
				log_file("area/2005summer", this_player()->short(1)+"�⤤ rubbish. \n");
				write(HIR"[2005 �L�����]"BLINK HIY"���ߧA! �A�⤤�F�v����~~! \n"NOR); 
				this_object()->save();
				break;
			}
		case 401..500:
			if( query_gift("pop") )
			{
				if( popc <= 0 ) popc = 1;
				else popc += 1;
				rm(PATH+"pop"+(popc<10?"0"+popc:""+popc));
				log_file("area/2005summer", this_player()->short(1)+"�⤤ pop. \n");
				write(HIR"[2005 �L�����]"BLINK HIY"���ߧA! �A�⤤�F�n���~~! \n"NOR); 
				this_object()->save();
				break;
			}
		case 501..700:
			if( query_gift("money") )
			{
				if( moneyc <= 0 ) moneyc = 1;
				else moneyc += 1;
				rm(PATH+"money"+(moneyc<10?"0"+moneyc:""+moneyc));
				log_file("area/2005summer", this_player()->short(1)+"�⤤ money. \n");
				write(HIR"[2005 �L�����]"BLINK HIY"���ߧA! �A�⤤�F������~~! \n"NOR); 
				this_object()->save();
				break;
			}
		default:
				write(HIR"[2005 �L�����] �O�Ǥ�~!! ���M�A�o���èS���⤤����F��~~.. \n"NOR); 
			break;
	}	
	
	return 1;
}

varargs mixed query_gift(string type)
{
	mixed *file;
	int i;
	int pop, pearl, doll, money, eq, rubbish;
	string *gifts;
        
	file = get_dir(PATH, -1); 
	gifts = ({ });

	for(i = 0; i < sizeof(file); i++)
	{
		gifts += ({ file[i][0] });
	}

	pop = 0;
	pearl = 0;
	doll = 0;
	money = 0;
	eq = 0;
	rubbish = 0;

	foreach(string id in gifts)
	{
		if( sscanf(id, "pop%d", i) == 1 )
			pop += 1;
		else if( sscanf(id, "pearl%d", i) == 1 )
			pearl += 1;
		else if( sscanf(id, "doll%d", i) == 1 )
			doll += 1;
		else if( sscanf(id, "money%d", i) == 1 )
			money += 1;
		else if( sscanf(id, "eq%d", i) == 1 )
			eq += 1;
		else if( sscanf(id, "rubbish%d", i) == 1 )
			rubbish += 1;	
	}

	if( type ) switch(type) {
		case "pop" : return pop;
		case "money" : return money;
		case "doll" : return doll;
		case "rubbish" : return rubbish;
		case "paper" : return eq;
		case "pearl" : return pearl;
		default: return "none";
	}

	return HIC"\t SAVE EQ - �կ�(white paper) "NOR": "+ eq +" �� (�@ 1 ��)\n"
		+ HIC"\t SAVE EQ - �å���(fluorescent stick)"NOR" : "+ pearl +" �� (�@ 2 ��)\n"
		+ HIC"\t SAVE EQ - ��������(death doll)"NOR" : "+ doll +" �� (�@ 3 ��)\n"
		+ HIC"\t SAVE EQ - �v����(doll) "NOR": "+ rubbish +" �� (�@ 10 ��)\n"
		+ HIC"\t �n���  - �n�� 250 �I "NOR": "+ pop +" �� (�@ 100 ��)\n"
		+ HIC"\t ������  - �j�� 10000 �T "NOR": "+ money +" �� (�@ 200 ��)\n\n";
}

varargs string query_record(string arg)
{
	object me;
	string id;

	restore();

	if( !game_record )		return "�ثe�٨S����������I\n";
	if( !mapp(game_record) )	return "�ثe�٨S����������I\n";

	me = this_player();
	if( !arg ) id = geteuid(me);
	else id = arg;

	if( id == "ayumi"
	|| id == "watch" 
	|| id == "bamboo" 
	|| id == "lemonlin"
	|| id == "opek" )
		return HIR"[2005 �L�����]"NOR" ���ߧA�A�A�O Save EQ �j���o���̡I\n";
	
	if( arg ) return game_record[id];

	if( game_record[id] >= 100 )
		return HIR"[2005 �L�����]"NOR" �A�ثe�٦� "+game_record[id]/100+" ��������|�C\n";

	return HIR"[2005 �L�����]"NOR" �h�§A�ѻP�O�����ʡC\n";
}

string do_list()
{
	float *score, swap;
	int i, j, x;
	int flag;
	string *ppl, msg, user;

	restore();
	
	if( !game_record )		return "�ثe�٨S����������I\n";
	if( !mapp(game_record) )	return "�ثe�٨S����������I\n";

	ppl=keys(game_record);
	score=values(game_record);

	i=sizeof(score);

	for(j=i-1;j>0;j--)
	{
		for(x=1;x<=j;x++)
		{
			if( score[x-1] > score[x] )
			{
				swap=score[x-1];
				score[x-1]=score[x];
				score[x]=swap;
				user=ppl[x-1];
				ppl[x-1]=ppl[x];
				ppl[x]=user;
			}
		}
	}
	i=sizeof(ppl);
	j=0;
	msg= HIW"--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--\n"NOR;
	msg += HIY"\t\t\t������"HIR"�y2005�L������z"HIY"���ƱƦ�](1-25�W)��\n";
	msg+=HIW"--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--\n"NOR;

	if( !i ) msg += "\t\t\t\t\t�ȵL����\n"; 
	
	while( i-- )
// && j < 25 ) 
	{
		j++;

		if( ppl[i]==getuid(this_player()) ) 
		{ msg += HIC; flag = 1; }
			else msg += CYN;

		if( game_record[ppl[i]] > 0 ) {
			msg+=sprintf("��%4d�W ---- %13s �ثe�@ %5d �I�o��",
				j,ppl[i],game_record[ppl[i]]);

			switch( j )
			{
				case 1: msg+= HIM""BLINK" (�W�Ťj���G�ۭq Save Eq �@��)"; break;
				case 2..5: msg+= HIY" (�j���G�j�|���w Save Eq �@��)"; break;
				default:
					if( game_record[ppl[i]] >= 100 ) msg+= HIW" ("+game_record[ppl[i]]/100+" ��������|)";
					break;
			}
			msg += "\n"NOR;
		}
	}
	if( !flag && game_record[getuid(this_player())] > 0 ) 
	{
		msg+=sprintf(HIC"��%|4s�W ---- %13s �ثe�@ %5d �I�o��",
		"n",geteuid(this_player()),game_record[geteuid(this_player())]);
		msg += "\n"NOR;
	}
         
	msg+=HIW"--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--\n"NOR;

	return msg;
}
