// 商人範例(1) 
// by Luky 19993.20
#include <ansi.h>
inherit NPC;
inherit BANKMAN;
inherit SSERVER;
void call_help();
void create()
{
//=========================基本設定==========================

        set_name( "蘭瑟斯", ({ "rancus",}));
        
        //tmr, long你自己改改吧. 配點eq..
        set("long", "一個身穿制服的工作人員, 接洽來往的客人。\n\n"
        	    +"  查詢帳戶請用 <balance> \n"
        	    +"  看存錢請用 <deposit 基本金額> \n"
        	    +"  要提錢請用 <withdraw 基本金額> \n\n"
        );
        
        set("level",3);
        set("title","[1;32m助手[m");
        set("gender", "男性");
        set("race", "人類");
        set("age", 45);

        set("combat_exp",300);		//戰熟(約在mob level的100倍左右為宜)
        
        set("evil",-20);			//邪惡度 20 (正的表邪惡, 負表善良)

	set_skill("unarmed",20);		// 技能(自定)
	set_skill("parry",10);		//
	set_skill("dodge",10);		//

   set("attitude", "peaceful");   //溫和的 NPC。
   set("talk_reply","想存錢(deposit)嗎? 常常存款可以避免遺失喔!!");

  set("chat_chance", 3 );  //動作機率
  set("chat_msg", ({       //動作內容
(: command("smile") :),
}) );
	set("chat_chance_combat", 10);
	set("chat_msg_combat", ({
(: call_out("call_help",0) :),
(: call_out("call_help",0) :),
(: call_out("call_help",0) :),
 HIR"蘭瑟斯大叫 : 「救命ㄚ∼﹗有人搶劫ㄚ﹗」\n"NOR,
     }) );
//===========================問題回答==================================
set("inquiry/name", @LONG
  [1;36m 我叫做蘭瑟斯.. 請多指教!![m
LONG );

        setup();

		//帶的錢(coin古代,dollar現代,未來沒有)
	add_money("silver", 25);
}

void init()
{
 add_action("do_deposit","deposit");
 add_action("do_withdraw","withdraw");
}

void call_help()
{
	object roken,target;
	target = offensive_target(this_object());
	if(!target) return ;

	roken=present("roken", environment(this_object()));
	if(!roken)
	{
		message_vision("蘭瑟思大叫: 快來人哪~~ 救命ㄚ!! \n",target);
		return ;
	}
	if(roken->is_fighting(target))
	{
		message_vision("洛肯看起來很生氣的樣子!!\n",target);
		return ;
	}
	else
	{
	 roken->kill_ob(target);
	 say(HIW"洛肯怒罵道：光天化日之下膽敢殺人搶劫！我要替天行道！！\n"NOR);
	 message_vision("洛肯大喝一聲, 開始對$N發動攻擊!!\n",target);
	 return ;
	}
}

