#include <ansi.h>
inherit NPC;
void create()
{
	set_name("史巴克",({"spock lin","spock","lin"}) );
	set("long",@LONG
他是泥巴幫的資深軍師，專門負責訓練泥巴幫新進幹部。
LONG);
	set("age",28);
	set("title",HIY"壞蟑螂"NOR);
	set("level",18);
	set("race","human");
	set("evil",-10);
	set("exp_point",2);	// 設定強度, exp及combat_exp會參考到這個值
				// 0 <= exp_point <= 9
				// 內定值為 0 , 請依據強度來設合理的值...

	set("talk_reply","我目前正在專心於醫學訓練，我的網頁是 http://bbs.csmc.edu.tw/spock/。");
	setup();

	carry_object(__DIR__"../wp/iron_hammer_10")->wield();
	carry_object(__DIR__"../eq/leather_boots_6")->wear();
	carry_object(__DIR__"../eq/cloth_pants_8")->wear();
	carry_object(__DIR__"../eq/cloth_clothes_5")->wear();
	add_money("dollar",1430);
}

void die()
{
	message_vision("$N臨死之前說: 蟑螂是打不死的!!\n",this_object());
	::die();
}
