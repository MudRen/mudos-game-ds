#include <path.h>
#include <ansi.h>
inherit NPC;

void sum_prot();
void stance();

void create()
{
	set_name("巫毒教教主", ({"voodoo leader","voodoo","leader"}) );
	set("race", "人類");
	set("gender", "女性");
	set("level",74);
	set("class","caster");
	set("age", 30);
	set("long", "她是巫毒教的教主\n");
	set("combat_exp", 180000);

//	set_skill("dodge",170);
//        set_skill("blade",190);
	set( "inquiry", ([
                  "voodoo" : "巫毒教是這個世界上數一數二的大教.\n",
                  "巫毒教" : "巫毒教是這個世界上數一數二的大教.\n",
                ]) );

	set("chat_chance_combat", 35);
	set("chat_msg_combat", ({
		(: sum_prot :),
	        (: stance :)
	}) );


	setup();
	add_money("coin",740);
	carry_object(SHENGSAN+"voodoo/eq/cloak")->wear();
	carry_object(SHENGSAN+"voodoo/eq/moonblade")->wield();
}

void sum_prot()
{
	object *enemy, ob, prot;

	if(this_object()->query("helpready")==1)
	return;
	enemy = query_enemy();
	if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];

	tell_room(environment(this_object()),"\n貼身護法來護駕了!!\n\n");

	ob->set_temp("voodoo",1);
	prot = new(__DIR__"protector1");
	prot->move(environment(this_object()));
	prot = new(__DIR__"protector1");
	prot->move(environment(this_object()));
	ob->delete_temp("voodoo",1);
	this_object()->set("helpready",1);
}

void stance()
{
	object *enemy, ob;
	int damage, comexp, obexp;

	enemy = query_enemy();
	if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];

	if(this_object()->query("stance")==1)
	{ this_object()->set("stance",0); return; }

	command("say "+ob->query("name")+"，你這個小子，讓你看看什麼叫做巫毒教。");

	tell_room(environment(this_object()),"\n巫毒教教主突然身子往後退了一步\n");
	tell_room(environment(this_object()),"\n你看到她的雙手合抱於胸前，只見她雙手被五種光芒所圍繞著。\n");

	obexp = random(ob->query("combat_exp")/100);
	comexp = this_object()->query("combat_exp")/100;

	if( obexp < comexp )
	{
	    damage = query_temp("apply/damage")+query_temp("apply/hit")+random(500);
	    message_vision(HIR"\n$N突然被五道強勁的氣流打中，被彈到牆壁之上了。"NOR"("HIM+damage+NOR")\n",ob);
	    this_object()->set("stance",1);
	    ob->add("hp",-damage);
	}
	else message_vision("\n五道強勁的氣流直直攻向$N，結果被$N機靈的化解了。\n",ob);
}

void die()
{
	object ob;
	if( !ob = query_temp("last_damage_from") )
	    ob = this_player(1);
	ob->set_temp("voodoo",1);
	if( !ob ) return;
	command("say 可惡的 "+ob->query("name")+" 你會後悔的!!!\n");
	::die();
	destruct(this_object());
}
