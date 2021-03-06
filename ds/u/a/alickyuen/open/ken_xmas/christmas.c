// 修改wilfred的npc by kkeenn@ds 
// Rewrite by -alickyuen@ds-

#include <ansi2.h>

inherit NPC;
inherit F_SAVE;

mapping areas = ([ /* sizeof == 14 */
	"/open/world1/acme/area/" : "天城",
	"/open/world1/acme/bonze/" : "凌雲寺",
	"/open/world1/acme/cominging/" : "天城大牢",
	"/open/world1/cominging/area/" : "步靈城",
	"/open/world1/cominging/purple_sun/" : "紫陽山",
	"/open/world1/ground_temple/" : "地下神殿",
	"/open/world1/linjack/emperor/" : "四大盜周圍",
	"/open/world1/moonhide/area/" : "天界",
	"/open/world1/sdo/nonhero/" : "無名英雄之墓",
	"/open/world1/tmr/area/" : "滄縣",
	"/open/world1/tmr/ghost-forest/" : "鬼斷森林",
	"/open/world1/wilfred/sand/" : "黃沙鎮",
	"/open/world1/wilfred/meadow/" : "牯牛草原",
	"/open/world1/wu_sha_town/" : "無沙鎮",
	// area中文名稱由sdo提供.
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
	set_name("聖誕老人", ({ "christmas-man", "man" }));
	set("gender", "男性" );
	set("long",@LONG
這就是傳說的耶誕老公公, 他只會在某些特定日子出現
百年難得一見ㄡ~~:P
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

	set("talk_reply", "我迷路了！...\n");

	set("can_speak", 1);
	set("inquiry", ([
		"迷路" : (: gogo :),
		"愛心" : (: report :),
		"目的地" : (: checkdest :),
	]));

	setup();
	set_living_name("ken_xmas");
//	set_heart_beat(30);

//	call_out("move_place", 10);
/*
	set_temp("helping", 0); // 幫助之玩家之ID
	set_temp("dest_dir", 0); // 目的地目錄名稱
	set_temp("destination", 0); // 目的地檔案名稱
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
	if( word == "愛心")
		write("耶誕老人說﹕"+report()+"");
	if( word == "迷路")
		write("耶誕老人說﹕"+gogo()+"");
	if( word == "目的地")
		write("耶誕老人說﹕"+checkdest()+"");

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

	call_out("find_place", 600); // 每10分鍾轉換目的地

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
                command("tchat 我在["+values(areas)[member_array(dest_dir , keys(areas))]+"]中迷路了:( (**遊戲最後至1月14日**)");
//		command("game 我現在迷路了，快來救我呀∼∼(玩法詳見help christmas)");

		call_out("move_place", 300); // 每5分鍾轉換地方

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
		return "謝過了，現正有人幫我帶路中了：）\n";

	if( !man->query_temp("destination") )
		find_place();

	place = load_object(man->query_temp("destination"));
	num = member_array(man->query_temp("dest_dir"), keys(areas));

	if( num == -1 || !place )
		return "咦？我瘋了耶，請找線上巫師替我醫治一下吧∼∼\n";

	command("follow "+me->query("id"));
	command("bow "+me->query("id"));

	remove_call_out("move_place");
	remove_call_out("find_place");
	remove_call_out("restart");
	call_out("restart", 300, 2);

	this_object()->set_temp("helping", me->query("id"));
	this_object()->set("chat_msg", ({
		"耶誕老人低頭看看手上的名單, 一臉茫然之色。\n",
		(: command("say 奇怪，我怎麼會迷路了呢...") :),
		(: command("hmm") :),
		(: command("help!") :),
	}));

	return "我想去"+HIY"『"+values(areas)[num]+HIY"』"NOR+"的"+HIY"『"+place->query("short")+HIY"』"NOR+"，麻煩你帶我去一下吧。\n"NOR;
}

string checkdest()
{
	if( !check() )
		return "這裡不是我想去的地方...\n";
}

int record(string id)
{
	if( !restore() )
		game_record = ([]);
	if( !game_record )
		game_record = ([]);

	game_record[id] += 1;

	this_object()->save();

	command("say 我非常感激你的幫助，可見你有愛心的人。");
	command("say 我會把你的愛心記錄下來，有朝一日我會回來賞你獎品，倘若你有繼續增加你的愛心...");

	restart(1);
	return 1;
}

void restart(int type)
{
	if( type == 1 )
	{
		command("say 時候不早了，我要繼續上路了。\n");
		command("wave");
	}
	if( type == 2 )
	{
		command("say 你太慢了，我看還是找第二個人幫我帶路吧。\n");
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
		else if( !userp(helper) ) // 判斷是否玩家,以防玩家跟obj id相同.
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
		return "目前還沒有任何人有愛心耶！\n";
	if( !mapp(game_record) )
		return "目前還沒有任何人有愛心耶！\n";

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
	msg += HIG"\t\t☆２００２新年特別活動『幫助迷路聖誕老人』愛心排行榜☆\n";
	msg+=HIW"--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--\n"NOR;
	while( i-- )
	{
		j++;

		if( ppl[i]==getuid(this_player()) ) msg+= HIC;
			else msg += CYN;

		if( game_record[ppl[i]] > 0 ) {
			msg+=sprintf("第%4s名 ---- %13s 愛心指數：%3d 點",
				chinese_number(j),ppl[i],game_record[ppl[i]]);

			switch( j )
			{
				case 1: msg+= HIM""BLINK" (愛心特獎：上名人堂＆自訂永久性 Save Eq 一件)\n"; break;
				case 2..3: msg+= HIY" (愛心大獎：永久性 Save Eq 一件)\n"; break;
				default: msg+= HIR" (愛心獎：用完即棄 Save Eq 一件)\n"; break;
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
			"耶誕老人低頭看看手上的名單, 一臉茫然之色。\n",
			(: random_move :),
			(: command("say 奇怪，我怎麼會迷路了呢...") :),
			(: command("hmm") :),
			(: command("help!") :),
		}));
		return;
	}
	else if( !userp(helper) ) // 判斷是否玩家,以防玩家跟obj id相同.
	{
		move_place();
		find_place();
		this_object()->delete_temp("helping");
		this_object()->set("chat_msg", ({
			"耶誕老人低頭看看手上的名單, 一臉茫然之色。\n",
			(: random_move :),
			(: command("say 奇怪，我怎麼會迷路了呢...") :),
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

	return "來幫我的?!";
}

void delete_record(string id)
{
	if( !restore() ) game_record= ([]);
	game_record[id] = 0;
	this_object()->save();
	return;
	}
