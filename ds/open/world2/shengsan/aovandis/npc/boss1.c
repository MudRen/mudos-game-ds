// In room078.c 珠寶店
inherit NPC;
inherit SELLMAN;

void make_mark();

void create()
{
	set_name("珠寶店老闆",({"boss"}) );
	set("long","她一位穿著體面的珠寶店老闆。\n");		
	set("age",32);
	set("level",15);
	set("race","人類");
	set("gender","女性");
	set("evil",-5);		// 邪惡度 -5 (正的表邪惡, 負表善良)
	set("exp_point",0);	// 設定強度, exp及combat_exp會參考到這個值
				// 0 <= exp_point <= 9
				// 內定值為 0 , 請依據強度來設合理的值...
	set("chat_chance",5);
	set("chat_msg",({
		(:command("say 一身的珠光寶氣才是人生嘛。嗯，這個不錯喔，那個也不錯啦"):),
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

	set("sell_list",([
		__DIR__"eq/necklace0"	:30,
		__DIR__"eq/ring0"	:30,
	])	);

	setup();

	add_money("dollar",200);
}

void init() 
{
	::init();
	add_action("do_list","list");
	add_action("do_buy" ,"buy");
}

void make_mark()
{
	object *enemy, ob;
	command("say 救命！來人阿！");

	enemy = query_enemy();
	if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];
	if(!ob) return;

	if( this_object()->query("helpready/"+ob->query("id")) )
		return;

	command("say "+ob->query("name")+"，你是個魔鬼。");
	ob->add_temp("quest/aovandis",2);	// 將欺負市民的人做上標記
	this_object()->set("helpready/"+ob->query("id"),1);	// 與 id 結仇

}
