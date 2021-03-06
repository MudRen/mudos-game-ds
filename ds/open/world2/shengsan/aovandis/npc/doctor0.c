// In room085.c 市立醫院
inherit NPC;

void make_mark();

void create()
{
	set_name("內科醫師",({"doctor"}) );
	set("long","他是一位有著高超醫術的醫師，對內科相當的在行。\n");		
	set("age",28);
	set("level",8);
    set("con",4);
	set("race","人類");
	set("gender","男性");
	set("evil",-15);	// 邪惡度 -15 (正的表邪惡, 負表善良)
	set("exp_point",0);	// 設定強度, exp及combat_exp會參考到這個值
				// 0 <= exp_point <= 9
				// 內定值為 0 , 請依據強度來設合理的值...
	set("chat_chance",5);
	set("chat_msg",({
		(:command("say 救人是我的天職，我以當醫師為榮！"):),
		(:command("smile"):),
	})	);

	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: make_mark :),
	}) );
	set_skill("dodge",10);
	set_skill("block",10);
	set_skill("parry",10);
	set_skill("unarmed",10);

	set("talk_reply","喔，這是座美麗的城市。請記得不要亂丟垃圾喔。");
	setup();

	add_money("dollar",100);
}

void make_mark()
{
	object *enemy, ob;
	command("say 哇！救命阿！");

	enemy = query_enemy();
	if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];
	if(!ob) return;

	if( this_object()->query("helpready/"+ob->query("id")) )
		return;

	command("say "+ob->query("name")+"你這個瘋子。");
	ob->add_temp("quest/aovandis",1);	// 將欺負市民的人做上標記
	this_object()->set("helpready/"+ob->query("id"),1);	// 與 id 結仇

}
