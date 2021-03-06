
inherit NPC;
void make_mark();

void create()
{
	set_name("警衛",({"guard"}) );
    set("long","一個年輕的警衛，正在巡邏著。\n");       
	set("age",23);
	set("level",20);
	set("race","人類");
	set("evil",-5);
	set("exp_point",0);	// 設定強度, exp及combat_exp會參考到這個值
				// 0 <= exp_point <= 9
				// 內定值為 0 , 請依據強度來設合理的值...
	set("chat_chance",5);
	set("chat_msg",({
        (:command("say 這裡不是旅遊區，請不要在這裡逗留喔！"):),
		(:command("hmm"):),
	})	);

	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
        (:command("say 為了維護治安，我一定會把做亂者就地正法！！"):),
		(: make_mark :),
	}) );
	set_skill("dodge",20);
	set_skill("block",20);
	set_skill("parry",20);
	set_skill("unarmed",20);
	set_skill("sword",20);

    set("talk_reply","嗯，最近附近有些宵小橫行，你要多加留意。");
	setup();


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
