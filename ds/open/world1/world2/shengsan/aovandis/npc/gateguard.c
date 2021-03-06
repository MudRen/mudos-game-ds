// In room009.c 奧凡迪斯正城門 room016.c 東側城門 room033.c 西側城門
inherit NPC;
void make_mark();

void create()
{
	set_name("憲兵",({"military policeman","policeman"}) );
	set("long","一個高大的憲兵正在這裡監視著進出城門的可疑人物。\n");		
	set("age",25);
	set("level",26);
	set("race","人類");
	set("evil",-1);
	set("exp_point",1);	// 設定強度, exp及combat_exp會參考到這個值
				// 0 <= exp_point <= 9
				// 內定值為 0 , 請依據強度來設合理的值...
	set("chat_chance",10);
	set("chat_msg",({
		(:command("say 歡迎來到奧凡迪斯，這是座美麗的城市，請不要做出違法的事情喔！"):),
		(:command("hmm"):),
	})	);

	set("chat_chance_combat", 40);
	set("chat_msg_combat", ({
		(:command("say 為了維護奧凡迪斯的安全，我絕對不會讓你逍遙法外！！"):),
		(: make_mark :),
	}) );
	set_skill("dodge",60);
	set_skill("block",20);
	set_skill("parry",20);
	set_skill("unarmed",20);
	set_skill("axe",40);

	set("talk_reply","喔，這是座美麗的城市。請記得不要亂丟垃圾喔。");
	setup();

	carry_object(__DIR__"wp/typicalaxe")->wield();
	carry_object(__DIR__"eq/typicalshield")->wear();
	carry_object(__DIR__"eq/typicalboot")->wear();

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
	else if(ob->query("evil") > 600 && random(2))
		command("say "+ob->query("name")+"，這裡不歡迎邪惡之人，請儘早離開奧凡迪斯吧。");
}

void make_mark()
{
	object *enemy, ob;
	command("say 你活膩啦！納命來。");

	enemy = query_enemy();
	if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];
	if(!ob) return;

	if( this_object()->query("helpready/"+ob->query("id")) )
		return;

        command("say 去死吧。"); // change msg by alickyuen
	ob->add_temp("quest/aovandis",1);	// 將欺負市民的人做上標記
	this_object()->set("helpready/"+ob->query("id"),1);	// 與 id 結仇

}
