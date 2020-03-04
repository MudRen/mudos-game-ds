#include <path.h>
inherit NPC;

void use_poison();

void create()
{
	set_name("�Ю{", ({"believer"}) );
	set("race", "�H��");
	set("gender", "�k��");
	set("level",35);
	set("age", 19);
set("evil",10+random(5));
	set("long", "�L�O�@��Ŭr�Ъ��Ю{\n");

	set("combat_exp", 80000);

	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: use_poison :)
	}) );

	set("chat_chance",50);
//	set("chat_msg",({ (:random_move:) }));
	set("chat_msg",({
	   (:command,"east":),
	   (:command,"west":),
	   (:command,"south":),
	   (:command,"north":),
	   (:command,"up":),
	   (:command,"down":)
           }));
           
	setup();

	add_money("coin",50);
	carry_object(SHENGSAN+"voodoo/eq/dagger")->wield();
}

void use_poison()
{
	object *enemy, ob;
	string msg;
	int damage;

	enemy = query_enemy();
	if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];

	if( ob->query_condition("poison") ) return;

	if( random(query("combat_exp")) > (int)ob->query("combat_exp") )
	{
	  ob->apply_condition("poison", 20);
	  message_vision("�զ⪺�����q$N�⤤����ŧ�V$n�C\n",this_object(), ob);
	  tell_object(ob, "�Aı�o�y�W���G�g�W�F����F��A����@�N�o����]�S���C\n");
	}
}
