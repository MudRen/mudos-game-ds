#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIC"�ŤѴ��ջ�"NOR,({"ttt"}));
	set("long","�o�O�@�Ӥ��Ŵ��ջ��C\n");
	set_weight(1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit","��");
		set("value",9999);
	}
	setup();
}

void init()
{
	add_action("do_ttt","ttt");
}

int do_ttt()
{
	object me;
	object env;
	mixed *local;
	int aaa,bbb,ccc;
	mixed www;
	string weather, wbuffer;
	int wsize;

	aaa = 1111;
	bbb = 2222;
	ccc = 3333;
	www = ( { aaa, bbb, ccc } );

	me = this_player();
	env = environment(me);
	if(!env) return notify_fail("�A�Ҧb���Ŷ��ᦱ�ܧΤF�C\n");

	local = localtime(time()*60);
	tell_object(me,"�C���ɶ�(��): "+CHINESE_D->chinese_date(time()*60)+"\n");
	tell_object(me,"�C���ɶ�(��): "+local[5]+"�~"+local[4]+"��"+local[3]+"��"
			+local[2]+"��"+local[1]+"��"+local[0]+"��\n");
	local = localtime(time());
	tell_object(me,"�{��ɶ�(��): "+CHINESE_D->chinese_date(time())+"\n");
	tell_object(me,"�{��ɶ�(��): "+local[5]+"�~"+local[4]+"��"+local[3]+"��"
			+local[2]+"��"+local[1]+"��"+local[0]+"��\n");

	message("world:world1:outdoor:vision","���մ���\n",users());

	wsize = sizeof(wbuffer);
	wbuffer = "smile1|smile2|smile3|smile4|";

	while(1)
	{
		if( sscanf(wbuffer,"%s|%s", weather, wbuffer)==2 )
		tell_object(me,weather+"  "+wbuffer+"\n");
		else break;
	}

	tell_object(me,www[0]+" "+www[1]+" "+www[2]+"\n");
	return 1;
}