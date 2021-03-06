#include <ansi.h>
inherit NPC;
void create()
{
	set_name("小孩群",({ "children" }));
	set("long","一團笑得好開心的小孩，他們好像在討論什麼東西。\n");
	set("level", 1);
	set("age",20);
	set("chat_chance", 8);
	set("chat_msg", ({
  (: random_move :),
}));
	setup();
	add_money("coin",150);
	carry_object(__DIR__"wp/woodensword")->wield();
	carry_object(__DIR__"eq/sandal")->wear();
}

int talk_action(object me)
{
	object ob;
	ob = this_object();
	if( !query_temp("musci") )
		message_vision(ob->name()+"對$N說："+RANK_D->query_respect(me)+"幫幫我刮刮看那井底的蘚苔吧 !\n",me);
	return 1;
}

int accept_object(object who, object ob)
{
	object tob, a;
	int exp;
	tob = this_object();
	if( ob->query("id")!="musci" || query_temp("toy") ) return 0;

	command("thank "+who->query("id"));
	command("bow");
	exp=25 - who->query("level");
	if(exp<1) exp=200+random(50);
	else exp=250+exp*20+random(exp*10);
	who->add("exp", exp);
	set_temp("toy",1);
	tell_object(who,HIR"你得到 "+exp+" 點經驗值。\n"NOR);
	set("long","一團很開心的小孩, 正仔細的觀察手上的東西.\n");

	return 1;
}

void reset()
{
	delete_temp("toy");
	set("long","一團笑得好開心的小孩，他們好像在討論什麼東西。\n");
	return;
}