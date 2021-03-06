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

        set_name( "寒大富", ({ "harn-tar-fu","harn","fu","boss"}));
        
        //tmr, long你自己改改吧. 配點eq..
        set("long", "一個身穿華麗服飾的微胖中年人, 他也是這間錢莊的主人。\n\n"
        	    +"  查詢帳戶請用 <balance> \n"
                +"  要存錢請用 <deposit 基本金額> \n"
        	    +"  要提錢請用 <withdraw 基本金額> \n\n"
        );
        
        set("level",17);
        set("title","[1;32m員外[m");
        set("gender", "男性");
        set("race", "人類");
        set("age", 45);

        set("combat_exp",1700);		//戰熟(約在mob level的100倍左右為宜)
        
        set("evil",20);			//邪惡度 20 (正的表邪惡, 負表善良)

	set_skill("blade",40);		// 技能(自定)
	set_skill("parry",40);		//
	set_skill("dodge",40);		//

   set("attitude", "peaceful");   //溫和的 NPC。
   set("talk_reply","想存錢(deposit)嗎? 常常存款可以避免遺失喔!!");

  set("chat_chance", 3 );  //動作機率
  set("chat_msg", ({       //動作內容
(: command("stare") :),
}) );
	set("chat_chance_combat", 10);
	set("chat_msg_combat", ({
(: call_out("call_help",0) :),
(: call_out("call_help",0) :),
(: call_out("call_help",0) :),
 HIR"員外大叫 : 「救命ㄚ∼﹗有人搶劫ㄚ﹗」\n"NOR,
     }) );
//===========================問題回答==================================
set("inquiry/name", @LONG
  [1;36m 我叫做寒大富.. 請多指教!![m
LONG );

        setup();

	add_money("gold", 1);		//帶的錢(coin古代,dollar現代,未來沒有)
	add_money("silver", 36);
}

void init()
{
 add_action("do_deposit","deposit");
 add_action("do_withdraw","withdraw");
}

void call_help()
{
	object guard,target;
	target = offensive_target(this_object());
	if(!target) return ;

	guard=present("guard", environment(this_object()));
	if(!guard)
	{
		message_vision("員外大叫: 快來人哪~~ 救命ㄚ!! \n",target);
		return ;
	}
	if(guard->is_fighting(target))
	{
		message_vision("守衛看起來很生氣的樣子!!\n",target);
		return ;
	}
	else
	{
	 guard->kill_ob(target);
	 message_vision("守衛大喝一聲, 開始對$N發動攻擊!!\n",target);
	 return ;
	}
}

