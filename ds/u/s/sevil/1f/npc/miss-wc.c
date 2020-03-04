// In 1f/17.c 化妝品店
inherit NPC;
void make_mark();

void create()
{
    set_name("化妝品店小姐",({"miss"}) );
    set("long","一個長的十分漂亮的百貨公司小姐。\n");     
    set("age",20);
	set("level",10);
	set("race","人類");
    set("gender","女性");
	set("evil",-5);		// 邪惡度 -5 (正的表邪惡, 負表善良)
	set("exp_point",0);	// 設定強度, exp及combat_exp會參考到這個值
				// 0 <= exp_point <= 9
				// 內定值為 0 , 請依據強度來設合理的值...
	set("chat_chance",2);
	set("chat_msg",({
        (:command("say 請隨便參觀！"):),
		(:command("smile"):),
	})	);

	set("chat_chance_combat", 40);
	set("chat_msg_combat", ({
		(: make_mark :),
	}) );
	set_skill("dodge",10);
	set_skill("block",10);
	set_skill("parry",10);
	set_skill("unarmed",10);

	set("talk_reply","喔，這是座美麗的城市。請記得不要亂丟垃圾喔。");


	setup();

	add_money("dollar",200);
}
void init()
{
        call_out("delay",2,this_player());
}
void delay(object me)
{
    tell_object(me,this_object()->name()+"對你說：最近有新的化妝品喔!!\n");
}

void make_mark()
{
	object *enemy, ob;
	command("say 哇！不要打我！");

	enemy = query_enemy();
	if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];
	if(!ob) return;

	if( this_object()->query("helpready/"+ob->query("id")) )
		return;

	command("say "+ob->query("name")+"，你是個魔鬼。");
	ob->add_temp("quest/aovandis",1);	// 將欺負市民的人做上標記
	this_object()->set("helpready/"+ob->query("id"),1);	// 與 id 結仇

}
