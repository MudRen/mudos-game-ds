// 青樓女子 - 點唱 v1.1 ( cominging 5/13/2000 )
// 1. 增加 teach 和 accept 指令
// 2. 改變檔案儲存方式, 可以改用數目字來用, 方便統計。

#include <ansi.h>

inherit NPC;

string *color = ({ HIM, HIW, RED, GRN, YEL, BLU, MAG, CYN,WHT, HIW });

void speak_message(object me, int flag, string *songs, string target_name);
void speak_end(int flag);

void create()
{
	set_name(GRN"青樓女子"NOR, ({ "wandering geisha","geisha" }) );
	set("long",
		"　　平常在樓層之上觀看風景的一個青樓女子，她一臉憂愁的樣子\n"
		"，似乎有著無限的煩惱，拿起她手中的那個箏，不時的彈起那弦，\n"
                "鼓起一陣陣的傷感與悲傷，你或許\可以問她聊一聊天, 她就會跟你\n"
        "說她所會唱的歌曲。\n");
	set("level", 23);
	set("age", 20+random(10));
	set("gender","女性");

	set("chat_chance", 6);
	set("chat_msg", ({
  this_object()->name(1)+"望著窗口向遠方嘆了口氣。\n",
  this_object()->name(1)+"喃喃自道: 自古多情空餘恨，此恨綿綿無絕期。\n",
  this_object()->name(1)+"拿起手中的箏，兢兢開始彈了起來。\n",
  (: command,"say 月光暗色淡，余心往鄉歸。" :),
  (: command,"say 不知何處是予家，處處是天下。" :),
  this_object()->name(1)+"臉色凝了一會兒，然後嘆了一口氣。\n",
}));
	set("chat_chance_combat", 12);
	set("chat_msg_combat", ({
  (: command,"sigh man" :),
  (: command,"say 何苦呢∼" :),
  (: command,"say 若苦之於我心也....:(" :),
}));

	set("inquiry", ([
//  "song" : (: list_songs :),
]));
	setup();
	carry_object(__DIR__"wp/zithern.c")->wield();
	carry_object(__DIR__"eq/s_cloth.c")->wear();
}

void init()
{
	add_action("do_sing","singing");
      add_action("do_teach", "teach");
    add_action("do_accept", "accept");
}

string query_color()
{
	return color[random(sizeof(color))];
}

void speak_end(object me)
{
	CHANNEL_D->do_channel(this_object(),"music","謝謝您的欣賞, 謝謝.");
	this_object()->delete_temp("busy");
	this_object()->delete("no_fight");
}

void speak_message(object me, int flag, string *songs, string target_name)
{
	if( flag > sizeof(songs) -1 )
	{
		call_out("speak_end", 0, me);
		return;
	}
	if( flag == 0 && target_name != me->name_id())
		CHANNEL_D->do_channel(this_object(), "music", HIG+me->name(1)+NOR"點撥了一首歌" + ((target_name) ? "給"+HIC+target_name+NOR : "") + "..。");
	CHANNEL_D->do_channel(this_object(),"music", query_color()+songs[flag]+NOR);
	call_out("speak_message", 4+random(3) , me, ++flag, songs, target_name);
}

int do_sing(string arg)
{
          string *songs, n_s, tar;
	int c;
	object me, t;

	me = this_player();

	if( query_temp("busy") )
		return notify_fail(" 有人在點了喔 ! \n");
//	if( me->query_temp("have_singing" ) ) return notify_fail(" 你已經點過了了喔！\n");
	if( !arg || ( sscanf(arg, "%d", c) != 1 && sscanf(arg, "%d for %s", c, tar) != 2 ))
		return notify_fail("想要點那首歌曲呢？( singing <第幾首> [for <人>] )\n");

	if( sscanf(arg, "%d for %s", c, tar) == 2 )
	{
		if( !objectp(t=find_player(tar)) )
			return notify_fail("沒有這個人喔！\n");
		if( t == me )
			return notify_fail("點給自己..！！\n");
		if( t->query_temp("invis") )
			return notify_fail("沒有這個人喔！\n");
	}

	if( file_size(n_s=__DIR__"song_info/"+c) == -1 ) return notify_fail("沒這首吧？\n");

	write(HIR"點撥歌曲：第 "+c+" 首。\n"NOR);

	if( !read_file(n_s)
	||	!arrayp(songs = explode(read_file(n_s) , "\n")))
		return notify_fail(HIR"載入失敗！！\n"NOR);

//	me->set_temp("have_singing",1);
	this_object()->set_temp("busy", 1);
	this_object()->set("no_fight", 1);
	if( !objectp(t) )
		t = me;
	call_out("speak_message", 1, me, 0, songs, t->name_id());
	return 1;
}

int talk_action(object me)
{
        string arg, *qu;
         int  j;

//	arg = "等會兒..\n" + "只見" + this_object()->name(1) + "拿出一張紙條...\n\n"
	arg = "只見" + this_object()->name(1) + "拿出一張紙條...\n\n"
	      + HIY"─────────── ◎ 歌 曲 ◎ ───────────\n"NOR;

	for(j=1;file_size(__DIR__"song_info/"+j)!=-1;j++)
	{
		qu = explode(read_file(__DIR__"song_info/"+j), "\n");
//		arg += chinese_number(j) + "、 " + t[z] + ((qu[0][0..1] == 0) ? HIR : NOR) + qu[0] + "\n"NOR;
		arg += chinese_number(j) + "、 " + ((qu[0][0..1] == 0) ? HIR : NOR) + qu[1] + "\n"NOR;
	}
	me->start_more(arg);
	return 1;
}

int do_teach()
{
	write(" - 玩家歌曲增加系統 - 請依照指式, 輸入系統所要求的。 \n");
	write("完成輸入後請按'.'結束儲存結果，取消輸入則按'~q'\n"NOR);
	write("───── "HIC"● "HIW"玩"HIY"家輸入系統"HIC" ○"NOR"────────\n");
	input_to("teach_1");

	return 1;
}

int teach_1(string msg, string text, int flag)
{
	if( flag == 0 )
	{
		text = "0" + this_player()->query("id") + "\n";
		flag = 1;
	}
	if( (flag == 1 || flag == 2 || flag == 3) && msg == ".")  
	{
		tell_object(this_player(),"歌曲不完整，input cancel。\n");
		return 1;
	}

	if( strlen(msg) > 70 )
	{
		write("\n "HIR"< error >"HIW" 每行只能有 70 個半形字, 35 個全形字 (中文字) 。\n");
		write("第"+CHINESE_D->chinese_number(flag-2)+"行[]﹕");
		input_to("done_songname", text, flag);
		return 1;
	}

	if(msg=="~q")
	{
		tell_object(this_player(),"\n取消輸入。\n");
		return 1;
	}
	if(msg==".") 
	{
		write(WHT"\n──────────────"HIW"["NOR WHT"歌曲編輯器"HIW"]"NOR WHT"──────────────\n"NOR);		
		write(HIG"歌曲編輯完畢。\n"NOR);
		
		if(call_out("do_save_song",1,text))
		write("資料傳輸中。\n");
		else
		write("資料傳送失敗。\n");
		
		return 1;
	}
	
	text += msg + "\n";
	flag++;
	
	if(flag == 2)
		write("請輸入原唱人﹕");
	else if(flag == 3)
		write("以下請逐句輸入歌詞﹕\n[第一句]﹕");
	else
		write("[第"+CHINESE_D->chinese_flagber(flag-2)+"句]﹕");
	input_to("done_songname", text, flag);
	
	return 1;
}

// 搜尋/etc目錄下的歌曲, 尋找空位
int do_check_had_songs(int num)
{
	string file, *msg;
	
	file = __DIR__"etc/";
	
	for(num=1;num<num+1;num++)
	{
	if( file_size(file+num)!=-1 ) //有這個檔的話
	{
		msg = explode( read_file(file+num), "\n");
		if( msg[1][0..3]=="<無>")
		return num;
	}
	else return num;
	}
	return num;     
}

// 歌曲存檔
int do_save_song(string msg)
{
	
	string file;
	int checksong;
	
	checksong = do_check_had_songs(1);
	file = __DIR__"etc/"+checksong;

	if(!checksong)
		tell_object(this_player(),"存檔空位搜尋失敗，請通知巫師處理。\n");
		
	if( file_size(file)==-1 )
		tell_object(this_player(),"第 "+checksong+" 首歌曲建立新檔案完畢。\n");
	else
		tell_object(this_player(),"第 "+checksong+" 首歌曲重新建立完畢。\n");
	
	if( file_size(file)!=-1 )
	rm(file);

	if( write_file(file, msg) ) 
	{
		tell_object(this_player(),"歌曲第 "+checksong+" 首存檔完畢，請等待認可。\n");
		return 1;
	}
	else
	{
		tell_object(this_player(),"歌曲(" + file + ")寫入失敗，請通知巫師處理。\n");
		return 1;
	}

	return 1;
}

//刪除歌曲
int do_del(string arg)
{
	string file, *msg, str;
	object me=this_player();
	
	if(!arg) return notify_fail("請輸入你所想要刪除的歌曲編號。\n");
	file = __DIR__"etc/"+arg;

	if( file_size(file) == -1 ) {
		return notify_fail("沒有此首歌曲。\n");
	}
	msg = explode( read_file(file), "\n");
	if( msg[1] != me->query("id") )
	return notify_fail("這首歌曲並非你所填詞，因此你無法刪除此歌。\n");
	
	str = "0\n<無>\n<已刪除>\n<已刪除>\n";
	rm(file);
	write_file(file, str);
	message_vision("$N在點唱機上按了幾下，刪除了第 "+arg+" 首歌「"+msg[2]+"」。\n", me);
	return 1;

}

// 歌曲巫師認可
int do_accept(string arg)
{
	int i;
	string file, *msg, text;
	object me = this_player();

        if( !wizardp(me) || wiz_level(me) < 4) return notify_fail("您的權限不足以認可歌曲");
	if( !arg ) return notify_fail("請輸入欲認可的歌曲編號。\n");

	file = __DIR__"song_info/" + arg;

	if( file_size(file) == -1 )
		return notify_fail("並沒有這首歌存在。\n");

	msg = explode(read_file(file), "\n");
	if(msg[0] != "0") return notify_fail("此首歌已通過認可。\n");
	if(msg[1] == "<無>") return notify_fail("此首歌已遭刪除，無需認可。\n");

	text = "1\n";
	for(i=1;i<sizeof(msg);i++)
		text += msg[i]+"\n";
	
	rm(file);
	if( !write_file(file, text) ) 
		write("無法認可歌曲("+file+")，請通知clode處理。\n");
	else
		write("第 "+arg+" 號歌曲「"+msg[2]+"」，填詞者:"+msg[1]+"通過認可。\n");
	return 1;

}
