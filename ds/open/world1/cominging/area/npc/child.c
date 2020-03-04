#include <ansi.h>
inherit NPC;
void create()
{
	set_name("�p��",({ "child" }));
	set("long","�@�ӯ��o�n�}�ߪ��p�ġA�L���G���Ƿдo�C\n");
	set("level", 1);
    set("age",5);
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
	if( !query_temp("toy") )
		message_vision(ob->name()+"��$N���G"+RANK_D->query_respect(me)+"�����ڧ��ڪ�����(toy)�C\n",me);
	return 1;
}

int accept_object(object who, object ob)
{
	object tob, a;
	tob = this_object();
	if( ob->query("id")!="toy" || query_temp("toy") ) return 0;

	command("thank "+who->query("id"));
	command("say ���§A�F�A"+RANK_D->query_respect(who)+"�I\n");
	who->add("exp", 700);
	set_temp("toy",1);
	tell_object(who,HIR"�A�o�� 700 �I�g��ȡC\n"NOR);
	call_out("delay",600,this_object());
	set("long","�@�ӯ����ܶ}�ߪ��p��, �����ۥL��W������.\n");

	return 1;
}

void delay(object tob)
{
	delete_temp("toy");
	set("long","�@�ӯ��o�n�}�ߪ��p�ġA�L���G���Ƿдo�C\n");
	return;
}
