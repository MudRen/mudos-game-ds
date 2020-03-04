inherit NPC;
void greeting(object ppl);
void create()
{
	set_name("陳銘崧",({"james chen","chen","james"}) );
	set("long",@LONG
一個研究所學生，十分喜愛搖滾音樂，又很會耍寶，所以有個外號叫做寶哥。
LONG);
	set("age",26);
	set("level",16);
	set("race","human");
	set("evil",-15);
	set("exp_point",2);	// 設定強度, exp及combat_exp會參考到這個值
				// 0 <= exp_point <= 9
				// 內定值為 0 , 請依據強度來設合理的值...

	set("talk_reply","中華大學真是母豬賽貂蟬，唉。");
	setup();

	carry_object(__DIR__"../eq/cloth_clothes_8")->wear();
	carry_object(__DIR__"../eq/cloth_boots_7")->wear();
	carry_object(__DIR__"../eq/cloth_pants_9")->wear();

	add_money("dollar",370);
}

void die()
{
	message_vision("$N臨死之前叫了一聲: OH~~ Check Out!!\n",this_object());
	::die();
}
