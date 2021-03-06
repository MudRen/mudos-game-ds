#include <ansi.h>
inherit NPC;

void create()
{
	set_name("劉躍德",({ "ua-da liu","liu","ua-da" }));
	set("long",
       "他是官府裡面的兵部尚書，他手上擁有許\多的兵力，他常常在\n"
		"兵房裡面去徵招各種人士前來投軍，看他手上的簿子厚度，大\n"
		"約就可以猜出現在有多少人馬了，劉躍德是使刀的高手，他常\n"
		"常在後院練刀，刀法純熟穩重，絲毫不漏破綻。\n");
	set("age",40+random(10));
	set("level",30);
	set("title", HIB"兵部尚書"NOR);
	set("chat_chance",9);
	set("chat_msg",({
  name()+"最近徵招的兵可真是越來越壯啦！\n",
  name()+"喃喃自語: 金山寨不知道該怎麼解決才好！\n",
  name()+"向你抱拳道: 這位請了！\n",
  (: command,"hmm" :),
  name()+"在房中走來走去，不知在思籌什麼。\n",
}));
	set("chat_chance_combat",10);
	set("chat_msg_combat", ({
	   (:command("kick"):),
}));

	set_skill("unarmed",70);
	set_skill("blade",70+random(30));
	set_skill("dodge",60);
	set_skill("parry",70);

	setup();
	carry_object(__DIR__"eq/cloth4")->wear();
	carry_object(__DIR__"wp/blade1")->wield();
	carry_object(__DIR__"eq/boots1")->wear();
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
