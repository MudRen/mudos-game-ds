// 藍天建設銷售經理
// by Shengsan@DS  2002/4/2 05:07PM
#include <ansi.h>
#include <marry.h>
inherit NPC;
object ppl2, ppl1;

int do_buyhouse2(string index);
int do_buildhouse();
string query_ladyname();
void destlady();

void create()
{
        set_name( (: query_ladyname :), ({ "selling manager","manager" }));
        set("long", @LONG
她是一位擁有迷人風采的美麗女人，俏麗的短髮加上裝扮不俗的服飾，
一種攝人的眼神正在對你上下打量著，另外他更是藍天建設裡一位擁有專業
銷售經驗的經理人。

	buyhouse		買房子

LONG
        );
	set("level",30);
	set("title","榮譽之");
	set("gender", "女性");
	set("race", "人類");
	set("age", 32);
	set("exp",1000);		//玩家殺死會得到exp/10 (可免)
					//建議不要自己設exp. 由系統決定
					//以免不同wiz寫的mob 會出現太大的差異
	set("combat_exp",2000);		//戰熟(約在mob level的100倍左右為宜)
	set("evil",20);			//邪惡度 20 (正的表邪惡, 負表善良)

	set("attitude", "peaceful");		//溫和的 NPC。
	set("talk_reply","為您及您的另一半選購一間溫暖的家(home)吧..呵呵..");
	set("no_kill",1);
	set("no_fight",1);
	set("chat_chance", 1 );  //動作機率
	set("chat_msg", ({       //動作內容
		"銷售經理笑笑地說: 甜蜜蜜的小倆口也應該要有自己的房子(house)吧... 我賣的房子可是萬中之選喔!\n",
		"銷售經理很有興致地注視著你, 眼神中似乎帶有一點俏皮。\n",
		"銷售經理拿起杯子喝了些水。\n",
		(:command("grin"):),
		(:command("think"):),
		}) );
//===========================問題回答==================================
	set("inquiry/name", "[1;36m 我是藍天建設的辣妹經理... 請多指教!![m");
	set("inquiry/buy", "[1;36m 您要買房子嗎? \n如果您喜歡這間房子就把它給買下來(buyhouse)吧!![m");
	set("inquiry/house", "[1;36m 能有屬於自己的房子是每個人的夢想... \n如果您喜歡這間房子就把它給買下來(buyhouse)吧!![m");
	set("inquiry/home", "[1;36m 能有屬於自己的房子是每個人的夢想... \n如果您喜歡這間房子就把它給買下來(buyhouse)吧!![m");
	set("inquiry/buyhouse", "[1;36m 喔? 你要買房子... 請直接鍵入 buyhouse[m");
	setup();
	add_money("dollar", 250);		//帶的錢

}

void init()
{
	seteuid(getuid(environment()));
	if(!userp(this_player())) return;
	
//	if(MARRY_D->query_house_bought(environment(this_object())->query("houseid")))
//	{
//		destruct(this_object());
//		return;
//	}
	
	add_action("do_buyhouse","buyhouse");
	add_action("do_yes",({"y"}));
	add_action("do_yes",({"yes"}));
	add_action("do_no",({"no"}));
	add_action("do_buildhouse","bh");
}

string query_ladyname()
{
	object envobj;
	string ladyname;
	
	envobj = environment(this_object());
	ladyname = envobj->query("Ladyname");
	if(!ladyname)
		ladyname = "辣妹";
	return ladyname;
}

int do_buyhouse()
{
	object target, temp, ob = this_object(), me = this_player();
	string	targetname;

	if(ob->query("buyinghouse")) return notify_fail("她似乎正在忙。\n");

	if( !targetname = me->query("marry_id") )
	{
		command("think");
		command("say 等你找到終身伴侶後再來談吧！");
		return 1;
	}
	if(!target = find_player(targetname))
	{
		command("hmm");
		command("say 好像沒這位朋友喔，您請回吧。");
		return 1;
	}
	if(userp(target) && environment(target) == environment(ob))
	{
		ppl1 = me;
		ppl2 = target; 
		set("buyinghouse",1);
		command("hmm");
		call_out("do_buyhouse1",3);
		return 1;
	}

	command("say 請您的配偶也來這裡看看房子吧。");
	command("snicker");
	return 1;
}

void do_buyhouse1()
{
	object ob = this_object();

	if(environment(ppl1) != environment(ob))
	{
		command("flop");
		command("say 客人跑了，難道是我不夠吸引力嗎？那這樁買賣就此打住嚕。");
		delete("buyinghouse");
		delete("asking");
		return;
	}
	if(environment(ppl2) != environment(ob))
	{
		command("?");
		command("say 怎麼您的愛人一轉眼就不見了？");
		delete("buyinghouse");
		delete("asking");
		return;
	}
	command("look "+ppl2->query("id"));
	command("say 嗯... 待我詢問對方的意見。");
	tell_object(ppl2,HIC+ppl1->name(1)+"提出買這棟房子的提議，請問您同意嗎？ [yes/no]\n"NOR);
	set("asking",1);
	return;
}

int do_yes()
{
	if(this_player() == ppl2 && query("asking"))
	{
		do_buyhouse2("y");
		return 1;
	}
	return 0;
}

int do_no()
{
	if(this_player() == ppl2 && query("asking"))
	{
		do_buyhouse2("n");
		return 1;
	}
	return 0;
}



int do_buyhouse2(string index)
{
	object ob = this_object();
	object obj1,obj2;

	delete("asking");
	if(index == "y")
	{
		message_vision(HIR"\n[$N望著$N感動地說: 好感動！我當然同意嚕！]\n\n"NOR,ppl2,ppl1);
		command("say 嗯∼太好了！");
		command("grin");
		if(environment(ppl1) != environment(ob))
		{
			command("flop");
			command("say 買主跑了，那這樁買賣就此打住嚕。");
			delete("buyinghouse");
			return 1;
		}
		if(ppl1->query("bank/now") < HOUSE_VALUE )
		{
			message_vision("$N摸摸自己的口袋後，臉上露出尷尬的表情。", ppl1);
			command("flop");
			command("ack");
			command("say 原來是窮光蛋?! 本美女真是看走了眼，那這樁買賣就此打住了吧。");
		}
		else if(!objectp(obj1 = present("marry ring", ppl1)))
		{
			command("flop");
			command("say "+ppl1->name(1)+"，你的結婚戒指呢？你的婚姻關係值德商榷喔，那這樁買賣就此打住了吧。");
		}
		else if(!objectp(obj2 = present("marry ring", ppl2)))
		{
			command("flop");
			command("say "+ppl2->name(1)+"，你的結婚戒指呢？你的婚姻關係值德商榷喔，那這樁買賣就此打住了吧。");
		}
		else if(!do_buildhouse())
		{
			command("think");
			command("say 奇怪嚕... 藍天建設對於這次的買賣似乎不以為意。(請通知線上巫師)");
			command("say 既然如此... 那這樁買賣就此打住了。");
		}
		else
		{
			ppl1->add("bank/now",-HOUSE_VALUE);
			tell_object(ppl1,HIG"[銷售經理跟您收了 "+HOUSE_VALUE+" 枚金幣。] \n"NOR);
			message_vision(HIR"\n[$N給了銷售經理 "+HOUSE_VALUE+" 枚金幣！]\n\n"NOR,ppl1);
			ppl1->save();
			ppl2->save();
		}
	}
	else
	{
		message_vision(HIC"\n[$N堅決的搖了搖頭]\n\n"NOR, ppl2);
		ob->command("say 看來您的愛人並不同意耶，那就算了，那這樁買賣就此打住嚕。");

	}
	delete("buyinghouse");	
	return 1;
}

int do_buildhouse()
{
	object ob = this_object();
	int i;
	i = MARRY_STD->buildhouse(ob);
	return i;
}

void reset()
{
	delete("buyinghouse");
	delete("asking");
	command("say 您來的不巧，今天公休日，想買房子明天請早。");
}

void destlady()
{
	int i;
	
	i = MARRY_D->query_house_bought(environment(this_object())->query("houseid"));
	if(i)
		destruct(this_object());
	return;
}