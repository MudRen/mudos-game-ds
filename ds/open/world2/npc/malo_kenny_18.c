#include <ansi.h>
inherit NPC;
void create()
{
	set_name("肯尼",({"kenny hsieh","kenny","hsieh"}) );
	set("long",@LONG
他是泥巴幫的財政顧問，專門負責維持泥巴幫的收支平衡。
LONG);
	set("age",28);
	set("title",HIY"泥巴黑手"NOR);
	set("level",18);
	set("race","human");
	set("evil",-10);
	set("exp_point",2);	// 設定強度, exp及combat_exp會參考到這個值
				// 0 <= exp_point <= 9
				// 內定值為 0 , 請依據強度來設合理的值...

	set("talk_reply","唉..最近景氣真差。");
	setup();

	carry_object(__DIR__"../wp/iron_dagger_10")->wield();
	carry_object(__DIR__"../eq/leather_boots_6")->wear();
	carry_object(__DIR__"../eq/cloth_pants_8")->wear();
	carry_object(__DIR__"../eq/cloth_clothes_5")->wear();
	add_money("dollar",2250);
}

void die()
{
	message_vision("$N臨死之前說: 錢果然不是萬能的!!\n",this_object());
	::die();
}
