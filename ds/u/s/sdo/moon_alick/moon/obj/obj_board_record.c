/*	record.c			*
 *	write by -alickyuen@ds-		*
 *	�����{�������Ӧ�acme:p		*/

#include <ansi2.h>

inherit ITEM;
inherit F_SAVE;

mapping game_record;

int do_record(object me);
int reset_record();
string do_list();

void create()
{
	set_name(HIM"�y�O���v�v�z�C���Ʀ�]"NOR, ({ "the list of game record", "record", "list" }) );
	set("no_get", 1);
	set("no_sac", 1);
	set("value", 0);
//	set("long", ""+this_object()->do_list()+"");
	set("long", " ");

	setup();
	if( !restore() )	game_record=([]);
}

string query_save_file() 
{
	return DATA_DIR + "game/moon_question";
}

void init()
{
	object me = this_player();

	if( !me ) return;
	if( !userp(me) ) return; // �Y�S me �S�P�_userp���ܷ|�Xbug -alickyuen@ds-
	
//	do_record(me);
	
	add_action("do_look", "look");
//        add_action("set_record", "set");
}
	 
int do_record(object me)
{
	string id;
	id=getuid(me);

	if( !mapp(game_record) ) game_record=([]);

	game_record[id]=me->query("game/moon_question");
	this_object()->save();
	return 1;
}

int set_record(string arg)
{
	string id;
//	int score;

	if( !wizardp(this_player()) ) return notify_fail("wrong\n");

	if( !mapp(game_record) ) game_record=([]);

//	if( sscanf(arg, "%s to %s", id, score) !=2 ) return notify_fail("wrong\n");
	id = arg;
	game_record[id]=this_player()->query("game/moon_question");
	this_object()->save();
	return 1;
}

int reset_record()
{
	game_record=([]);
	this_object()->save();

	write("�M�������I\n");

	return 1;
}

int do_look(string arg)
{
	if ( arg == "list" || arg == "record" )
	{
		return write(do_list());
	}
}

string do_list()
{
	float *score, swap;
	int i, j, x;
	string *ppl, msg, user;

	if( !game_record )		return "�ثe�٦���������I\n";
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
	msg += HIG"\t\t\t������`�S�O���ʡy�O���v�v�z���ƱƦ�]��\n";
	msg+=HIW"--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--\n"NOR;
	while( i-- )
	{
		j++;

		if( ppl[i]==getuid(this_player()) ) msg+= HIC;
			else msg += CYN;

		if( game_record[ppl[i]] > 0 ) {
			msg+=sprintf("��%4s�W ---- %13s �ثe�@ %3d �I�o��",
				chinese_number(j),ppl[i],game_record[ppl[i]]);

			switch( j )
			{
				case 1: msg+= HIM""BLINK" (�W�Ťj���G�W�W�H�󡮦ۭq Save Eq �@��)\n"; break;
				case 2..5: msg+= HIY" (�j���G�H�� Save Eq �@��)\n"; break;
				default: msg+= HIR" (�ѥ[���G���BExp)\n"; break;
                		}
		}

		msg+=NOR;
	}       
	msg+=HIW"--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--\n"NOR;

	return msg;
}
