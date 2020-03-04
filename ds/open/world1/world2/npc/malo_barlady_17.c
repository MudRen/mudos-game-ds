#include <ansi.h>
inherit NPC;
inherit SELLMAN;
void create()
{
//=========================基本設定==========================

        set_name( "服務小姐", ({ "bar lady","lady"}));
        set("long",@LONG
        一個酒店的服務小姐，正在對著你哈腰。
	==============================================
	目錄 <list>
	買東西 <buy 物品> <buy 數量 物品>
	==============================================
LONG);
        set("level",17);
        set("gender", "女性");
        set("race", "human");
        set("age", 33);
        set("evil",-10);			//邪惡度 20 (正的表邪惡, 負表善良)

	set("attitude", "peaceful");   //溫和的 NPC。
	set("talk_reply","我們賣的酒可是很受歡迎的喔!!");
	set("sell_list",([
  __DIR__"../obj/bloodmarry_wine" : 15,
  __DIR__"../obj/bluegimi_wine" : 20,
  __DIR__"../obj/beer" : 5,
  __DIR__"../obj/greentea" : 10,
]));

//===========================問題回答==================================
set("inquiry/name", @LONG
  [1;36m 我叫做小美.. 請多指教!![m
LONG );
        setup();
      add_money("dollar", 780);		//帶的錢
      carry_object(__DIR__"../eq/cloth_clothes_f_5")->wear();
      carry_object(__DIR__"../eq/gem_ring_1")->wear();
      carry_object(__DIR__"../eq/leather_boots_f_5")->wear();
      carry_object(__DIR__"../eq/cloth_gloves_3")->wear();
}

void init()
{
	::init();
	add_action("do_list","list");
	add_action("do_buy","buy");
}

