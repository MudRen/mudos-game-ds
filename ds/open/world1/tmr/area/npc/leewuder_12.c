// by Luky 19993.20
#include <ansi.h>
inherit NPC;
void create()
{
//=========================基本設定==========================

        set_name("李武德", ({"lee wu der","lee","der"}));
        set("long",@LONG
一個剛拜入八極門的年輕人，正在這裡練習著八極拳，一招一式
似乎頗具架勢，但由地上足印的深度看來，其馬步基礎還不夠紮實。

LONG
        );
        set("gender", "男性");
        set("race", "human");
 	set("level",12);
        set("age", 19);
        //set("exp",300);		//玩家殺死會得到exp/10 (可免)
        				//建議不要自己設exp. 由系統決定
        				//以免不同wiz寫的mob 會出現太大的差異
			
//        set("env/wimpy", 10);		//逃跑wimpy (10%)
        set("evil",-20);		//邪惡度 -20 (正的表邪惡, 負表善良)

	set_skill("unarmed",99);	// 技能(自定)
	set_skill("combat",90);		//
	set_skill("fork",70);		//
	set_skill("bagi_fist",30);
	set_skill("horse-steps",20);
	set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
                (:command("exert bagi_fist"):),
         }) );

	
   set("attitude", "peaceful");   //溫和的 NPC。
set("inquiry/join", @NAME
  [1;36m 我的師傅神槍李就在小屋(house)裡面，想拜入八極門就進去(enter)見他吧。[m
NAME );
//set("talk_reply","怎麼辦!?我不小心把小明鎖在秘密基地(base)了.. 你可以幫我救救他嗎?");
      setup();
//      set_element("fire");  //向性: none,metal,plant,wind,ground,water,fire
      add_money("coin", 220);		//帶的錢 古代:coin 現代:dollar 未來則用set("bank/future",數量);
      carry_object("/open/world1/eq/clothes_8")->wear();
      carry_object("/open/world1/wp/woodfist_8")->wield();
}


