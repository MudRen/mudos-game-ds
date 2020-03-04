#include <ansi.h>
inherit NPC;

string drink();
string eat();

void create()
{
	set_name("���޽çL", ({ "partol sentry","sentry" }));
	set("long",
		"���ަb�u�ö𤤦U�a�貧�B���çL�A�L�ݰ_�ӴN�O���������A�����y�U�A\n"
		"�@�I�����G�H���ˤl�A���W��o�@�I�I�����Z�ҡC\n");
	set("level",28+random(2));
        set("age",33+random(3));

	set("combat_exp", 30000-random(1000));
	set("chat_chance", 10);
        set("chat_msg", ({
  (: command,"up" :),
  (: command,"down" :),
  (: command,"stare" :),
  name(1)+"�[��ۥ|�P������a�褣��l�C\n",
}));
	set("chat_chance_combat", 14);
	set("chat_msg_combat", ({
  (: command,"angry" :),
}));
	set_skill("blade", 70);
	set_skill("parry", 66);
	set_skill("unarmed", 76);
	set_skill("dodge", 85);

        setup();
	carry_object(__DIR__"wp/b_blade.c")->wield();
	carry_object(__DIR__"eq/ps_boots")->wear();
	carry_object(__DIR__"eq/chain_mail")->wear();
	carry_object(__DIR__"eq/ps_waist")->wear();
}

void die()
{
	object ob, counter, room;
	if( !ob = query_temp("last_damage_from") )
		ob = this_player(1);
	if( !ob )
	{
		::die();
		return;
	}

	counter = find_object(__DIR__"counter.c");
	if( objectp(counter) )
		counter->query_bandit_war(1);
	else tell_object(ob,"���~: �гq�� Cominging �j�j, ����.\n");

	::die();
        //destruct(this_object());
        return;
}