#include <ansi.h>
inherit NPC;

string drink();
string eat();

void create()
{
	set_name("�j�s���o", ({ "bandit","golden dragon" }) );
	set("long","�@�Ӫ��s�몺�j�s���o�A�L�y�W���G���𭫭����ˤl�C\n");

	set("level",34+random(2));
        set("age",30+random(3));
        set("title",HIY"��"HIR"�s"HIM"��"NOR);
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
	set("attitude", "aggressive"); //�D�ʧ���,�ͩʦn������ NPC�C

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