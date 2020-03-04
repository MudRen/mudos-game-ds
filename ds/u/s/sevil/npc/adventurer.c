#include <ansi.h>
inherit NPC;
void create()
{
	set_name("�_�I��",({ "adventurer","���H" }));
	set("long","�@�ӱq�~�a�ӨӪ��_�I�a�C\n");
	set("level", 10);
	set("age",20);
	set("chat_chance", 8);
	set("chat_msg", ({
  (: random_move :),
}) );
	set_skill("sword",10);
	set_skill("dodge",25);
	set_skill("combat",5);
	setup();
	add_money("coin",150);
	carry_object(__DIR__"wp/longsword")->wield();
	carry_object(__DIR__"eq/swatheshoe")->wear();
}

void init()
{
	call_out("delay",2,this_player());
}

int accept_object(object who, object ob)
{
	if( ob->query("id")!="musci" && ob->query("id")!="golden sand" ) return 0;
	if( !query_temp("uselo"))
	{
		command("ah");
		command("say ��ӬO�o�ӪF��r....");
		command("thank "+who->query("id"));
		who->add("exp", 400);
		set_temp("uselo",1);
		tell_object(who,HIR"�A�o�� 400 �I�g��ȡC\n"NOR);
		call_out("a",600,this_object());
	}
	else command("bow");
	return 1;
}

void delay(object me)
{
	tell_object(me,this_object()->name()+"��A���G�аݧA���D�����̭�������F��H\n");
	return;
}

void a(object tob)
{
	delete_temp("uselo");
	return;
}