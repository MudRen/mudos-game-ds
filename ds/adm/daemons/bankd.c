/*	File : "/adm/daemons/bankd.c		*
 *	Author : -Alickyuen@DS-			*
 *	Desc : ���|�M�ݻȦ�,�s�������s��	*
 *	Last Modify : 19-11-2001		*/

#include <dbase.h>
#include <ansi2.h>
#define DATA_FILES DATA_DIR+"club_bank/"

inherit F_DBASE;
inherit F_SAVE;

mapping bank_amount, bank_record;

void interest_receive();
int do_save(string id, int world, int money, string name, string type);
int clear_data(string name, string id, string type);
int save_interest(string id, string log, string type);

void create()
{
        seteuid(getuid());

	set("channel_id", "���|�Ȧ�޲z���F(Bank elf)");
	set("club_id", "");

	if( !restore() )
	{
//		if( !bank_record )
			bank_record = ([]);
//		if( !bank_amount )
			bank_amount = ([]);
	}
}

string query_save_file() 
{
	return DATA_DIR+"club_bank/"+query("club_id");
}

int open_new(string id, string place)
{
	set("club_id", id);
	set("location", place);

	if( !restore() )
	{
			bank_record = ([]);
			bank_amount = ([]);
	}
	this_object()->save();

	return 1;
}

int do_save(string id, int world, int money, string name, string type)
{
	string log;

	set("club_id", id);

	if( !restore() )
	{
//		if( !bank_record )
			bank_record = ([]);
//		if( !bank_amount )
			bank_amount = ([]);
	}
	
	log = name+" �� "+ctime(time())+" "+type+" ";

	switch(world)
	{
		case 1:
			if( (money < 0) && ( bank_amount["past"] < (money*-1) ) )
				return 0;
			bank_amount["past"] += money;
			if( money < 0 ) money *= -1;
			log += money+" �T�ɪO�C\n"NOR;
		break;
 		case 2:
			if( (money < 0) && ( bank_amount["now"] < (money*-1) ) )
				return 0;
			bank_amount["now"] += money;
			if( money < 0 ) money *= -1;
			log += money+" ���{���C\n"NOR;
		break;
 		case 3:
			if( (money < 0) && ( bank_amount["future"] < (money*-1) ) )
				return 0;
			bank_amount["future"] += money;
			if( money < 0 ) money *= -1;
			log += money+" �I�q�l�����C\n"NOR;
		break;
 		default:
			return 0;
		break; 
	}

	CHANNEL_D->do_channel(this_object(), id, HIY+log+NOR);

	if( !bank_record[type] )	bank_record[type] = "";

	if( strlen(bank_record[type]) > 1200 )
		clear_data("�t��", id, type);

	if( !bank_record[type] )	bank_record[type] = "";

	bank_record[type] += (CYN"�@�@�@"+log);

	this_object()->save();
	
	return 1;
}

string get_bank_amount(string id)
{
	string msg;

	set("club_id", id);

	if( !restore() )
	{
//		if( !bank_record )
			bank_record = ([]);
//		if( !bank_amount )
			bank_amount = ([]);
	}

	msg = HIY"�@�@�Ȧ椺�@���s�ڡС@"+to_int(bank_amount["past"])+"�@�T�ɪO�C\n";
	msg += "�@�@�@�@�@�@�@�@�@�С@"+to_int(bank_amount["now"])+"�@���{���C\n";
	msg += "�@�@�@�@�@�@�@�@�@�С@"+to_int(bank_amount["future"])+"�@�I�q�l�����C\n\n"NOR;

	return msg;
}

string get_log(string id, string type)
{
	string log;

	set("club_id", id);

	if( !restore() )
	{
//		if( !bank_record )
			bank_record = ([]);
//		if( !bank_amount )
			bank_amount = ([]);
	}

	log = HIC"�@�@"+id+" �� "+type+" �O���G\n"NOR;

	if( !bank_record[type] || (strlen(bank_record[type]) < 1) )
	{
		log += CYN"�@�@�@���ȡ@�L�@�O�@����\n\n"NOR;
		return log;
	} else {
//		for(i=0;i<sizeof(bank_record[type]);i++)
//		{
//			log+= bank_record[type][i];
//		}
		log += bank_record[type];
		log += NOR;
//		if( strlen(log) > 1200 )
//			clear_data("�t��", id, type);
		return log;
	}
}

int clear_data(string name, string id, string type)
{
	set("club_id", id);
	if( !restore() )
	{
//		if( !bank_record )
			bank_record = ([]);
//		if( !bank_amount )
			bank_amount = ([]);
	}

	bank_record[type] = "";

	CHANNEL_D->do_channel(this_object(), id,
		HIY""+name+" �����|�Ȧ� "+type+" �O���M�����C"NOR);

	this_object()->save();

	(load_object(dbase["location"]))->create(); 

	return 1;
}


void interest_receive()
{
	mixed *file;
	string type, *clubs, log;
          int i, rdm, j, ratio;

	file = get_dir(DATA_FILES, -1); 
	clubs = ({ });

	for(i=0;i<sizeof(file);i++)
	{
		clubs += ({ replace_string(file[i][0], ".o", "") });
	}

	if( sizeof(clubs) )
	{ 
//		foreach(string id in clubs)
		for(j=0;j<sizeof(clubs);j++)
		{
			set("club_id", clubs[j]);
			rdm = random(8);

                        if( random(5) >= 2 ) // 0, 1, 2, 3, 4. 
			{
				ratio = rdm;
				type = "deposit";
			} else {
				ratio = (rdm * -1);
        				type = "withdraw";
			}

			if( !restore() )
			{
					bank_record = ([]);
					bank_amount = ([]);
			}
			log = HIW"����Q�v�� "+ratio+"% �I\n"NOR;
			save_interest(clubs[j], log, type);
			if( bank_amount["past"] ) do_save(clubs[j], 1, (bank_amount["past"] * ratio / 100), query("channel_id"), type);
			if( bank_amount["now"] ) do_save(clubs[j], 2, (bank_amount["now"] * ratio / 100), query("channel_id"), type);
			if( bank_amount["future"] ) do_save(clubs[j], 3, (bank_amount["future"] * ratio / 100), query("channel_id"), type);
			(load_object(dbase["location"]))->create();
		}		
	}

//	this_object()->save();

	return;
}

int save_interest(string id, string log, string type)
{
	set("club_id", id);

	if( !restore() )
	{
		bank_record = ([]);
		bank_amount = ([]);
	}
	CHANNEL_D->do_channel(this_object(), id, log);

	if( !bank_record[type] )	bank_record[type] = "";

	if( strlen(bank_record[type]) > 1200 )
		clear_data("�t��", id, type);

	if( !bank_record[type] )	bank_record[type] = "";

	bank_record[type] += ("�@�@�@"+log);

	this_object()->save();
	
	return 1;
}

string sort_list()
{
	mixed *file;
	string *clubs, log;
	int i, j, total;
	
	file = get_dir(DATA_FILES, -1); 
	clubs = ({ });

	for(i=0;i<sizeof(file);i++)
	{
		clubs += ({ replace_string(file[i][0], ".o", "") });
	}

	log = HIC"�ڤۤC�������겣�Ʀ�]�@(�j�N�ϲ{�N�ϥ��Ӹ겣)\n"NOR;
	log += HIR"==================================================================\n"NOR;

	if( sizeof(clubs) )
	{ 
		for(j=0;j<sizeof(clubs);j++)
		{
			set("club_id", clubs[j]);

			if( !restore() )
			{
					bank_record = ([]);
					bank_amount = ([]);
			}

			total = (bank_amount["past"] + bank_amount["now"] + bank_amount["future"]);
			log += sprintf(HIY"\n���|�y%|8s�z���`�겣���G%10d�I\n"NOR,
				clubs[j],
				total,
				);
		}		
	} else {
		log += HIY"\t\t\t�Ʀ�ɵo����~�A�Шϥ� report ���O�^���I\n"NOR;
	}

	log += HIR"\n==================================================================\n"NOR;

	return log;
}
