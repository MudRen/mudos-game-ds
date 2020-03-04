// 商人範例(1) 
// by Luky 19993.20
#include <ansi.h>
inherit NPC;
inherit BANKMAN;
void create()
{
//=========================基本設定==========================

        set_name("銀行助理", ({ "bank assistant","assistant"}));
        set("long",@LONG
        一個清秀的年輕小姐﹐她在這裡提供顧客存放款的服務。
        	
        	餘額查詢	<balance> 
        	存款		<deposit 金額> 
        	提款		<withdraw 金額> 
LONG);
        set("level",15);
        set("title","[1;32m行員[m");
        set("gender", "女性");
        set("race", "human");
        set("age", 26);
        
        //新的修正: 注意!! (wimpy)
        set("wimpy", 20);		//逃跑wimpy (20%)
	set("evil",-20);		//邪惡度 20 (正的表邪惡, 負表善良)

	set("attitude", "peaceful");   //溫和的 NPC。
	set("talk_reply","想存錢(deposit)嗎? 常常存款可以避免遺失喔!!");
	set("no_kill",1);

//===========================問題回答==================================
set("inquiry/name", @LONG
  [1;36m 我叫做李彩珍.. 請多指教!![0m
LONG );

        setup();
      add_money("dollar", 1670);		//帶的錢(coin古代,dollar現代,未來沒有)
	carry_object(__DIR__"../eq/leather_boots_f_5")->wear();
	carry_object(__DIR__"../eq/cloth_clothes_f_5")->wear();
}

void init()
{
 ::init();
 add_action("do_deposit","deposit");
 add_action("do_withdraw","withdraw");
}
