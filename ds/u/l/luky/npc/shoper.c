// 商人範例(1) 
// by Luky 19993.20
#include <ansi.h>
inherit NPC;
inherit SHOPMAN;
void create()
{
//=========================基本設定==========================

        set_name( "林老闆", ({ "boss lin","lin","boss"}));
        set("long", "一個胖胖的中年男人﹐曖昧的對著你笑著。\n\n"
        	    +"  看存貨請用 <list> <list wp> <list eq>\n"
        	    +"  要買東西用 <buy 物品> <buy 數量 物品> \n"
        	    +"  要賣東西用 <sell 物品> <sell all> <sell 數量 物品>\n\n"
        );
        set("level",20);
        set("title","[1;32m商人[m");
        set("gender", "男性");
        set("race", "人類");
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

   set("attitude", "peaceful");   //溫和的 NPC。
   set("talk_reply","好啊.. 多介紹一些朋友來買東西吧!!");
	set("storeroom","/u/l/luky/shop");	//注意. 要建立一個room放東西(參考/u/l/luky/shop.c)

  set("chat_chance", 3 );  //動作機率
  set("chat_msg", ({       //動作內容
"林老闆笑笑的說: 小兄弟, 要不要買點東西啊? 我可以算你便宜一點喔..\n",
(:command("smile"):),
}) );

//===========================問題回答==================================
set("inquiry/name", @LONG
  [1;36m 我叫做林大發.. 請多指教!![m
LONG );

        setup();

      add_money("coin", 120);		//帶的錢
      carry_object(__DIR__"item/bag");
      carry_object(__DIR__"eq/blackjacket")->wear();
}

void init()
{
add_action("do_list","list");
add_action("do_buy","buy");
add_action("do_sell","sell");
}


