
inherit NPC;
void make_mark();

void create()
{
	set_name("警衛",({"guard"}) );
	set("long","你看到一個年輕的警衛，他正在為兩個月前出現的竊盜集團傷腦筋。\n");		
	set("age",23);
	set("level",20);
	set("race","人類");
	set("evil",-5);
	set("exp_point",0);	// 設定強度, exp及combat_exp會參考到這個值
				// 0 <= exp_point <= 9
				// 內定值為 0 , 請依據強度來設合理的值...
	set("chat_chance",5);
	set("chat_msg",({
		(:command("say 歡迎來到奧凡迪斯，這是座美麗的城市，請盡興的玩吧！"):),
		(:command("hmm"):),
	})	);

	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		(:command("say 為了維護奧凡迪斯的安全，我身為守衛隊隊員，勢必要將作亂者就地正法！！"):),
		(: make_mark :),
	}) );
	set_skill("dodge",20);
	set_skill("block",20);
	set_skill("parry",20);
	set_skill("unarmed",20);
	set_skill("sword",20);

	set("talk_reply","嗯，最近附近有些宵小橫行，你要多加留意。");
	setup();

//	carry_object(__DIR__"wp/typicalsword")->wield();
	carry_object(__DIR__"eq/typicalshield")->wear();
	carry_object(__DIR__"eq/typicalboot")->wear();

	add_money("dollar",50);
}

void init()
{
	object ob = this_player();
	::init();
	if(!this_object()->is_killing(ob->query("id")) && ob->query_temp("quest/aovandis") > 1 + random(3) )
	{
		command("say 你這個作亂者，居然為非作歹，今天被我遇到算你倒楣。");
		ob->add_temp("quest/aovandis",-2);
		kill_ob(this_player());
	}

}

void make_mark()
{
	object *enemy, ob;

	enemy = query_enemy();
	if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];
	if(!ob) return;

	if( this_object()->query("helpready/"+ob->query("id")) )
		return;

	message_vision("$N慌張的拿起無線電請求支援。\n",this_object());
	ob->add_temp("quest/aovandis",1);	// 將欺負市民的人做上標記
	this_object()->set("helpready/"+ob->query("id"),1);	// 與 id 結仇

}
