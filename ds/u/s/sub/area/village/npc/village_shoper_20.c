// 商人範例(1) 
// by Luky 19993.20
#include <ansi.h>
inherit NPC;
inherit SHOPMAN;
void create()
{
//=========================基本設定==========================

        set_name( "商店老闆", ({ "shop boss","boss"}));
        set("long",@LONG
        一個胖胖的中年男人，正在清潔貨架。
	==============================================
	查詢存貨 	<list> <list wp> <list eq>
	買東西 		<buy 物品> <buy 數量 物品>
	賣東西 		<sell 物品> <sell all> <sell 數量 物品>
	試用東西 	<try 物品>
	==============================================
LONG);
        set("level",19);
        set("title","[1;32m商人[m");
        set("gender", "男性");
        set("race", "human");
        set("age", 42);
        set("evil",10);			//邪惡度 20 (正的表邪惡, 負表善良)

	set("attitude", "peaceful");   //溫和的 NPC。
	set("talk_reply","好啊.. 多介紹一些朋友來買東西吧!!");
	set("storeroom",__DIR__"shop1");	//注意. 要建立一個room放東西

//===========================問題回答==================================
set("inquiry/name", @LONG
  [1;36m 我叫做林奇.. 請多指教!![m
LONG );
        setup();
      add_money("dollar", 1100);		//帶的錢
}

void init()
{
	::init();
	add_action("do_list","list");
	add_action("do_buy","buy");
	add_action("do_sell","sell");
	add_action("do_try","try");
}


