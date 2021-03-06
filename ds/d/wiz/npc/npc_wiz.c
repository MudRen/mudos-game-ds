#include <ansi.h>
inherit NPC;
void goto_1();
void goto_2();
void goto_3();
void create()
{
//=========================基本設定==========================

        set_name( "大嘴", ({ "bigmouth" }));
        set("long", "一位很用功\的新手巫師﹐正在到處看文章學東西。\n");
        set("level",20);
        set("title","[1;32m見習巫師[m");
        set("gender", "男性");
        set("race", "human");
        set("age", 42);
        set("exp",1000);		//玩家殺死會得到exp/10 (可免)
        				//建議不要自己設exp. 由系統決定
        				//以免不同wiz寫的mob 會出現太大的差異
        				
        set("str",31);			//設定屬性(可免)
        set("dex",21);			//也可以只設定 level
        set("con",33);			//其他沒設定的屬性系統就會自動產生,
        set("int",18);			//即使是相同的level也會有不同屬性.
        
        set("combat_exp",2000);		//戰熟(約在mob level的100倍左右為宜)
//        set("env/wimpy", 20);		//逃跑wimpy (20%)
        set("evil",20);			//邪惡度 20 (正的表邪惡, 負表善良)

	set_skill("blade",40);		// 技能(自定)
	set_skill("parry",20);		//
	set_skill("dodge",30);		//

//========================態度類別=================================
//   set("attitude", "friendly");   //友善的 NPC。
   set("attitude", "peaceful");   //溫和的 NPC。
//   set("attitude", "heroism");    //英雄主義的 NPC。
//   set("attitude", "aggressive"); //主動攻擊,生性好鬥的的 NPC。
//   set("attitude", "killer");     //嗜殺成性的 NPC。


//=============================自動動作=================================
  set("chat_chance", 1 );  //動作機率
  set("chat_msg", ({       //動作內容
"你覺得有點不太對勁。\n",
(:command("look board"):),
(:command("say can you help me?"):),
(:command("hmm"):),
(:command("lick"):),
}) );

//===========================問題回答==================================
set("inquiry/name", @LONG
  [1;36m我叫做吳生四...你好!![m
LONG );


//=========================戰鬥訊息===========================
     set("chat_chance_combat", 17);
     set("chat_msg_combat", ({
(:command("kick "+this_player()->query("id")):),
 HIR"大嘴很不爽的說 : 「可惡的傢伙∼﹗PK就PK, 誰怕誰﹗」\n"NOR,
     }) );


// 排程動作

set("schedule",
([
	"00" : (: command("say 現在是遊戲中的0點整了喔!!") :),
	"01" : (: command("say 現在是遊戲中的1點整了喔!!") :),
	"02" : (: command("go up") :),
	"02" : (: command("say 現在是遊戲中的3點整了喔!!") :),
	"04" : (: command("go down") :),
	"05" : (: command("say 現在是遊戲中的5點整了喔!!") :),
	"06" : (: command("say 現在是遊戲中的6點整了喔!!") :),
	"07" : (: command("say 現在是遊戲中的7點整了喔!!") :),
	"08" : (: command("say 現在是遊戲中的8點整了喔!!") :),
	"09" : (: command("say 現在是遊戲中的9點整了喔!!") :),
	"10" : (: command("say 現在是遊戲中的10點整了喔!!") :),
	"11" : (: command("say 現在是遊戲中的11點整了喔!!") :),
	"12" : (: command("say 現在是遊戲中的12點整了喔!!") :),
	"13" : (: goto_1 :),
	"14" : (: command("say 現在是遊戲中的14點整了喔!!") :),
	"15" : (: command("say 現在是遊戲中的15點整了喔!!") :),
	"16" : (: command("say 現在是遊戲中的16點整了喔!!") :),
	"17" : (: goto_2 :),
	"18" : (: command("say 現在是遊戲中的18點整了喔!!") :),
	"19" : (: command("say 現在是遊戲中的19點整了喔!!") :),
	"20" : (: command("say 現在是遊戲中的20點整了喔!!") :),
	"21" : (: command("say 現在是遊戲中的21點整了喔!!") :),
	"22" : (: command("say 現在是遊戲中的22點整了喔!!") :),
	"23" : (: goto_3 :),
]));


        setup();

//==========================裝備道具=============================
      add_money("coin", 200);		//帶的錢
      carry_object("/u/l/luky/npc/item/bag");
      //carry_object(__DIR__"wp/kaisan_b")->wield();
      //carry_object(__DIR__"eq/blackjacket")->wear();
}

int talk_action(object me)	//talk 時會執行此函式.
{
 command("smile "+me->query("id") );
 command("say 我會努力學習的!");
 return 1;
}

void goto_1()
{
	if(!find_object("/u/l/luky/workroom")) return;
 message_vision(HIW" 『閃人囉~ 』只見$N"HIW"往天空一躍﹐化身為一隻小蝙蝠﹐啪啪啪~的飛走了。\n"NOR, this_object());
 this_object()->move("/u/l/luky/workroom");
 message_vision(HIW"『轟~~』$N"HIW"突然出現在一陣煙霧之中。\n"NOR, this_object());
}

void goto_2()
{
	if(!find_object("/u/s/shengsan/workroom")) return;
 message_vision(HIW" 『閃人囉~ 』只見$N"HIW"往天空一躍﹐化身為一隻小蝙蝠﹐啪啪啪~的飛走了。\n"NOR, this_object());
 this_object()->move("/u/s/shengsan/workroom");
 message_vision(HIW"『轟~~』$N"HIW"突然出現在一陣煙霧之中。\n"NOR, this_object());
}

void goto_3()
{
	if(!find_object("/d/wiz/hall1")) return;
 message_vision(HIW" 『閃人囉~ 』只見$N"HIW"往天空一躍﹐化身為一隻小蝙蝠﹐啪啪啪~的飛走了。\n"NOR, this_object());
 this_object()->move("/d/wiz/hall1");
 message_vision(HIW"『轟~~』$N"HIW"突然出現在一陣煙霧之中。\n"NOR, this_object());
}

void init()
{
	::init();
add_action("do_kill","kill");
}

int do_kill(string arg)
{
 if(arg=="passenger")
 {
 message_vision("[1;37m大嘴對$N[1;37m說: 請不要動粗, 有事好商量。[m\n",this_player());
 return 1;
 }
return 0;
}

//======================動作反應======================================
void relay_emote(object ob, string verb)
{
        if( !userp(ob) ) return;
        switch(verb) {
        case "kick":
                command("angry "+ob->query("id") );
		if(random(10)>7 && !ob->is_fighting())
        	{
        	shout("[1;31m"+ob->query("name")+"("+ob->query("id")+")悲慘的淒涼吶喊: 救命阿!! 救命阿!!!\n"
        	+"大嘴(bigmouth)想謀殺我!! 大嘴(bigmouth)是殺人兇手!![m\n");
                command("say 他@#$的, 老子正在用功\居然敢踢我!!");
                kill_ob(ob);
                }
                break;
        case "club":
                command("angry "+ob->query("id") );
                if(random(10)>6 && !ob->is_fighting())
        	{
        	shout("[1;31m"+ob->query("name")+"("+ob->query("id")+")悲慘的淒涼吶喊: 救命阿!! 救命阿!!!\n"
        	+"大嘴(bigmouth)想謀殺我!! 大嘴(bigmouth)是殺人兇手!![m\n");
                command("say 他@#$的, 老子正在用功\居然敢踢我!!");
                kill_ob(ob);
                }
                break;
        default:
                command("say 滾遠一點!!別煩我!!");
                break;
        }
}

//======================接受反應======================================
int accept_object(object who, object ob)
{
        int val;

        val = ob->value();
        if( !val )
                return notify_fail("他不想收你的東西。\n");
        else if( val > 100 ) {
                if( (who->query("evil") > 0)
                &&      (random(val/10) > (int)who->query("level")) )
                        who->add("evil", - (random((int)who->query("level")) + val/1000) );
        }
        say( "旅客說道﹕多謝這位" + RANK_D->query_respect(who)
                + "﹐神明一定會保佑你的。\n");

        return 1;
}

void reset()
{
        // delete("memory");
}
