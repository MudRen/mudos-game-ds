#include <ansi.h>
inherit NPC;

void create()
{
	set_name("工人", ({ "worker" }));
	set("long",
		"一個在工作的工人，他看起來汗挾滿身，好像工作的挺累的樣子，\n"
		"若是你給他些鼓勵，他會感謝你的。\n");
	set("level",7);
	set("age",24+random(3));
	set("title","工作");
	set("chat_chance",10);
	set("chat_msg",({
  (: command,"sweat" :),
  (: command,"addoil" :),
  name()+"努力勤奮的工作。\n",
  (: command,"sweat2" :),
}));
	set("chat_chance_combat",10);
	set("chat_msg_combat", ({
	   (:command("kick"):),
}));

	setup();
}

void die()
{
	int i;
	object ob;
	if( !ob = query_temp("last_damage_from") )
		ob = this_player(1);
	if( !ob ) 
	{
		::die();
		return;
	}
	i=ob->query_temp("SKYCITY/jail");
	ob->set_temp("SKYCITY/jail",i+1);
	::die();
	//destruct(this_object());
	return;
}