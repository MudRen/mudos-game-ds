#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIC"藍天測試儀"NOR,({"ttt"}));
	set("long","這是一個水藍測試儀。\n");
	set_weight(1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit","個");
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
	if(!env) return notify_fail("你所在的空間扭曲變形了。\n");

	local = localtime(time()*60);
	tell_object(me,"遊戲時間(中): "+CHINESE_D->chinese_date(time()*60)+"\n");
	tell_object(me,"遊戲時間(西): "+local[5]+"年"+local[4]+"月"+local[3]+"日"
			+local[2]+"時"+local[1]+"分"+local[0]+"秒\n");
	local = localtime(time());
	tell_object(me,"現實時間(中): "+CHINESE_D->chinese_date(time())+"\n");
	tell_object(me,"現實時間(西): "+local[5]+"年"+local[4]+"月"+local[3]+"日"
			+local[2]+"時"+local[1]+"分"+local[0]+"秒\n");

	message("world:world1:outdoor:vision","測試測試\n",users());

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