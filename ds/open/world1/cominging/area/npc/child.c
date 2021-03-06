#include <ansi.h>
inherit NPC;
void create()
{
	set_name("小孩",({ "child" }));
	set("long","一個笑得好開心的小孩，他似乎有些煩惱。\n");
	set("level", 1);
    set("age",5);
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
	if( !query_temp("toy") )
		message_vision(ob->name()+"對$N說："+RANK_D->query_respect(me)+"幫幫我找找我的玩具(toy)。\n",me);
	return 1;
}

int accept_object(object who, object ob)
{
	object tob, a;
	tob = this_object();
	if( ob->query("id")!="toy" || query_temp("toy") ) return 0;

	command("thank "+who->query("id"));
	command("say 謝謝你了，"+RANK_D->query_respect(who)+"！\n");
	who->add("exp", 700);
	set_temp("toy",1);
	tell_object(who,HIR"你得到 700 點經驗值。\n"NOR);
	call_out("delay",600,this_object());
	set("long","一個笑的很開心的小孩, 正玩著他手上的玩具.\n");

	return 1;
}

void delay(object tob)
{
	delete_temp("toy");
	set("long","一個笑得好開心的小孩，他似乎有些煩惱。\n");
	return;
}
