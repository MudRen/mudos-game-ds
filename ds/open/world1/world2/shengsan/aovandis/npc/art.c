inherit NPC;

void make_mark();

void create()
{
	set_name("亞特",({"art"}) );
	set("long","亞特是奧凡迪斯的守衛隊總司令，他的領導風格被其他守衛隊的成員所肯定。\n");		
	set("age",40);
	set("level",30);
	set("attitude", "heroism");
	set("race","人類");
	set("evil",-20);	// 邪惡度 -20 (正的表邪惡, 負表善良)
	set("exp_point",3);	// 設定強度, exp及combat_exp會參考到這個值
				// 0 <= exp_point <= 9
				// 內定值為 0 , 請依據強度來設合理的值...
	set("chat_chance",5);
	set("chat_msg",({
		(:command("say 守護這座美麗的城市是我的責任！"):),
		(:command("smile"):),
	})	);

	set("chat_chance_combat", 30);
	set("chat_msg_combat", ({
		(:command("say 為了維護奧凡迪斯的安全，我，守衛隊總司令，要將作亂者就地正法！！"):),
		(: make_mark :)
	}) );
	set_skill("dodge",60);
	set_skill("block",60);
	set_skill("parry",50);
	set_skill("unarmed",80);
	set_skill("sword",80);

	set("talk_reply","喔，這是座美麗的城市。請記得不要亂丟垃圾喔。");
	set("inquiry/name","你好，我是奧凡迪斯的守衛隊總司令，名叫亞特");
	setup();

	carry_object(__DIR__"wp/artsword")->wield();
	carry_object(__DIR__"eq/drangonshield")->wear();
	add_money("dollar",50);
}

void init()
{
	object ob = this_player();
	::init();
	if(!this_object()->is_killing(ob->query("id")) && ob->query_temp("quest/aovandis") > 3 + random(3) )
	{
		command("say 你這個作亂者"+ob->name(1)+"，居然為非作歹，今天被我遇到算你倒楣。");
		ob->add_temp("quest/aovandis",-2);
		kill_ob(this_player());
	}
}

void make_mark()
{
	object *enemy, ob;
	command("say 喝！看招！");

	enemy = query_enemy();
	if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];
	if(!ob) return;

	if( this_object()->query("helpready/"+ob->query("id")) )
		return;

	command("say "+ob->query("name")+"，你這個該死的傢伙。");
	ob->add_temp("quest/aovandis",1);	// 將欺負市民的人做上標記
	this_object()->set("helpready/"+ob->query("id"),1);	// 與 id 結仇

}
