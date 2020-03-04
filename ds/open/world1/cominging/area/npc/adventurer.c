#include <ansi.h>
inherit NPC;
void create()
{
	set_name("冒險者",({ "adventurer","路人" }));
	set("long","一個從外地而來的冒險家。\n");
	set("level", 10);
	set("age",20);
	set("chat_chance", 8);
	set("chat_msg", ({
  (: random_move :),
}) );
	set_skill("sword",10);
	set_skill("dodge",25);
	set_skill("combat",5);
	setup();
	add_money("coin",150);
	carry_object(__DIR__"wp/longsword")->wield();
	carry_object(__DIR__"eq/swatheshoe")->wear();
}

void init()
{
	call_out("delay",2,this_player());
}

int accept_object(object who, object ob)
{
	if( ob->query("id")!="musci" && ob->query("id")!="golden sand" ) return 0;
	if( !query_temp("uselo"))
	{
		command("ah");
		command("say 原來是這個東西呀....");
		command("thank "+who->query("id"));
		who->add("exp", 400);
		set_temp("uselo",1);
		tell_object(who,HIR"你得到 400 點經驗值。\n"NOR);
		call_out("a",600,this_object());
	}
	else command("bow");
	return 1;
}

void delay(object me)
{
if(!me) return;
	tell_object(me,this_object()->name()+"對你說：請問你知道井底裡面有什麼東西？\n");
	return;
}

void a(object tob)
{
	delete_temp("uselo");
	return;
}
