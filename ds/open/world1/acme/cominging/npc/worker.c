#include <ansi.h>
inherit NPC;

void create()
{
	set_name("�u�H", ({ "worker" }));
	set("long",
		"�@�Ӧb�u�@���u�H�A�L�ݰ_�Ӧ��������A�n���u�@�����֪��ˤl�A\n"
		"�Y�O�A���L�ǹ��y�A�L�|�P�§A���C\n");
	set("level",7);
	set("age",24+random(3));
	set("title","�u�@");
	set("chat_chance",10);
	set("chat_msg",({
  (: command,"sweat" :),
  (: command,"addoil" :),
  name()+"�V�O�ԾĪ��u�@�C\n",
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