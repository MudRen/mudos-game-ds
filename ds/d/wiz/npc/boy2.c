// 任務範例人物 
// by Luky 19993.20
#include <ansi.h>
inherit NPC;
void create()
{
//=========================基本設定==========================

        set_name( "小華", ({ "boy"}));
        set("long", "一個小男孩, 他看起來很慌張, 你可以試試看和他說說話(talk with boy)。\n"
        );
        set("level",2);
        set("gender", "男性");
        set("race", "人類");
        set("age", 6);
        set("exp",300);			//玩家殺死會得到exp/10 (可免)
        				//建議不要自己設exp. 由系統決定
        				//以免不同wiz寫的mob 會出現太大的差異
        				
        set("str",5);			//設定屬性(可免)
        set("dex",6);			//也可以只設定 level
        set("con",5);			//其他沒設定的屬性系統就會自動產生,
        set("int",6);			//即使是相同的level也會有不同屬性.
        
        set("combat_exp",200);		//戰熟(約在mob level的100倍左右為宜)
        set("env/wimpy", 10);		//逃跑wimpy (10%)
        set("evil",-30);		//邪惡度 20 (正的表邪惡, 負表善良)

	set_skill("blade",20);		// 技能(自定)
	set_skill("parry",20);		//
	set_skill("dodge",20);		//

   set("attitude", "peaceful");   //溫和的 NPC。
set("inquiry/name", @LONG
  [1;36m 我叫做小華.. 請多指教!![m
LONG );
set("inquiry/base", "[1;36m 秘密基地就在旁邊那個地洞(hole)裡..快點去救他吧!![m\n");
set("inquiry/hole", "地洞? 就在你後面啊..打 go hole 就可以進去了!!\n");
set("talk_reply","怎麼辦!?我不小心把小明鎖在秘密基地(base)了.. 你可以幫我救救他嗎?");
      setup();
      add_money("coin", 20);		//帶的錢
      carry_object("/u/l/luky/npc/item/dump");
}


