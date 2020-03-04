inherit NPC;
void create()
{
	set_name("小茹比",({"kid ruby","kid","ruby"}) );
	set("long",@LONG
一個天真的小孩子，正在玩著扮演國王建立國家的遊戲。
LONG);
	set("age",18);
	set("level",12);
	set("race","human");
	set("evil",-15);
	set("exp_point",2);	// 設定強度, exp及combat_exp會參考到這個值
				// 0 <= exp_point <= 9
				// 內定值為 0 , 請依據強度來設合理的值...

	set("talk_reply","看到國王還不下跪??");
	setup();
	carry_object(__DIR__"../wp/wood_staff_5")->wield();
	carry_object(__DIR__"../eq/cloth_cloak_3")->wear();
	carry_object(__DIR__"../eq/cloth_pants_5")->wear();

	add_money("dollar",90);
}

void die()
{
	message_vision("$N臨死之前說: 嗚..你欺負我..我要叫其他國家通緝你!!\n",this_object());
	::die();
}
