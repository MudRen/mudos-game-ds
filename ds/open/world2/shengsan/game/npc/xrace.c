// xrace.c			Shengsan@DS	1999.4.9
// 競速小姐
// 如果要使用本程式, 請確定 driver 的 options.h 中有定義
// THIS_PLAYER_IN_CALL_OUT, 否則無法正常工作...

#include <ansi.h>

/*
 *  定義跑道長度
 */
#define RaceLength 1000

/*
 *  設定等待玩家下指令的時間
 */
#define WaitforplayerTime 20


inherit NPC;
inherit __DIR__+"chiplib.c";

void ChoiceNPC();
void raceloop();
void gameover(int target);
void Waitforplayer();
int to_say_play();
int do_see(string arg);
int do_seerace();
int do_stoprace();
int reset();
int reset_player();
int do_reset();
int Check_playerdata();
int Playing;
int Waitstatus;
int Checksum;
string Player;
string PlayerId;
int *NPCRace = ({	// 建議最高 100, 最低 1
		 60,  20,  70,  10,  70,
		 45,  90,  90,  95,  60,
		 85,   5,  75,  85,  60,
		 30,  40, 100,   3, 110,
		 75,  15,  80,  10,  50 });
int *NPCRacingRace = ({ 0,0,0,0,0,0 });
int *BetMutiple = ({ 0,0,0,0,0,0 });
int *RacingLenth = ({ 0,0,0,0,0,0 });
string *NPCName = ({
	"藍天美女","小紅蟳","蠟筆小新","凱蒂貓","米老鼠",
	"皮卡丘","吸血鬼","骷髏\人","魔法公主","路人甲",
	"辣妹","大海龜","路人乙","酷哥","拉麵伯伯",
	"開喜婆婆","小丸子","暴龍","小蚯蚓","大龍蝦",
	"SM女王","小紅帽","櫻木花道","小蚊子","MTV妹妹" });
string *NPCRacingName = ({ "None","None","None","None","None","None" });

void create()
{
	set_name("雪兒",({ "suet","racing lady","lady" }));
        set("level",9);
	set("title","競速小姐");
	set("race", "人類");
	set("gender","女性");
	set("age", 19);
	set("long",
@LONG
可愛美麗的小姐, 請讓她為你下籌碼吧. ( ask suet about play )
LONG
        );
	set("attitude", "friendly");

	set("inquiry",([
           "賽跑": (: to_say_play :),
           "race": (: to_say_play :),
           "玩法": (: to_say_play :),
           "play": (: to_say_play :),
           "規則": (: to_say_play :),
           "rule": (: to_say_play :),
	]));
        setup();
        seteuid(getuid());
}

void init()
{
	if(this_player()->query_temp("GAME/Xrace/Checksum")!=Checksum)
		reset_player();
	add_action("do_see","see");
	add_action("do_seerace",".");
	add_action("do_bet","bet");
	add_action("do_start","start");
	add_action("do_knpc","k");
	if(wizardp(this_player()))
	{
		add_action("do_stoprace","stoprace");
		add_action("do_reset","r");
	}
}

/*
 *  看比賽場的情況
 */
int do_see(string arg)
{
	object me = this_player();

	if(!arg || arg!="race")
	{
		command("say "+me->query("name")+"，什麼事情讓你東張西望的阿？");
		return 1;
	}
	do_seerace();
	return 1;
}

/*
 *  看比賽場的情況, 如果有籌碼且為第一次看, 會對比賽場作重置的動作.
 */
int do_seerace()
{
	string list;
	object me = this_player();
	int i;

	if(Playing==0 && PlayerId==0)
	{
		i = Game_can_afford(1,me);
		if(!me->query_temp("GAME/Xrace/Playing") && i!=0)
		{
			Playing = 1;			// 設定遊戲進行中
			PlayerId = me->query("id");	// 設定遊戲人
			Player = me->query("name");
			Checksum = random(9999)+1;	// 設定場次檢查碼
			ChoiceNPC();
			me->set_temp("GAME/Xrace/Checksum",Checksum);
			me->set_temp("GAME/Xrace/Playing",1);
		}
	}
	if(me->query_temp("GAME/Xrace/Playing")>=1)
		remove_call_out("Waitforplayer");
	message_vision("$N往比賽場望了過去！\n",me);
	list = "";
	list += "�����������������稙�������������������������������������������������������������\n";
	list += "�禷]道編號:\t";
	list += sprintf("��%-10s%-10s%-10s%-10s%-10s%-10s%2s",
		"-=１=-","-=２=-","-=３=-","-=４=-","-=５=-","-=６=-","��");
	list += "\n";
	list += "�礜w──────�鞷w─────────────────────────────�瀵n";
	list += "�灠捘阞怴G\t";
	list += sprintf("��%-10s%-10s%-10s%-10s%-10s%-10s%2s",
		NPCRacingName[0],NPCRacingName[1],NPCRacingName[2],
		NPCRacingName[3],NPCRacingName[4],NPCRacingName[5],"��" );
	list += "\n";
	list += "�礜w──────�鞷w─────────────────────────────�瀵n";
	list += me->query_temp("GAME/Xrace/Playing")==1 ? "�纗w估速度：\t" : "�瓥t度：\t";
	list += sprintf("��%-10d%-10d%-10d%-10d%-10d%-10d%2s",
		NPCRacingRace[0],NPCRacingRace[1],NPCRacingRace[2],
		NPCRacingRace[3],NPCRacingRace[4],NPCRacingRace[5],"��" );
	list += "\n";
	list += "�礜w──────�鞷w─────────────────────────────�瀵n";
	list += "�蠸葀v：\t";
	list += sprintf("��%-10d%-10d%-10d%-10d%-10d%-10d%2s",
		BetMutiple[0],BetMutiple[1],BetMutiple[2],
		BetMutiple[3],BetMutiple[4],BetMutiple[5],"��" );
	list += "\n";
	list += "�礜w──────�鞷w─────────────────────────────�瀵n";
	list += "�禷Z離終點距離：";
	list += sprintf("��%-10d%-10d%-10d%-10d%-10d%-10d%2s",
		RaceLength-RacingLenth[0],RaceLength-RacingLenth[1],RaceLength-RacingLenth[2],
		RaceLength-RacingLenth[3],RaceLength-RacingLenth[4],RaceLength-RacingLenth[5],"��" );
	list += "\n";
	list += "�����������������嘵�������������������������������������������������������������";
	list += "\n";
	tell_object(me,list);

	if(Playing==1 && me->query_temp("GAME/Xrace/Playing")<=2
	&& me->query_temp("GAME/Xrace/Checksum")==Checksum)
	{
		Waitstatus = 0;
		call_out("Waitforplayer",0);
	}

	if(me->query_temp("GAME/Xrace/Playing")<2)
		return 1;


	return 1;

	
}

/*
 *  選擇跑道及壓賭金
 */
int do_bet(string str)
{
	object me;
	int i,kind,bet;
	me = this_player();
	if(Playing && PlayerId != me->query("id"))
	{
		command("say "+me->query("name")+"，目前已經有人在玩了喔，麻煩請您等下一輪吧。");
		return 1;
	}
	if(Check_playerdata()==0)
		return 1;
	if(me->query_temp("GAME/Xrace/Playing")>=1)
		remove_call_out("Waitforplayer");

	i = Game_can_afford(1,me);
	if(i!=1)
	{
		command("say "+me->query("name")+"，您的籌碼呢？");
		return 1;
	}

	if(!me->query_temp("GAME/Xrace/Playing"))
	{
		command("say "+me->query("name")+"，您有沒有先看看場上的情形ㄚ？");
		return 1;
        }
	if(me->query_temp("GAME/Xrace/Playing")>=2)
	{
		command("say "+me->query("name")+"，您已經壓過了喔。");
		return 1;
        }

	if(!str)
	{
		command("say "+me->query("name")+"，請您看看玩法好嗎？");
		return 1;
	}

	if( sscanf(str,"%d %d",kind,bet)!=2)
	{
		command("say "+me->query("name")+"，請您看看規則好嗎？");
		return 1;
	}

	if( kind<1 || kind>6 )
	{
		command("say "+me->query("name")+"，您要壓幾號啊？");
		return 1;
	}

	me->set_temp("GAME/Xrace/Kind",kind);
	me->set_temp("GAME/Xrace/Bet",bet);
	me->set_temp("GAME/Xrace/Playing",2);
	Game_receive_chip(-bet,me);
	command("say 嗯，"+me->query("name")+"，您最看好的是 * "+NPCRacingName[kind-1]+" * ，賭金是"+chinese_number(bet)+"枚籌碼。");
	message_vision("$N將"+chinese_number(bet)+"枚籌碼拿給"+query("name")+"。\n",me);
	command("say "+me->query("name")+"，您可以按下 start 讓比賽開始囉。");
	command("say 別忘了，您只有一次機會可以隨時按 k 丟出保齡球干擾比賽喔！");

	if(Playing==1 && me->query_temp("GAME/Xrace/Playing")>=1)
	{
		Waitstatus = 0;
		call_out("Waitforplayer",0);
	}

	return 1;
}

/*
 *  開始比賽
 */
int do_start()
{
	object me = this_player();

	if(Playing && PlayerId != me->query("id"))
	{
		command("say "+me->query("name")+"，目前已經有人在玩了喔，麻煩請您等下一輪吧。");
		return 1;
	}

	if(me->query_temp("GAME/Xrace/Playing")>=3)
	{
		command("say "+me->query("name")+"，您已經按過開始鈕了喔。");
		return 1;
	}
	if(Check_playerdata()==0)
		return 1;
	if(me->query_temp("GAME/Xrace/Playing")>=1)
		remove_call_out("Waitforplayer");
	if( me->query_temp("GAME/Xrace/Playing")<2 )
	{
		command("say "+me->query("name")+"，你還沒押注耶！");
		return 1;
	}
	me->set_temp("GAME/Xrace/Playing",3);

	message_vision("$N很緊張的按下開始鈕。\n",me);
	raceloop();
	return 1;
}

/*
 *  進入真正的比賽迴圈
 */
void raceloop()
{
	object ob = this_object();
	int target,i,j;
	remove_call_out("raceloop");

	target = random(30)%6;

	switch(random(600)%20)
	{
		case 0: if(NPCRacingRace[target]<=0)
			{
				i = random(10)+1;
				NPCRacingRace[target] += i;
				RacingLenth[target] += NPCRacingRace[target];
				message_vision(NPCRacingName[target]+"聽到場外的加油聲而深深感動著，"+NPCRacingName[target]+"的速度由零變為"+chinese_number(i)+"了！\n",ob);
			}
			else
			{
				i = random(6)+1;
				NPCRacingRace[target] *= i;
				RacingLenth[target] += NPCRacingRace[target];
				message_vision(HIG+NPCRacingName[target]+"突然發狂，速度增加了"+chinese_number(i)+"倍！\n"NOR,ob);
			}
			break;
		case 1: i = (1+target+random(30)%5)%6;
			NPCRacingRace[target] = NPCRacingRace[i];
			RacingLenth[target] += NPCRacingRace[target];
			message_vision(HIG+NPCRacingName[target]+NOR"愛上了"HIM+NPCRacingName[i]+NOR"，速度跟"+NPCRacingName[i]+"一樣了！\n",ob);
			break;
		case 2: i = random(200)+1;
			RacingLenth[target] += i;
			message_vision(NPCRacingName[target]+"踩到"HIY"香蕉皮"NOR"，前進了"+chinese_number(i)+"格！\n",ob);
			break;
		case 3: if(NPCRacingRace[target]<=0)
			{
				i = random(100)+1;
				NPCRacingRace[target] += i;
				message_vision(HIC+NPCRacingName[target]+"從絕望中意外的得到小天使的鼓勵，速度由零變為"+chinese_number(i)+"了！\n"NOR,ob);
			}
			else if( random(5)==1 )
			{
				NPCRacingRace[target] = 0;
				message_vision(GRN+NPCRacingName[target]+"被場外丟進來的保齡球K到，速度變為零了！\n"NOR,ob);

			}
			break;
		case 4: i = (1+target+random(30)%5)%6; j = random(100);
			NPCRacingRace[i] -= ( (NPCRacingRace[i]-j)<=0 ? NPCRacingRace[i] : j );
			message_vision(NPCRacingName[target]+"向"+NPCRacingName[i]+HIR"發射飛彈"NOR"，結果造成"+NPCRacingName[i]+"的速度下降"+chinese_number(j)+"點！\n",ob);
			break;
		case 5: if(NPCRacingRace[target]<=0)
			{
				i = 200+random(100)+1;
				NPCRacingRace[target] += i;
				RacingLenth[target] += NPCRacingRace[target];
				message_vision(NPCRacingName[target]+"化悲憤為力量，突然化身為 "+HIM+"* 變態"+NPCRacingName[target]+" *"+NOR+" ，速度由零變為"+chinese_number(i)+"了！\n",ob);
			}
			else
			{
				i = random(6)+10;
				NPCRacingRace[target] *= i;
				RacingLenth[target] += NPCRacingRace[target];
				message_vision(NPCRacingName[target]+"突然變身為 "+HIY+"* 超級"+NPCRacingName[target]+" *"+NOR+" ，速度增加了"+chinese_number(i)+"倍！\n",ob);
			}
			break;
		case 6: if(NPCRacingRace[target]<=0)
			{
				i = random(10)+1;
				NPCRacingRace[target] += i;
				RacingLenth[target] += NPCRacingRace[target];
				message_vision(NPCRacingName[target]+"喝了一罐"+GRN+"蠻牛"+NOR+"，"+NPCRacingName[target]+"的速度由零變為"+chinese_number(i)+"了！\n",ob);
			}
			else
			{
				NPCRacingRace[target] -= NPCRacingRace[target]/2;
				RacingLenth[target] += NPCRacingRace[target];
				message_vision(HIM"哇!!"+NPCRacingName[target]+"在場上跌倒了，速度減少二分之一！\n"NOR,ob);
			}
			break;
		default:
			if(NPCRacingRace[target]<=0)
				message_vision(CYN"絕望的"+NPCRacingName[target]+"正待在原地不動。\n"NOR,ob);
			else if(random(2)==1)
			{
				RacingLenth[target] += NPCRacingRace[target];
				message_vision(HIG+NPCRacingName[target]+NOR+HIW"正奮力的向前跑。\n"NOR,ob);
			}
			else
			{
				RacingLenth[target] += NPCRacingRace[target];
				message_vision(HIC+NPCRacingName[target]+NOR+HIW"正努力的向前衝刺。\n"NOR,ob);
			}
	}

	if(RacingLenth[target]>=RaceLength)
	{
		remove_call_out("raceloop");
		gameover(target);
	}
	else
	{
		call_out("raceloop",1);
	}
	return;
}

/*
 *  讓玩家可以有一次的丟保齡球機會
 */
int do_knpc()
{
	object me = this_player();
	int target;
	if(Playing && PlayerId != me->query("id"))
	{
		command("say "+me->query("name")+"，目前已經有人在玩了喔，麻煩請您等下一輪吧。");
		return 1;
	}

	if(Check_playerdata()==0)
		return 1;

	if(me->query_temp("GAME/Xrace/Playing")<2)
	{
		command("say "+me->query("name")+"，這樣不好吧，遊戲又還沒開始。");
		return 1;
	}
	if(me->query_temp("GAME/Xrace/K"))
	{
		message_vision("$N想要暗算某人，卻發現沒有保齡球了。\n",me);
	}
	else
	{
		target = (me->query_temp("GAME/Xrace/Bet")+random(30)%5)%6;
		NPCRacingRace[target] = 0;
		message_vision(GRN"$N用力地把保齡球往外一丟，結果"+NPCRacingName[target]+"不幸地被保齡球K到，速度變為零了！\n"NOR,me);
		me->set_temp("GAME/Xrace/K",1);
	}
	return 1;
}

/*
 *  遊戲結束, 判斷輸贏.
 */
void gameover(int target)
{
	object me = this_player();
	object me2;
	int i,bet;

	if(Check_playerdata()==0)
		return;
	me->set("GAME/Xrace/Playing",4);
	Playing = 0;
	i = me->query_temp("GAME/Xrace/Kind");
	if( i != target+1 )
	{
		if(!objectp(me = present(PlayerId, environment(this_object()))))
		{
			command("shout 哇！ * "+NPCRacingName[target]+" * 得到了勝利！");
			command("say 咦？"+Player+"不知道跑到那兒了。");
		}
		else
		{
			do_seerace();
			command("shout 哇！ * "+NPCRacingName[target]+" * 得到了勝利！");
			command("say "+me->query("name")+"，很抱歉您猜的"+NPCRacingName[i-1]+"並沒有獲得冠軍。");
			command("say 也許\下次的運氣會更好喔，後會有期，"+Player+"。");
		}
	}
	else if(!objectp(me = present(PlayerId, environment(this_object()))))
	{
		command("shout 哇！ * "+NPCRacingName[target]+" * 得到了勝利！");
		command("say 咦？"+Player+"不知道跑到那兒了。沒辦法，獎金不能給你囉。");
		command("giggle");
	}
	else
	{
		do_seerace();
		command("shout 哇！ * "+NPCRacingName[target]+" * 得到了勝利！");
		bet = BetMutiple[target] * me->query_temp("GAME/Xrace/Bet");
		Game_receive_chip(bet,me);
		command("applaud "+me->query("id"));
		command("say "+me->query("name")+"，恭喜您猜中了本次比賽的冠軍得主是"+NPCRacingName[target]+"。");
		message_vision(query("name")+"將"+chinese_number(bet)+"枚籌碼給了$N！\n",me);
		command("say 歡迎下次再來呦。");
	}
	reset();
	return;
}

/*
 *  等待玩家下一個動作, 如果遲遲未有動作就重置比賽.
 */
void Waitforplayer()
{
	Waitstatus += 1;
	if( Waitstatus == 1)
		call_out("Waitforplayer",WaitforplayerTime);
	else
	{
		command("say 這麼久了都沒動作，好吧，這場比賽作廢。");
		reset();
	}
}

/*
 *  檢查玩家的資料是否正常
 */
int Check_playerdata()
{
	object me;
	if(!PlayerId)
		return 1;
	if(objectp(me = present(PlayerId, environment(this_object()))))
	{
		if(PlayerId==me->query("id") && !me->query_temp("GAME/Xrace/Playing"))
		{
			command("say "+me->query("name")+"，你可能在比賽期間曾經死亡或曾經離開過夢幻七域。");
			command("say 所以你在本遊戲的資料一併消失了。(請看規則第三條)");
			remove_call_out("raceloop");
			message_vision("遊戲被終止了！\n",me);
			reset();
			return 0;
		}
	}
	return 1;
}

/*
 *  強制停止比賽迴圈(巫師專用)
 */
int do_stoprace()
{
	remove_call_out("raceloop");
	write("比賽被某人中斷了...\n");
	return 1;
}

/*
 *  重置比賽資料
 */
int reset()
{
	int i;

	Playing = 0;
	PlayerId = 0;
	Player = 0;
	Checksum = 0;
	for(i=0;i<sizeof(NPCRacingName);i++)
	{
		NPCRacingRace[i] = 0;
		BetMutiple[i] = 0;
		RacingLenth[i] = 0;
		NPCRacingName[i] = "None";
	}
	reset_player();
	return 1;
}

/*
 *  重置玩家資料
 */
int reset_player()
{
	object me = this_player();
	if(me->query_temp("GAME"))
		me->delete_temp("GAME/Xrace");
	return 1;
}

/*
 *  重置資料
 */
int do_reset()
{
	reset();
	write("Reset was Okay...\n");
	return 1;
}

/*
 *  亂數點選出賽的名單
 */
void ChoiceNPC()
{
	int i,j,k,tmp,allsize, racesize;
	int *betmul = ( { 0,0,0,0,0,0 }) ;

	string list;

	allsize = sizeof(NPCName);
	racesize = sizeof(NPCRacingName);

	for(i=0;i<racesize;i++)		// 隨機取樣, 絕對不會重複
	{
		NPCRacingRace[i] = random(allsize)+1;
		for(j=0;j<i;j++)
		{
			if(NPCRacingRace[i]==NPCRacingRace[j])
				i--;
		}
	}
	for(i=0;i<racesize;i++)		// 將資料寫入
	{
		NPCRacingRace[i]--;
		NPCRacingName[i] = NPCName[NPCRacingRace[i]];
		NPCRacingRace[i] = NPCRace[NPCRacingRace[i]];
		betmul[i] = NPCRacingRace[i];
	}
	for(i=0;i<racesize;i++)		// 計算賠率的前置作業
	for(j=i;j<racesize;j++)		// 將速度作排序(使用泡昇排序法)
	{
		if(betmul[i] < betmul[j])
		{
			tmp = betmul[j];
			for(k=j;k>=i+1;k--)
				betmul[k] = betmul[k-1];
			betmul[i] = tmp;
		}
	}
	tmp = betmul[0]-betmul[5];	// 計算賠率的前置作業
	tmp = tmp/10;
	j = tmp-2;
	k = betmul[0]-betmul[5];
	for(i=0;i<racesize;i++)		// 計算賠率, 並將賠率寫入
	{
		BetMutiple[i] = tmp-j*(NPCRacingRace[i]-betmul[5])/k;
	}

	return;
}

/*
 *  說明玩法及規則
 */
int to_say_play()
{
	object me = this_player();
	command("say 玩法很簡單，只要你猜對哪一位參賽者會得冠軍，那麼高額獎金就是你的了。");
write(@HELP

        指  令                         說    明
=====================================================================
	see race		看看比賽場的情況
	.			看看比賽場的情況
	bet <跑道編號> <籌碼數>	下壓金，猜會得冠軍的參賽者
	start			開始比賽
	k			拿保齡球暗算場上的參賽者
=====================================================================

規則:	1. 一個場次只可以有一人押注，而且只能猜其中一位是冠軍。
	2. 只有一次機會可以拿保齡球暗算場上的參賽者。
	3. 比賽期間不得離開比賽場地，否則後果自負。
HELP);
	return 1;
}