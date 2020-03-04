#include <ansi.h>

inherit NPC;
void do_ship(string arg,int flag);

void create()
{
	set_name( "�Ѳ��" , ({ "shipman" }) );
	set("long",@long
�o�O�@��~�Ѫ����C
long
);

	set("age", 60);
	set("level", 5);
	
	set("str", 2);
	set("int", 2);
	set("con", 2);
	set("dex", 2);

	setup();
	call_out("do_ship",60,"west",0);
}

int accept_object(object who,object ob)
{
	
	if(ob->query("id")=="coin" && !this_object()->query_temp("do_ship") )
	{
	if (ob->query_amount() >= 50)
		{
		command("smile");
		command("say �o��ȭ��A�ӨӨӡA�ФW��y��(enter ship)�A�Y��}��C");
		who->receive_money(- ob->query_amount() );
		who->set_temp("do_ship",1);	
		}
		else
		{
		command("say ��e�����O���Q����A����L�ۡC");
		}
	return 1;
	}
	return 0;
}

void do_ship(string arg,int flag)
{
	object ob;
	ob=this_object();
if(flag==0)
{
	command("say �U��ȭ��֧��F�A�n�}��F�C");
	ob->set_temp("do_ship",arg);
	ob->move(__DIR__"ship");	
	command("say �U��ȭ��֧��F�A�n�}��F�C");
	tell_room(environment(ob),"�Ѳ���_�F�@�����ˬ񩹪e�����h�A���w�w�a���ʤF�C\n");
	environment(ob)->set("exits",([]) );
	call_out("do_ship",20,arg,1);
}
else
{
	message_vision("�A���Mı�o���@�}�}�I���A�Q���w�a���F�C\n",ob);
	command("say �U��ȭ��A�w�a���F�A�Ц��B�n�H��������A�ǳƤU��F�C");
	environment(ob)->set("exits",(["out":__DIR__+arg]) );
	ob->move(__DIR__+arg);
	if(arg=="east") arg="west";
	else arg="east";
	call_out("do_ship",60,arg,0);

}
	return;
}

void init()
{
	add_action("do_enter","enter");
}

int do_enter(string arg)
{
	object me;
	me=this_player();
	
	if(!arg || arg != "ship") return 0;
	if(!me->query_temp("do_ship") ) return 0;
	me->move(__DIR__"ship");
	me->delete_temp("do_ship");
	tell_room(environment(me),"$N���W�F���C\n",me);
	return 1;
}


