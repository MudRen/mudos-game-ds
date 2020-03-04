#include <ansi.h>
inherit NPC;

string drink();
string eat();

void create()
{
	set_name("��^�h�L", ({ "fort guard","guard" }) );
	set("long",
		"�u�ö𳻼Ӫ��h�L�A�ݹ�B�F���|�P���H�A���ۤ@�I�I����\n"
		"�K�Y���A�ҥH�ݤ��M���L���e���A�L�����ۻ���A���ۮ���\n"
		"���A�@�I�믫�ݼݪ��ˤl�C\n");

	set("level",34+random(2));
        set("age",30+random(3));

	set("chat_chance_combat",120);
	set("chat_msg_combat",({
  (: command("shoot") :),
}));

	set("combat_exp", 31000);
	set_skill("sword", 70);
	set_skill("parry", 70);
	set_skill("unarmed", 76);
	set_skill("dodge", 65);

        setup();
	carry_object(__DIR__"wp/bow")->wield();
	carry_object(__DIR__"eq/long_boots")->wear();
	carry_object(__DIR__"eq/chain_mail")->wear();
	carry_object(__DIR__"obj/arrow2");
	carry_object(__DIR__"obj/arrow2");
	carry_object(__DIR__"obj/arrow2");
	carry_object(__DIR__"obj/arrow2");
	carry_object(__DIR__"obj/arrow2");
	carry_object(__DIR__"obj/arrow2");
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