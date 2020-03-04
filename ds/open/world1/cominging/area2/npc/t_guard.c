#include <ansi.h>
inherit NPC;

string drink();
string eat();

void create()
{
	set_name("�u�ö�çL", ({ "tower janitor","janitor" }) );
	set("long",
		"�@�Ӧb�u�ö𤧤����u�B�F�����X�f���çL�A�L��W���ۤ@����u�A\n"
		"���G���ǨI�����ˤl�A���W��ۤ@�I���Z�ҡC\n");
	set("level",24+random(2));
        set("age",30+random(3));

	set("combat_exp", 29000);
	set("chat_chance", 10);
        set("chat_msg", ({
  (: command,"idle" :),
  (: drink :),
  (: eat :),
  (: command,"yawn" :),
  (: command,"zzz" :),
  (: command,"say �u�֪����" :),
  (: drink :),
  (: eat :),
  (: drink :),
  (: eat :),
}));
	set("chat_chance_combat", 14);
	set("chat_msg_combat", ({
  (: command,"angry" :),
  (: command,"say �O���Z�ڥ𮧡I" :),
  (: command,"hmm" :),
}));
	set_skill("fork", 60);
	set_skill("parry", 70);
	set_skill("unarmed", 76);
	set_skill("dodge", 65);

        setup();
	carry_object(__DIR__"wp/halbert")->wield();
	carry_object(__DIR__"eq/tg_boots")->wear();
	carry_object(__DIR__"eq/tg_armor")->wear();
}

void init()
{

	object ob;
	if( interactive(ob = this_player()) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	::init();
}

void greeting(object me)
{
	string gender;
	if( me->query("gender") == "�k��" )
		gender = "�p�l";
	else gender = "�p�f";
	if( random(100) < 10 )
	{
		message_vision("$N���G�ݨ�F$n�����N�N���i�ӤF�o�Ӧa��C\n",this_object(),me);
		message_vision("$N���ӫȮ𪺹�$n���G"+gender+"�A�o�i���O���A�i�Ӫ����a��I\n",this_object(),me);
	}
	else tell_object(me,"�A���G�����N�N���i�ӨS����"+this_object()->name(1)+"�ݨ�I\n");
}

string drink()
{
	string msg;
	if( environment(this_object())->query("level") == "tower_1" )
	{
		msg = this_object()->name(1)+"���_��W�������}�l�B�P�B�P�}�l�ܤF�_��...\n";
		message_vision("$N���_��W�������}�l�B�P�B�P�}�l�ܤF�_��...\n",this_object());
		this_object()->receive_heal("ap",30);
	}
	return msg;
}

string eat()
{
	string msg;
	if( environment(this_object())->query("level") == "tower_1" )
	{
		command("unwield halbert");
		message_vision("$N��U�⤤�F��A���_���W��³�A�Y�F�_��...\n",this_object());
		msg = this_object()->name(1)+"��U�⤤�F��A���_���W��³�A�Y�F�_��...\n";
		this_object()->receive_heal("ap",40);
		this_object()->receive_heal("hp",40);
		call_out("wield_h",4);
	}
	return msg;
}

void wield_h()
{
	command("wield halbert");
	return;
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