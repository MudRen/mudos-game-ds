
inherit NPC;
void make_mark();

void create()
{
	set_name("警衛隊長",({"leader"}) );
	set("long","這個隊長是資深的警衛，他胸上的徽章夠他炫耀一輩子了。\n");		
	set("age",39);
	set("level",32);
	set("race","人類");
	set("evil",-5);
	set("exp_point",0);	// 設定強度, exp及combat_exp會參考到這個值
				// 0 <= exp_point <= 9
				// 內定值為 0 , 請依據強度來設合理的值...
	set("chat_chance",10);
	set("chat_msg",({
		(:command("say 能夠為奧凡迪斯服務，真是我最大的榮幸。"):),
		(:command("hmm"):),
		(: this_object(), "random_move" :),
	})	);

	set("chat_chance_combat", 30);
	set("chat_msg_combat", ({
		(:command("say 為了維護奧凡迪斯的安全，我，警衛隊長，要將作亂者就地正法！！"):),
		(: make_mark :),
	}) );
	set_skill("dodge",30);
	set_skill("block",30);
	set_skill("parry",30);
	set_skill("unarmed",30);
	set_skill("fork",70);

	set("talk_reply","喔，這是座美麗的城市。請記得不要亂丟垃圾喔。");
	setup();

	carry_object(__DIR__"wp/speedlance")->wield();
	carry_object(__DIR__"eq/patrolhelmet")->wear();

	add_money("dollar",50);
}

void init()
{
	object ob = this_player();
	::init();
	if(!this_object()->is_killing(ob->query("id")) && ob->query_temp("quest/aovandis") > 2 + random(3) )
	{
		command("say 你這個作亂者，居然為非作歹，今天被我遇到算你倒楣。");
		ob->add_temp("quest/aovandis",-2);
		kill_ob(this_player());
	}
}


void make_mark()
{
	object *enemy, ob;
	command("say 放下屠刀，立地成佛。棄械投降吧！");

	enemy = query_enemy();
	if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];
	if(!ob) return;

	if( this_object()->query("helpready/"+ob->query("id")) )
		return;

	command("say "+ob->query("name")+"，你是個魔鬼。");
	ob->add_temp("quest/aovandis",1);	// 將欺負市民的人做上標記
	this_object()->set("helpready/"+ob->query("id"),1);	// 與 id 結仇

}
