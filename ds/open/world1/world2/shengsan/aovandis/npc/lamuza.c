// 獎卷商人範例(1) 
// by Luky 19993.20
#include <ansi.h>
inherit NPC;
inherit LOTTERYMAN;
void create()
{
//=========================基本設定==========================

        set_name( "拉穆札", ({ "lamuza"}));
        set("long", "一個戴著眼鏡的中年人﹐正在這裡擺\攤位賣彩卷。\n\n"
        	    +"  看存貨請用 <list> \n"
        	    +"  要買東西用 <buy 編號 ticket> <buy 物品> <buy 數量 物品> \n"
        	    +"  要對獎用 <reward> \n\n"
        );
        set("level",20);
        set("title","[1;32m獎卷商[m");
        set("gender", "男性");
        set("race", "人類");
        set("age", 42);
        set("exp",1000);		//玩家殺死會得到exp/10 (可免)
        				//建議不要自己設exp. 由系統決定
        				//以免不同wiz寫的mob 會出現太大的差異
       
        set("combat_exp",2000);		//戰熟(約在mob level的100倍左右為宜)
//        set("env/wimpy", 20);		//逃跑wimpy (20%)
        set("evil",20);			//邪惡度 20 (正的表邪惡, 負表善良)

   set("attitude", "peaceful");   //溫和的 NPC。
   set("talk_reply","多買點彩卷吧..呵呵..");
	//注意. 要設定貨品清單
   set("sell_list",([	
           TICKET    : 10, //表示每買一張彩卷會扣10點補給點數
           "/open/always/newspaper"  : 15, 
       ]) );
        set("gift_file",({	
         "/open/always/doll",
         __DIR__"wp/sunsword",
         __DIR__"eq/sunarmor",
         __DIR__"wp/sundagger",
         __DIR__"eq/sunboots",
         __DIR__"wp/sunstaff",
         __DIR__"eq/suncloth",
         __DIR__"wp/sunblade",
         __DIR__"eq/suncloak",
        }) );
  set("no_kill",1);
  set("no_fight",1);
  set("chat_chance", 1 );  //動作機率
  set("chat_msg", ({       //動作內容
"拉穆札笑笑的說: 大老闆, 要不要買點彩卷<buy>啊? 我賣的彩卷<list>中獎率很高喔!\n",
(:command("grin"):),
(:command("think"):),
}) );

//===========================問題回答==================================
set("inquiry/name", @NAME
  [1;36m 我叫做拉穆札.. 請多指教!![m
NAME
);

        setup();

      add_money("dollar", 120);		//帶的錢

}

void init()
{
::init();
add_action("do_list","list");
add_action("do_buy","buy");
add_action("do_reward","reward");
}


