// In room118.c 植物園
inherit NPC;

void make_mark();
string s_water();
string s_mother();

void create()
{
	set_name("小男孩",({"boy"}) );
	set("long","他是一位頑皮的小孩。\n");		
	set("age",7);
	set("level",3);
	set("race","人類");
	set("gender","男性");
	set("evil",-5);		// 邪惡度 -5 (正的表邪惡, 負表善良)
	set("exp_point",0);	// 設定強度, exp及combat_exp會參考到這個值
				// 0 <= exp_point <= 9
				// 內定值為 0 , 請依據強度來設合理的值...
set_temp("apply/hit",-20);      //弱化命中率
set_temp("apply/dodge",-20);    //弱化閃躲率
	set("chat_chance",3);
	set("chat_msg",({
		(:command("say 好棒喔！這個週末媽媽要帶我去海水浴場玩耶。"):),
		(:command("laugh"):),
		(: this_object(), "random_move" :),
	})	);

	set("inquiry/海水浴場",(: s_water :) );
	set("inquiry/媽媽",(: s_mother :) );
	set("inquiry/媽咪",(: s_mother :) );
	set("inquiry/mother",(: s_mother :) );

	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		(: make_mark :),
	}) );
	set_skill("dodge",5);
	set_skill("block",4);
	set_skill("parry",4);
	set_skill("unarmed",4);

	set("talk_reply","呵，植物園裡有好多好玩的東西喔。");
	setup();

	add_money("dollar",5);
}

void make_mark()
{
	object *enemy, ob;

	command("say 媽咪•••救命啊！！！！");

	enemy = query_enemy();
	if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];
	if(!ob) return;

	if( this_object()->query("helpready/"+ob->query("id")) )
		return;

	command("say "+ob->query("name")+"你會受到報應的。");
	ob->add_temp("quest/aovandis",1);	// 將欺負市民的人做上標記
	this_object()->set("helpready/"+ob->query("id"),1);	// 與 id 結仇

}

string s_water()
{
	return "哦？你是說海水浴場嗎？我想你應該問問我媽咪才對。";
}

string s_mother()
{
	return "我媽咪？咦？我媽咪怎麼不見了？你知道她在哪裡嗎？";
}
