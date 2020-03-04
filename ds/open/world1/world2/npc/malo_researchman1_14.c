#include <ansi.h>
inherit NPC;
void create()
{
	set_name("康德溫",({"kenderwen"}) );
	set("long",@LONG
他是杜馬集團生化研究室的特派員，到世界各地收集擁有特殊能力的
生物樣本。
LONG);
	set("age",34);
	set("title","生化研究員");
	set("level",14);
	set("race","human");
	set("evil",-10);
	set("exp_point",2);	// 設定強度, exp及combat_exp會參考到這個值
				// 0 <= exp_point <= 9
				// 內定值為 0 , 請依據強度來設合理的值...

	set("talk_reply","聽說這附近有種奇特的紅冠鳥能帶給人們幸運。");
	setup();

	//carry_object(__DIR__"../wp/iron_dagger_10")->wield();
	carry_object(__DIR__"../eq/life_glasses")->wear();
	carry_object(__DIR__"../eq/leather_boots_6")->wear();
	carry_object(__DIR__"../eq/cloth_gloves_3")->wear();
	carry_object(__DIR__"../eq/cloth_pants_8")->wear();
	carry_object(__DIR__"../eq/cloth_clothes_5")->wear();
	add_money("dollar",950);
}
