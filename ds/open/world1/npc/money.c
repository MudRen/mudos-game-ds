#include <ansi.h>
inherit NPC;
void create()
{
 set_name("財神",({"god"}));
 set("long",@LONG
就是財神咩
LONG
    );
 set("attitude", "peaceful");
 set("age",26);
 set("evil",-10);
 set("gender","男性");
 set("level",9);
 set_skill("hammer", 20);
 setup();
 carry_object(__DIR__"../eq/cloth")->wear();
}

int accept_object(object who,object ob)
{
	object obj,me;
	me=this_player();
	obj=this_object();
	if(ob->name()=="mark")
	{
		if(obj->is_busy() )
		{
			command("whisper "+who->query("id")+" 請閣下稍待一下...");
			return 0;
		}
		message_vision("$N給了財神一個"+ob->query("name")+"。\n",who);
	
		obj->start_busy(5);
		destruct(ob);
		command("smile");
		add_money("coin",10000);
		command("give 10000 coin to "+me->query("id"));
		return 1;
	}
}


