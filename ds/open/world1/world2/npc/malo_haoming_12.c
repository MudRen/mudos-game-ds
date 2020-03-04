inherit NPC;
void create()
{
	set_name("應皓明",({"Haoming in","haoming","in"}) );
	set("long",@LONG
一個無所是事的高職生，已經失業了一段時間，興趣是打電動和打籃球，
正忙著到處找女生搭訕。
LONG);
	set("age",18);
	set("level",12);
	set("race","human");
	set("evil",-15);
	set("exp_point",2);	// 設定強度, exp及combat_exp會參考到這個值
				// 0 <= exp_point <= 9
				// 內定值為 0 , 請依據強度來設合理的值...

	set("talk_reply","猜猜看我今天穿什麼顏色的內褲啊。");
	setup();

	carry_object(__DIR__"../eq/cloth_clothes_7")->wear();
	carry_object(__DIR__"../eq/cloth_boots_6")->wear();
	carry_object(__DIR__"../eq/cloth_pants_7")->wear();

	add_money("dollar",140);
}

void die()
{
	message_vision("$N臨死之前說: 有種就來挑格鬥天王!!\n",this_object());
	::die();
}
