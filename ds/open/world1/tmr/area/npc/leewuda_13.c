// by Luky 19993.20
#include <ansi.h>
inherit NPC;
void create()
{
//=========================基本設定==========================

        set_name("李武達", ({"lee wu da","lee","da"}));
        set("long",@LONG
一個剛拜入八極門的年輕人，正在這裡對著稻草人練習大槍訣，
看起來似乎還不太熟練。

LONG
        );
        set("gender", "男性");
        set("race", "human");
 	set("level",13);
        set("age", 19);
        //set("exp",300);		//玩家殺死會得到exp/10 (可免)
        				//建議不要自己設exp. 由系統決定
        				//以免不同wiz寫的mob 會出現太大的差異
			
//        set("env/wimpy", 10);		//逃跑wimpy (10%)
        set("evil",-20);		//邪惡度 -20 (正的表邪惡, 負表善良)

	set_skill("unarmed",99);	// 技能(自定)
	set_skill("combat",90);		//
	set_skill("fork",70);		//
	set_skill("da-fork",30);	//
	map_skill("fork","da-fork");
//	set("chat_chance_combat", 50);
//       set("chat_msg_combat", ({
//                (:command("exert da-fork"):),
//         }) );

	
   set("attitude", "peaceful");   //溫和的 NPC。
set("inquiry/master", @NAME
  [1;36m 我的師傅神槍李就在小屋(house)裡面，想見他就進去(enter)吧。[m
NAME );
//set("talk_reply","怎麼辦!?我不小心把小明鎖在秘密基地(base)了.. 你可以幫我救救他嗎?");
      setup();
//      set_element("fire");  //向性: none,metal,plant,wind,ground,water,fire
      add_money("coin", 120);		//帶的錢 古代:coin 現代:dollar 未來則用set("bank/future",數量);
      carry_object("/open/world1/eq/clothes_8")->wear();
      carry_object("/open/world1/wp/pike_13")->wield();
}


