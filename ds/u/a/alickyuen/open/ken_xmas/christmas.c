// �ק�wilfred��npc by kkeenn@ds 
// Rewrite by -alickyuen@ds-

#include <ansi2.h>

inherit NPC;
inherit F_SAVE;

mapping areas = ([ /* sizeof == 14 */
	"/open/world1/acme/area/" : "�ѫ�",
	"/open/world1/acme/bonze/" : "�ⶳ�x",
	"/open/world1/acme/cominging/" : "�ѫ��j�c",
	"/open/world1/cominging/area/" : "�B�F��",
	"/open/world1/cominging/purple_sun/" : "�����s",
	"/open/world1/ground_temple/" : "�a�U����",
	"/open/world1/linjack/emperor/" : "�|�j�s�P��",
	"/open/world1/moonhide/area/" : "�Ѭ�",
	"/open/world1/sdo/nonhero/" : "�L�W�^������",
	"/open/world1/tmr/area/" : "�ɿ�",
	"/open/world1/tmr/ghost-forest/" : "���_�˪L",
	"/open/world1/wilfred/sand/" : "���F��",
	"/open/world1/wilfred/meadow/" : "�������",
	"/open/world1/wu_sha_town/" : "�L�F��",
	// area����W�٥�sdo����.
]);

mapping game_record;
int record(string id);
int find_place();
int move_place();
int check();
string quest();
string report();
string checkdest();
void restart(int type);
string gogo();

string query_save_file()
{
	return DATA_DIR+"game/ken_xmas";
}

void create()
{
	set_name("�t�ϦѤH", ({ "christmas-man", "man" }));
	set("gender", "�k��" );
	set("long",@LONG
�o�N�O�ǻ����C�ϦѤ���, �L�u�|�b�Y�ǯS�w��l�X�{
�ʦ~���o�@����~~:P
LONG
);      
	set("age",1200);
	set("no_kill",1);
	set("race","human");
	set("level", 80);
	set("max_hp", 12000);

	set("chat_chance", 60);
	set("chat_msg", ({
		(: random_move :),
		(: random_move :),
		(: random_move :),
		(: random_move :),
		(: random_move :),
		(: random_move :),
	}));

	set("talk_reply", "�ڰg���F�I...\n");

	set("can_speak", 1);
	set("inquiry", ([
		"�g��" : (: gogo :),
		"�R��" : (: report :),
		"�ت��a" : (: checkdest :),
	]));

	setup();
	set_living_name("ken_xmas");
//	set_heart_beat(30);

//	call_out("move_place", 10);
/*
	set_temp("helping", 0); // ���U�����a��ID
	set_temp("dest_dir", 0); // �ت��a�ؿ��W��
	set_temp("destination", 0); // �ت��a�ɮצW��
*/
}

void init()
{
/*
	object me = this_player();

	if( !me) return;
	if( !userp(me) ) return;

	record(me->query("id"));
*/
}

void relay_say(object me,string word)
{
	if( word == "�R��")
		write("�C�ϦѤH���R"+report()+"");
	if( word == "�g��")
		write("�C�ϦѤH���R"+gogo()+"");
	if( word == "�ت��a")
		write("�C�ϦѤH���R"+checkdest()+"");

	return;	
}

int find_place()
{
	string *file, dest_dir, test;

	dest_dir = keys(areas)[random(sizeof(keys(areas)))];
	file = get_dir(dest_dir);
	test = dest_dir+file[random(sizeof(file))];

	if( !objectp(load_object(test)) || !load_object(test)->query("short") )
	{
		return find_place();
	}

	this_object()->set_temp("dest_dir", dest_dir);
	this_object()->set_temp("destination", test);

	call_out("find_place", 600); // �C10�����ഫ�ت��a

	return 1;
}	

int move_place()
{
	string *file, dest_dir;
	string room;

	dest_dir = keys(areas)[random(sizeof(keys(areas)))];
	file = get_dir(dest_dir);
	room = dest_dir+file[random(sizeof(file))];

        if( !objectp(load_object(room)) ) 
	{
		move_place();
		return 1;
	}
        if( !load_object(room)->is_room() ) 
	{
		move_place();
		return 1;
	}

	if( this_object()->move(room) )
	{
//		command("game* help!");
                command("tchat �ڦb["+values(areas)[member_array(dest_dir , keys(areas))]+"]���g���F:( (**�C���̫��1��14��**)");
//		command("game �ڲ{�b�g���F�A�֨ӱϧڧr���(���k�Ԩ�help christmas)");

		call_out("move_place", 300); // �C5�����ഫ�a��

		return 1;
	} else {
		move_place();

		return 1;
	}
}	

string quest()
{
	object me, man, place;
	int num;

	me = this_player();
	man = this_object();

	if( man->query_temp("helping") )
		return "�¹L�F�A�{�����H���ڱa�����F�G�^\n";

	if( !man->query_temp("destination") )
		find_place();

	place = load_object(man->query_temp("destination"));
	num = member_array(man->query_temp("dest_dir"), keys(areas));

	if( num == -1 || !place )
		return "�x�H�ںƤF�C�A�Ч�u�W�Ův������v�@�U�a���\n";

	command("follow "+me->query("id"));
	command("bow "+me->query("id"));

	remove_call_out("move_place");
	remove_call_out("find_place");
	remove_call_out("restart");
	call_out("restart", 300, 2);

	this_object()->set_temp("helping", me->query("id"));
	this_object()->set("chat_msg", ({
		"�C�ϦѤH�C�Y�ݬݤ�W���W��, �@�y��M����C\n",
		(: command("say �_�ǡA�ګ��|�g���F�O...") :),
		(: command("hmm") :),
		(: command("help!") :),
	}));

	return "�ڷQ�h"+HIY"�y"+values(areas)[num]+HIY"�z"NOR+"��"+HIY"�y"+place->query("short")+HIY"�z"NOR+"�A�·ЧA�a�ڥh�@�U�a�C\n"NOR;
}

string checkdest()
{
	if( !check() )
		return "�o�̤��O�ڷQ�h���a��...\n";
}

int record(string id)
{
	if( !restore() )
		game_record = ([]);
	if( !game_record )
		game_record = ([]);

	game_record[id] += 1;

	this_object()->save();

	command("say �ګD�`�P�E�A�����U�A�i���A���R�ߪ��H�C");
	command("say �ڷ|��A���R�߰O���U�ӡA���¤@��ڷ|�^�ӽ�A���~�A�խY�A���~��W�[�A���R��...");

	restart(1);
	return 1;
}

void restart(int type)
{
	if( type == 1 )
	{
		command("say �ɭԤ����F�A�ڭn�~��W���F�C\n");
		command("wave");
	}
	if( type == 2 )
	{
		command("say �A�ӺC�F�A�ڬ��٬O��ĤG�ӤH���ڱa���a�C\n");
		command("wave");
	}

	this_object()->delete_temp("helping");
	this_object()->delete_temp("dest_dir");
	this_object()->delete_temp("destination");
	this_object()->delete_temp("okay");

	move_place();

	return;
}

int check()
{
	object helper;

	if( this_object()->query_temp("helping") )
	{
		if( !objectp(helper = present(this_object()->query_temp("helping"), environment(this_object()))) )
		{
			this_object()->add_temp("noone", 1);
			return 1;
		}
		else if( !userp(helper) ) // �P�_�O�_���a,�H�����a��obj id�ۦP.
		{
			this_object()->add_temp("noone", 1);
			return 1;
		}
	}		
	if( file_name(environment(this_object()))+".c" == this_object()->query_temp("destination") )
	{
 		record(this_object()->query_temp("helping"));
		return 1;
	}
	return 0;
}
/*
void heart_beat()
{
	check();
}
*/
string report()
{
	float *score, swap;
	int i, j, x;
	string *ppl, msg, user;

	if( !restore() )
		game_record = ([]);
	if( !game_record )
		return "�ثe�٨S������H���R�߭C�I\n";
	if( !mapp(game_record) )
		return "�ثe�٨S������H���R�߭C�I\n";

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
	msg= HIW"\n\n--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--\n"NOR;
	msg += HIG"\t\t�����������s�~�S�O���ʡy���U�g���t�ϦѤH�z�R�߱Ʀ�]��\n";
	msg+=HIW"--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--\n"NOR;
	while( i-- )
	{
		j++;

		if( ppl[i]==getuid(this_player()) ) msg+= HIC;
			else msg += CYN;

		if( game_record[ppl[i]] > 0 ) {
			msg+=sprintf("��%4s�W ---- %13s �R�߫��ơG%3d �I",
				chinese_number(j),ppl[i],game_record[ppl[i]]);

			switch( j )
			{
				case 1: msg+= HIM""BLINK" (�R�߯S���G�W�W�H�󡮦ۭq�ä[�� Save Eq �@��)\n"; break;
				case 2..3: msg+= HIY" (�R�ߤj���G�ä[�� Save Eq �@��)\n"; break;
				default: msg+= HIR" (�R�߼��G�Χ��Y�� Save Eq �@��)\n"; break;
                		}
		}

		msg+=NOR;
	}       
	msg+=HIW"--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--\n"NOR;

	return msg;
}

void start()
{	
	object helper;

	if( !objectp(helper = present(this_object()->query_temp("helping"), environment(this_object()))) )
	{
		move_place();
		find_place();
		this_object()->delete_temp("helping");
		this_object()->set("chat_msg", ({
			"�C�ϦѤH�C�Y�ݬݤ�W���W��, �@�y��M����C\n",
			(: random_move :),
			(: command("say �_�ǡA�ګ��|�g���F�O...") :),
			(: command("hmm") :),
			(: command("help!") :),
		}));
		return;
	}
	else if( !userp(helper) ) // �P�_�O�_���a,�H�����a��obj id�ۦP.
	{
		move_place();
		find_place();
		this_object()->delete_temp("helping");
		this_object()->set("chat_msg", ({
			"�C�ϦѤH�C�Y�ݬݤ�W���W��, �@�y��M����C\n",
			(: random_move :),
			(: command("say �_�ǡA�ګ��|�g���F�O...") :),
			(: command("hmm") :),
			(: command("help!") :),
		}));
		return;
	}


	return;
}

string gogo()
{
	if( this_object()->query_temp("okay") )
		return "????????";

	remove_call_out("move_place");
	call_out("record", 1, this_player()->query("id") );
	this_object()->set_temp("okay",1);

	return "�����ڪ�?!";
}

void delete_record(string id)
{
	if( !restore() ) game_record= ([]);
	game_record[id] = 0;
	this_object()->save();
	return;
	}
