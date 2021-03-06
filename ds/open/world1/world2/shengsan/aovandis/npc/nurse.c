// In room085.c 市立醫院 room102.c 市立醫院開刀房
inherit NPC;

void make_mark();

void create()
{
	set_name("護士",({"nurse"}) );
	set("long","一位美麗的小姐親切的向您打聲招呼。\n");		
	set("age",22);
	set("level",9);
    set("con",4);
	set("race","人類");
	set("gender","女性");
	set("evil",-15);	// 邪惡度 -15 (正的表邪惡, 負表善良)
	set("exp_point",0);	// 設定強度, exp及combat_exp會參考到這個值
				// 0 <= exp_point <= 9
				// 內定值為 0 , 請依據強度來設合理的值...
set_temp("apply/dodge",-10);    //弱化閃躲率
set_temp("apply/hit",-10);      //弱化命中率
	set("chat_chance",5);
	set("chat_msg",({
		(:command("say 能為病人服務是我一生中最快樂的事！"):),
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

	enemy = query_enemy();
	if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];
	if(!ob) return;

	if(random(30)%2)
		command("say 哇！救命阿！");
	else
		command("slap "+ob->query("id"));

	if( this_object()->query("helpready/"+ob->query("id")) )
		return;

	command("say "+ob->query("name")+"，你是個魔鬼。");
	ob->add_temp("quest/aovandis",1);	// 將欺負市民的人做上標記
	this_object()->set("helpready/"+ob->query("id"),1);	// 與 id 結仇

}
