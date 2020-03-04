#include <ansi.h>

inherit NPC;
void do_ship(string arg,int flag);

void create()
{
	set_name( "�K������" , ({ "driver" }) );
	set("long",@long
�@���K���������A�t�d�r�p�K����p�C
long
);

	set("age", 50);
	set("level", 5);
	set("str", 2);
	set("int", 2);
	set("con", 2);
	set("dex", 2);
	setup();
	call_out("do_train",60,"train_station",0);
}

int accept_object(object who,object ob)
{
	
	if(ob->query("id")=="coin" && !this_object()->query_temp("do_train") )
	{
	if (ob->query_amount() >= 50)
		{
		command("smile");
		command("say �A�n�A�ЧA�{�b�i�J���[(enter train)�A�ܧִN�|�}�X�C");
		who->receive_money(- ob->query_amount() );
		who->set_temp("do_train",1);	
		}
		else
		{
		command("say �A�n�����ܴN���ڤ@�ǿ��a�C");
		}
	return 1;
	}
	return 0;
}
void do_train(string arg,int flag)
{
	object ob;
	ob=this_object();
if(flag==0)
{
	command("say �A�̧��n�A�{�b�}���F�C");
	ob->set_temp("do_train",arg);
	ob->move(__DIR__"train");	
	command("say �A�̧��n�A�{�b�}���F�C");
	tell_room(environment(ob),"�������U�@�ӫ��s�A�K���Y�ɶ}�ʡC\n");
	environment(ob)->set("exits",([]) );
	call_out("do_train",20,arg,1);
}
else
{
	message_vision("�A�P�쨮�t�}�l�ܺC�A�ݨӧ֨�F�F�C\n",ob);
	command("say ��F�F�A�j�a�֤U���a�C");
	environment(ob)->set("exits",(["out":__DIR__+arg]) );
	ob->move(__DIR__+arg);
	if(arg=="train_station1") arg="train_station";
	else arg="train_station1";
	call_out("do_train",60,arg,0);

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
	
	if(!arg || arg != "train") return 0;
	if(!me->query_temp("do_train") ) return 0;
	me->move(__DIR__"train");
	me->delete_temp("do_train");
	tell_room(environment(me),"$N���W�F���[�C\n",me);
	return 1;
}