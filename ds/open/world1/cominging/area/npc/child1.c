#include <ansi.h>
inherit NPC;
void create()
{
	set_name("�p�ĸs",({ "children" }));
	set("long","�@�ί��o�n�}�ߪ��p�ġA�L�̦n���b�Q�פ���F��C\n");
	set("level", 1);
	set("age",20);
	set("chat_chance", 8);
	set("chat_msg", ({
  (: random_move :),
}));
	setup();
	add_money("coin",150);
	carry_object(__DIR__"wp/woodensword")->wield();
	carry_object(__DIR__"eq/sandal")->wear();
}

int talk_action(object me)
{
	object ob;
	ob = this_object();
	if( !query_temp("musci") )
		message_vision(ob->name()+"��$N���G"+RANK_D->query_respect(me)+"�����ڨ��ݨ����������a�a !\n",me);
	return 1;
}

int accept_object(object who, object ob)
{
	object tob, a;
	int exp;
	tob = this_object();
	if( ob->query("id")!="musci" || query_temp("toy") ) return 0;

	command("thank "+who->query("id"));
	command("bow");
	exp=25 - who->query("level");
	if(exp<1) exp=200+random(50);
	else exp=250+exp*20+random(exp*10);
	who->add("exp", exp);
	set_temp("toy",1);
	tell_object(who,HIR"�A�o�� "+exp+" �I�g��ȡC\n"NOR);
	set("long","�@�Ϋܶ}�ߪ��p��, ���J�Ӫ��[���W���F��.\n");

	return 1;
}

void reset()
{
	delete_temp("toy");
	set("long","�@�ί��o�n�}�ߪ��p�ġA�L�̦n���b�Q�פ���F��C\n");
	return;
}