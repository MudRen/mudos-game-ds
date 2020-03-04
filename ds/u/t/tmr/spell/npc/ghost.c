#include <ansi.h>
inherit NPC;

void create()
{
	set_name("孤魂野鬼",({"ghost"}) );
	set("long",
"一個渾身素衣，不知已死了多少年，至今乃未投胎的野鬼。 \n"
);
	set("gender","男生");
	set("age",100);
	set("level",1);
	set("evil",40);		
	set("race","人類");
	set("chat_chance",10);
	set("chat_msg",({
		"孤魂野鬼飄了過去，又飄了過來....\n",
	})	);

	setup();
}

void die()
{
	object me;
	me=(object)this_object()->query_temp("host");
	me->add_temp("call_ghost",-1);

	command("say 我死了∼∼∼∼∼");
	tell_room(environment(this_object()),this_object()->query("name")+"慘呼一聲，就此煙消雲散了。\n");
	destruct(this_object() );
	return;
}
void init()
{
	add_action("do_hest","hest");

}

int do_hest(string arg)
{
	string dest, cmd;
	object ob,me;

	me=this_player();
	ob=this_object();

	
	if(ob->query_temp("host")!=me->query("id") ) return 0;
	if( !arg || sscanf(arg, "%s to %s", dest, cmd) != 2 )
		return notify_fail("指令格式﹕hest <某鬼魂> to <指令>\n");

	if( !(ob = present(dest, environment(me))) )
		return notify_fail("這裡沒有 " + dest + "。\n");
	if(ob->is_busy() ) return notify_fail(ob->query("name")+"正忙著，沒有空聽你的驅使。\n");

	command(cmd);
	return 1;
}

