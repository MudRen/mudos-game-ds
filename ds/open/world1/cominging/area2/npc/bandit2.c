#include <ansi.h>
inherit NPC;

string drink();
string eat();

void create()
{
	set_name("強盜嘍囉", ({ "bandit","golden dragon" }) );
	set("long","一個金龍寨的強盜嘍囉，他臉上似乎殺氣重重的樣子。\n");

	set("level",34+random(2));
        set("age",30+random(3));
        set("title",HIY"金"HIR"龍"HIM"寨"NOR);
	set("combat_exp", 31000);
	set("chat_chance", 10);
        set("chat_msg", ({
  (: random_move :),
  (: command,"snort" :),
}));
	set("chat_chance_combat", 14);
	set("chat_msg_combat", ({
  (: command,"angry" :),
}));
	set("attitude", "aggressive"); //主動攻擊,生性好鬥的的 NPC。

	set_skill("blade", 60);
	set_skill("parry", 70);
	set_skill("unarmed", 76);
	set_skill("dodge", 65);

        setup();
	carry_object(__DIR__"wp/steelblade2")->wield();
	carry_object(__DIR__"eq/sandal")->wear();
	carry_object(__DIR__"eq/necklace")->wear();
}

void init()
{
	::init();
	remove_call_out("snort");
	call_out("snort", 1);
}

void snort()
{
	command("hmm");
}

void die()
{
	object ob, counter;

	if( !ob = query_temp("last_damage_from") )
		ob = this_player(1);
	if( !ob )
	{
		::die();
		return;
	}

	counter = find_object(__DIR__"counter.c");

	counter->query_bandits(ob);

	::die();
        //destruct(this_object());
        return;
}