// In room063.c 第一商街
inherit NPC;

void make_mark();

void create()
{
	set_name("市民",({"citizen"}) );
	set("long","他身穿筆挺的西裝，是個上班族。\n");		
	set("age",45);
	set("level",5);
    set("con",3);
	set("race","人類");
	set("gender","男性");
	set("evil",-5);		// 邪惡度 -5 (正的表邪惡, 負表善良)
	set("exp_point",0);	// 設定強度, exp及combat_exp會參考到這個值
				// 0 <= exp_point <= 9
				// 內定值為 0 , 請依據強度來設合理的值...
set_temp("apply/hit",-20);      //弱化命中率
set_temp("apply/dodge",-20);    //弱化閃躲率
	set("chat_chance",5);
	set("chat_msg",({
		(:command("say 天有不測風雲，人有旦夕禍福。走也要走得瀟灑，你說對不對阿！"):),
		(:command("smile"):),
		(: this_object(), "random_move" :),
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
	command("say 救命阿！");

	enemy = query_enemy();
	if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];
	if(!ob) return;

	if( this_object()->query("helpready/"+ob->query("id")) )
		return;

	command("say "+ob->query("name")+"你是個魔鬼。");
	ob->add_temp("quest/aovandis",1);	// 將欺負市民的人做上標記
	this_object()->set("helpready/"+ob->query("id"),1);	// 與 id 結仇

}
