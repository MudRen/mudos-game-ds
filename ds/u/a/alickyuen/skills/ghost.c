#include <ansi.h>
inherit NPC;

void create()
{
	set_name("�t���",({"ghost"}) );
	set("long",
"�@�Ӵ�������A�����w���F�h�֦~�A�ܤ��D����L�������C \n"
);
	set("gender","�k��");
        set("age",30);
	set("level",1);
	set("evil",40);		
	set("race","�H��");
        set("chat_chance",1);
	set("chat_msg",({
		this_object()->query("name")+"�ƤF�L�h�A�S�ƤF�L��....\n",
		this_object()->query("name")+"���ĤF�@�f��@�����@\n",
	})	);

    set_temp("float",1); // �����ӯB�b�Ť��a, By Acme
	setup();
}

void init()
{
	object owner;
	owner=this_object()->query("creater");
	if(!this_object()->query("no_creater"))
	{
		if(!objectp(owner) || !owner->is_character())
		{
			message_vision("$N�˦b�a�W, �����Ƭ��@�y�ä��F..\n",this_object());
			destruct(this_object());
			return;
		}
	}
	::init();
}


