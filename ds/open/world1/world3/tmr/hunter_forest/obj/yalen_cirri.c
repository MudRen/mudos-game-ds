inherit ITEM;

void create()
{
	set_name("�ȳs�ý�",({"yalen cirri","cirri"}) );
	set_weight(500);
	set("long","�o�O�@���ȳs���ý��A�h�b�Q�ΨӮM�ɰʪ�(catch)�C\n");
	if(clonep() )
		set_default_object(__FILE__);
	else {
	set("value",1);
	set("material","plant");
	set("volume",1);
	}
	setup();
}

void init()
{
	add_action("do_catch","catch");
}

int do_catch(string arg)
{
	object me,ob;
	me=this_player();
	if(!arg || arg!="���W" )
		return notify_fail("�ȳs�ý��u��ΨӸɮ����W�C\n");
	if(!objectp(ob=present("gu name",environment(me)) ) )
		return notify_fail("�o�̨S�����W�o���ʪ��C\n");
	if(query("catch_ok") )
		return notify_fail("�A�w�g���착�W�F�C\n");
	message_vision("$N�Q�Ψ��W���@���ý��A���Q���착�W�C\n",me);
	set("catch_ok",1);
	destruct(ob);
	return 1;
}