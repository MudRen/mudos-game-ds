// by Luky 19993.20
#include <ansi.h>
inherit NPC;
void create()
{
//=========================基本設定==========================

        set_name("壯漢", ({"strong man","man"}));
        set("long",@LONG
一個十分強壯的男人，看來外家硬功有不錯的底子，應該曾經拜
於名師門下。不知為何會淪落到此表演胸口碎大石等雜藝餬口，看了
讓同為練武者的你有點心酸。

LONG
        );
        set("gender", "男性");
        set("race", "human");
 	set("level",15);
        set("age", 30);
        //set("exp",300);		//玩家殺死會得到exp/10 (可免)
        				//建議不要自己設exp. 由系統決定
        				//以免不同wiz寫的mob 會出現太大的差異
			
//        set("env/wimpy", 10);		//逃跑wimpy (10%)
        set("evil",-20);		//邪惡度 -20 (正的表邪惡, 負表善良)

	set_skill("unarmed",99);	// 技能(自定)
	set_skill("combat",90);		//

   set("attitude", "peaceful");   //溫和的 NPC。
set("inquiry/name", @NAME
  [1;36m 我叫做龍天白.. 請多指教!![m
NAME );
set("inquiry/龍天白", "這是我的名字, 有問題嗎？");
//set("talk_reply","怎麼辦!?我不小心把小明鎖在秘密基地(base)了.. 你可以幫我救救他嗎?");
      setup();
//      set_element("ground");    //向性: none,metal,plant,wind,ground,water,fire
      add_money("coin", 320);		//帶的錢 古代:coin 現代:dollar 未來則用set("bank/future",數量);
      carry_object("/open/world1/eq/clothes_8")->wear();
      carry_object("/open/world1/wp/hammer_16")->wield();
}


