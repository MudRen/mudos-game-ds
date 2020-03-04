#include <ansi.h>
inherit NPC;

void create()
{
	set_name("�t���",({"ghost"}) );
	set("long",
"�@�Ӵ�������A�����w���F�h�֦~�A�ܤ��D����L�������C \n"
);
	set("gender","�k��");
	set("age",100);
	set("level",1);
	set("evil",40);		
	set("race","�H��");
	set("chat_chance",10);
	set("chat_msg",({
		"�t����ƤF�L�h�A�S�ƤF�L��....\n",
	})	);

	setup();
}

void die()
{
	object me;
	me=(object)this_object()->query_temp("host");
	me->add_temp("call_ghost",-1);

	command("say �ڦ��F������");
	tell_room(environment(this_object()),this_object()->query("name")+"�G�I�@�n�A�N���Ϯ������F�C\n");
	destruct(this_object() );
	return;
}
void init()
{
	add_action("do_hest","hest");

}

int do_hest(string arg)
{
	string dest, cmd;
	object ob,me;

	me=this_player();
	ob=this_object();

	
	if(ob->query_temp("host")!=me->query("id") ) return 0;
	if( !arg || sscanf(arg, "%s to %s", dest, cmd) != 2 )
		return notify_fail("���O�榡�Rhest <�Y����> to <���O>\n");

	if( !(ob = present(dest, environment(me))) )
		return notify_fail("�o�̨S�� " + dest + "�C\n");
	if(ob->is_busy() ) return notify_fail(ob->query("name")+"�����ۡA�S����ť�A���X�ϡC\n");

	command(cmd);
	return 1;
}

